
include_directories(src)
include_directories(/usr/local/include)
include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

add_executable (main_cpp src/list.cpp src/entity.cpp src/main.cpp)
add_executable (test_cpp src/list.cpp src/entity.cpp test/test.cpp)
target_link_libraries(test_cpp gtest    gtest_main)
