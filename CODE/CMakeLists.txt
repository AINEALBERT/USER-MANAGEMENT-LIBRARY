cmake_minimum_required(VERSION 3.10)

project(LIBRARY)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Pybind11
set(pybind11_DIR "C:/Users/ALBERT/AppData/Local/Programs/Python/Python312/Lib/site-packages/pybind11/share/cmake/pybind11")
find_package(pybind11 REQUIRED)

#OpenCV package
set(OpenCV_DIR "C:/Users/ALBERT/Downloads/opencv/build/x64/vc16/lib")
find_package(OpenCV REQUIRED)
# Include directories
include_directories(include)

# Source files
add_library(LIBRARY user_manager.h user_manager.cpp user_manager_pybind.cpp)

# Bcrypt library
target_link_libraries(LIBRARY bcrypt)
target_link_libraries(LIBRARY ${OpenCV_LIBS})
target_link_libraries(user_manager_pybind PRIVATE LIBRARY ${OpenCV_LIBS} pybind11::module)
