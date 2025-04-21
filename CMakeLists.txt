cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_COMPILER "clang" CACHE PATH "")
set(CMAKE_CXX_COMPILER "clang++" CACHE PATH "")
set(CMAKE_GENERATOR "Ninja")

set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)
set(VCPKG_ROOT "${EXTERNAL_DIR}/vcpkg")
# set toolchain file
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(
	playground
	VERSION 0.1.0
	LANGUAGES C CXX
)

set(LIB_NAME TestLib)

# nvim LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# export symbols for dll
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(
	${LIB_NAME}
		main.cpp
)
enable_testing()

find_package(GTest CONFIG REQUIRED)

target_link_libraries(${LIB_NAME} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main CURL::libcurl)

add_test(PlaygroundTests ${LIB_NAME})

#-----------------------------------------------------------
# 
#-----------------------------------------------------------

