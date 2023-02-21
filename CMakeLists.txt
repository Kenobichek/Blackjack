# CMakeList.txt : CMake project for Blackjack, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16)

project ("Blackjack")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.4.1/msvc2019_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)

qt_standard_project_setup()

file(GLOB libs "${PROJECT_SOURCE_DIR}/Lib/*")
file(COPY ${libs} DESTINATION "${CMAKE_BINARY_DIR}")
file(CREATE_LINK "${PROJECT_SOURCE_DIR}/Content" "${CMAKE_BINARY_DIR}/Content" SYMBOLIC)

file(GLOB source_files "Source/*.h" "Source/*.cpp" "Source/*.ui")

include_directories("Source")

add_executable (Blackjack ${source_files})

target_link_libraries(Blackjack PRIVATE Qt6::Widgets Qt6::Multimedia)

set_target_properties(Blackjack PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
