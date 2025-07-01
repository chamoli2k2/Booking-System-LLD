cmake_minimum_required(VERSION 3.10)
project(MovieBookingSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/CoreClasses
    ${PROJECT_SOURCE_DIR}/Controllers
    ${PROJECT_SOURCE_DIR}/Services
    ${PROJECT_SOURCE_DIR}/Interfaces
    ${PROJECT_SOURCE_DIR}/ConcreteLockProviders
    ${PROJECT_SOURCE_DIR}/ConcretePaymentStrategies
    ${PROJECT_SOURCE_DIR}/CommonEnum
)

# Source files
file(GLOB_RECURSE SOURCES
    "${PROJECT_SOURCE_DIR}/main.cpp"
    "${PROJECT_SOURCE_DIR}/CoreClasses/*.cpp"
    "${PROJECT_SOURCE_DIR}/Controllers/*.cpp"
    "${PROJECT_SOURCE_DIR}/Services/*.cpp"
    "${PROJECT_SOURCE_DIR}/Interfaces/*.cpp"
    "${PROJECT_SOURCE_DIR}/ConcreteLockProviders/*.cpp"
    "${PROJECT_SOURCE_DIR}/ConcretePaymentStrategies/*.cpp"
)

add_executable(MovieBookingSystem ${SOURCES})
