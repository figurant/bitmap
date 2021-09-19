add_executable(run_actual_tests bitmap_test.cpp  ../../source/BitMap.cpp)

target_link_libraries(run_actual_tests gtest gtest_main)
