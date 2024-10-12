#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    int sensor_id0 = 0; // 0 для CAM0 и 1 для CAM1
    int sensor_id1 = 1; // 0 для CAM0 и 1 для CAM1
    int framerate = 60; // Установите нужный фреймрейт

    std::string pipeline0 = "nvarguscamerasrc sensor-id=" + std::to_string(sensor_id0) +
                            " ! video/x-raw(memory:NVMM),width=1920,height=1080,framerate=" + std::to_string(framerate) + "/1" +
                            " ! nvvidconv ! video/x-raw,format=BGRx ! videoconvert ! appsink";

    std::string pipeline1 = "nvarguscamerasrc sensor-id=" + std::to_string(sensor_id1) +
                            " ! video/x-raw(memory:NVMM),width=1920,height=1080,framerate=" + std::to_string(framerate) + "/1" +
                            " ! nvvidconv ! video/x-raw,format=BGRx ! videoconvert ! appsink";

    std::cout << "Инициализация захвата видео..." << std::endl;
    cv::VideoCapture cap0(pipeline0, cv::CAP_GSTREAMER);
    cv::VideoCapture cap1(pipeline1, cv::CAP_GSTREAMER);

    if (!cap0.isOpened())
    {
        std::cerr << "Ошибка: не удалось открыть видеопоток с камеры 0!" << std::endl;
    }
    else
    {
        std::cout << "Видеопоток с камеры 0 открыт успешно!" << std::endl;
    }

    if (!cap1.isOpened())
    {
        std::cerr << "Ошибка: не удалось открыть видеопоток с камеры 1!" << std::endl;
    }
    else
    {
        std::cout << "Видеопоток с камеры 1 открыт успешно!" << std::endl;
    }

    // Создание окон
    std::cout << "Создание окон..." << std::endl;
    cv::namedWindow("Камера0", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Камера1", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Параметры", cv::WINDOW_AUTOSIZE);

    cv::Mat frame0;
    cv::Mat frame1;

    while (true)
    {
        if (cap0.isOpened())
        {
            cap0 >> frame0;
            if (frame0.empty())
            {
                std::cerr << "Ошибка: пустой кадр!" << std::endl;
                frame0 = cv::Mat::zeros(480, 640, CV_8UC3); // Создание пустого изображения
            }
        }
        else
        {
            // Используем пустое изображение, если видеопоток не открыт
            frame0 = cv::Mat::zeros(480, 640, CV_8UC3); // Черное изображение
        }

        if (cap1.isOpened())
        {
            cap1 >> frame1;
            if (frame1.empty())
            {
                std::cerr << "Ошибка: пустой кадр!" << std::endl;
                frame1 = cv::Mat::zeros(480, 640, CV_8UC3); // Создание пустого изображения
            }
        }
        else
        {
            // Используем пустое изображение, если видеопоток не открыт
            frame1 = cv::Mat::zeros(480, 640, CV_8UC3); // Черное изображение
        }

        // Наложение текста на видео
        cv::putText(frame0, "Тестовый источник видео0", cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);
        cv::putText(frame1, "Тестовый источник видео1", cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);
        // Вывод видео

        cv::imshow("Камера0", frame0);
        cv::imshow("Камера1", frame1);

        // Параметры
        cv::Mat paramWindow(200, 400, CV_8UC3, cv::Scalar(255, 255, 255));
        cv::putText(paramWindow, "Параметры камеры", cv::Point(10, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 0), 2);
        cv::imshow("Параметры", paramWindow);

        // Ожидание нажатия клавиши
        if (cv::waitKey(30) >= 0)
            break;
    }

    // Освобождение ресурсов
    if (cap0.isOpened())
    {
        cap0.release();
    }
     if (cap1.isOpened())
    {
        cap1.release();
    }
    cv::destroyAllWindows();
    return 0;
}
