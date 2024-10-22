cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

set(CMAKE_CXX_STANDARD 14)

# Указываем путь к OpenCV
set(OpenCV_DIR /usr/lib/aarch64-linux-gnu)  # Указываем найденный путь

find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Включаем директории с заголовочными файлами GTK3 и OpenCV
include_directories(${GTK3_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS} ${OpenCV_LIBRARY_DIRS})

# Определяем флаги компиляции для GTK3
add_definitions(${GTK3_CFLAGS_OTHER})

# Добавляем исполняемый файл
add_executable(${PROJECT_NAME} main.cpp)

# Линкуем библиотеки GTK3 и OpenCV
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} ${OpenCV_LIBS})









# cmake_minimum_required(VERSION 3.10)
# project(YourProjectName)

# set(CMAKE_CXX_STANDARD 14)

# # Добавляем путь к OpenCV
# #set(OpenCV_DIR /usr/local/share/OpenCV)  # Укажите правильный путь, если он отличается
# set(OpenCV_DIR /usr/lib/aarch64-linux-gnu)  # Указываем найденный путь
# find_package(OpenCV REQUIRED)
# find_package(PkgConfig REQUIRED)
# pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# include_directories(${GTK3_INCLUDE_DIRS})
# link_directories(${GTK3_LIBRARY_DIRS})

# add_definitions(${GTK3_CFLAGS_OTHER})

# add_executable(${PROJECT_NAME} main.cpp)
# target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES})
# target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})  # Исправил имя проекта на переменную

#add_executable(welcome main.cpp
#        lessons/buffered_reader.cpp
#        lessons/comment.cpp
#        lessons/context_actions.cpp
#        lessons/duplicate.cpp
#        lessons/file_structure.cpp
#        lessons/find_in_files.cpp
#        lessons/multiple_selection.cpp
#        lessons/quadratic_equations_solver.cpp
#        lessons/selection.cpp
#        lessons/unwrap.cpp
#        BasicEditing.cpp
#        CodeAssistance.cpp
#        Refactorings.cpp
#        Navigation.cpp
#
#)
#