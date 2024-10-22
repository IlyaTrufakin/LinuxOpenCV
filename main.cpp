#include <opencv2/opencv.hpp>
#include <X11/Xlib.h>
#include <iostream>
#include <memory>
#include <stdexcept>

// Функция для инициализации камеры
std::unique_ptr<cv::VideoCapture> initializeCamera(int sensor_id, int width, int height, int framerate)
{
    std::string pipeline = "nvarguscamerasrc sensor-id=" + std::to_string(sensor_id) +
                           " ! video/x-raw(memory:NVMM),width=" + std::to_string(width) +
                           ",height=" + std::to_string(height) + ",framerate=" + std::to_string(framerate) + "/1" +
                           " ! nvvidconv ! video/x-raw,format=BGRx ! videoconvert ! video/x-raw,format=BGR ! appsink";

    // Попытка открыть видеопоток
    auto cap = std::make_unique<cv::VideoCapture>(pipeline, cv::CAP_GSTREAMER);
    if (!cap->isOpened())
    {
        throw std::runtime_error("Ошибка: не удалось открыть видеопоток с камеры " + std::to_string(sensor_id));
    }
    return cap;
}

int main()
{
    Display *disp = XOpenDisplay(NULL);
    Screen *scrn = DefaultScreenOfDisplay(disp);
    int screen_width = scrn->width;
    int screen_height = scrn->height;

    int sensor_id0 = 0; // 0 для CAM0 и 1 для CAM1
    int sensor_id1 = 1; // 0 для CAM0 и 1 для CAM1
    int framerate = 60; // Установите нужный фреймрейт

    std::cout << "Разрешение экрана: " << screen_width << "x" << screen_height << std::endl;

    // Вычисляем ширину каждого окна
    int window_width = screen_width / 3;
    int window_height = screen_height;

    // Создание и настройка окон
    cv::namedWindow("Камера0", cv::WINDOW_NORMAL);
    cv::namedWindow("Камера1", cv::WINDOW_NORMAL);
    cv::namedWindow("Параметры", cv::WINDOW_NORMAL);

    // Размещение окон
    cv::resizeWindow("Камера0", window_width, window_height);
    cv::resizeWindow("Камера1", window_width, window_height);
    cv::resizeWindow("Параметры", window_width, window_height);

    // Перемещение окон
    cv::moveWindow("Камера0", 0, 0);                  // Окно 0 на левую часть экрана
    cv::moveWindow("Камера1", window_width, 0);       // Окно 1 в центр
    cv::moveWindow("Параметры", window_width * 2, 0); // Окно 2 на правую часть экрана

    try
    {
        // Инициализация камер с использованием unique_ptr для автоматического освобождения ресурсов
        auto cap0 = initializeCamera(0, 1920, 1080, 30);
        auto cap1 = initializeCamera(1, 1920, 1080, 30);

        cv::Mat frame0, frame1;

        while (true)
        {
            // Захват кадров с камер
            *cap0 >> frame0;
            *cap1 >> frame1;

            // Проверка на пустые кадры
            if (frame0.empty() || frame1.empty())
            {
                throw std::runtime_error("Ошибка: Пустой кадр!");
            }

            // Отображение кадров
            cv::imshow("Камера 0", frame0);
            cv::imshow("Камера 1", frame1);

            // Выход при нажатии любой клавиши
            if (cv::waitKey(30) >= 0)
                break;
        }

        // Автоматическое освобождение ресурсов при выходе из try-блока
    }
    catch (const std::exception &e)
    {
       std::cerr << e.what() << std::endl;
        // // Освобождение ресурсов
        // if (cap0.isOpened())
        // {
        //     cap0.release();
        // }
        // if (cap1.isOpened())
        // {
        //     cap1.release();
        // }
        // Освобождение ресурсов и завершение программы
    }

    cv::destroyAllWindows(); // Закрытие всех окон
    return 0;

}
