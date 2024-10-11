#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Параметры для GStreamer камеры
    std::string pipeline = "videotestsrc ! video/x-raw, width=640, height=480, framerate=30/1 ! videoconvert ! appsink";

    std::cout << "Инициализация захвата видео..." << std::endl;
    cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);

    if (!cap.isOpened()) {
        std::cerr << "Ошибка: не удалось открыть видеопоток!" << std::endl;
    } else {
        std::cout << "Видеопоток открыт успешно!" << std::endl;
    }

    // Создание окон
    std::cout << "Создание окон..." << std::endl;
    cv::namedWindow("Камера", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Параметры", cv::WINDOW_AUTOSIZE);

    cv::Mat frame;

    while (true) {
        if (cap.isOpened()) {
            cap >> frame;
            if (frame.empty()) {
                std::cerr << "Ошибка: пустой кадр!" << std::endl;
                frame = cv::Mat::zeros(480, 640, CV_8UC3); // Создание пустого изображения
            }
        } else {
            // Используем пустое изображение, если видеопоток не открыт
            frame = cv::Mat::zeros(480, 640, CV_8UC3); // Черное изображение
        }

        // Наложение текста на видео
        cv::putText(frame, "Тестовый источник видео", cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);

        // Вывод видео
        cv::imshow("Камера", frame);

        // Параметры
        cv::Mat paramWindow(200, 400, CV_8UC3, cv::Scalar(255, 255, 255));
        cv::putText(paramWindow, "Параметры камеры", cv::Point(10, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 0), 2);
        cv::imshow("Параметры", paramWindow);

        // Ожидание нажатия клавиши
        if (cv::waitKey(30) >= 0) break;
    }

    // Освобождение ресурсов
    if (cap.isOpened()) {
        cap.release();
    }
    cv::destroyAllWindows();
    return 0;
}
