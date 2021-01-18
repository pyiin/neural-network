#neural-network
cmake_minimum_required(VERSION 3.10)

project(neural-network)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(neural-network ${SOURCES})
