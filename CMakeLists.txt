cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME Laba) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(StackName Stack) #Переменная с именем приложения
set(StackLibName StackLib) #Переменная с именем библиотеки
set(ArithmeticName Arithmetic)
set(ArithmeticLibName ArithmeticLib)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ArithmeticLib) #Добавляем директорию "${CMAKE_CURRENT_SOURCE_DIR}/vectorLib" в дополняемые каталоги включаемых файлов
#${CMAKE_CURRENT_SOURCE_DIR} - стандартная переменная с адресом рабочей директории

add_subdirectory(Stack) #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(StackLib)
add_subdirectory(Arithmetic)
add_subdirectory(ArithmeticLib)
add_subdirectory(gtest)
add_subdirectory(test)