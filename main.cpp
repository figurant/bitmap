#include <iostream>
#include "source/BitMap.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    BitMap test_bitmap_1 = BitMap(1024);
    BitMap test_bitmap_2 = BitMap(1024);
    test_bitmap_1.reset();
    test_bitmap_1[10] = 1;
    test_bitmap_1[8] = 1;
    test_bitmap_2.reset();
    test_bitmap_2[10] = 1;
    test_bitmap_2[12] = 1;
    test_bitmap_1&=test_bitmap_2;
    std::cout << test_bitmap_1[8] << std::endl;
    std::cout << test_bitmap_1[10] << std::endl;
    std::cout << test_bitmap_1[12] << std::endl;
}

