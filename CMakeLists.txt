project(TEMA1)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -pedantic -Weffc++ -Werror -g)

add_executable(TEMA1 main.cpp Gadget.cpp Gadget.h Ecran.cpp Ecran.h SmartPhone.cpp SmartPhone.h SmartTV.cpp SmartTV.h rang.hpp SmartPhone_factory.cpp SmartPhone_factory.h SmartTV_factory.cpp SmartTV_factory.h)