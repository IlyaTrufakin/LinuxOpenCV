#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Параметры для GStreamer камеры (замените параметрами из вашего скрипта)
    std::string pipeline = "nvarguscamerasrc ! video/x-raw(memory:NVMM), width=1920, height=1080, framerate=60/1 ! nvvidconv ! videoconvert ! appsink";

    // Открытие потока с камеры через GStreamer
    cv::VideoCapture cap(pipeline, cv::CAP_GSTREAMER);

    if (!cap.isOpened()) {
        std::cerr << "Ошибка: не удалось открыть камеру!" << std::endl;
        return -1;
    }

    // Окна для вывода видео и параметров
    cv::namedWindow("Камера", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Параметры", cv::WINDOW_AUTOSIZE);

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "Ошибка: пустой кадр!" << std::endl;
            break;
        }

        // Наложение текста на видео
        cv::putText(frame, "FPS: 60", cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0), 2);

        // Вывод видео
        cv::imshow("Камера", frame);

        // Параметры (для примера пустое изображение)
        cv::Mat paramWindow(200, 400, CV_8UC3, cv::Scalar(255, 255, 255));
        cv::putText(paramWindow, "Параметры камеры", cv::Point(10, 50), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 0), 2);
        cv::imshow("Параметры", paramWindow);

        // Ожидание нажатия клавиши
        if (cv::waitKey(30) >= 0) break;
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
