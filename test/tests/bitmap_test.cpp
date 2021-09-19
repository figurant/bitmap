#include "gtest/gtest.h"
#include "../../source/BitMap.h"

namespace {
    class BitMapTestClass : public testing::Test {
    public:
        BitMap test_bitmap_1 = BitMap(20);
        BitMap test_bitmap_2 = BitMap(20);
    };
}

TEST_F(BitMapTestClass, Test_SetGetBit) {
    ASSERT_EQ(0, 0);
    ASSERT_EQ(test_bitmap_1[10], 0);
    test_bitmap_1[10] = 1;
    ASSERT_EQ(test_bitmap_1[10], 1);
    test_bitmap_1.reset();
    ASSERT_EQ(test_bitmap_1[10], 0);
}

TEST_F(BitMapTestClass, Test_MapAnd) {
    test_bitmap_1.reset();
    test_bitmap_1[10] = 1;
    test_bitmap_1[8] = 1;
    test_bitmap_2.reset();
    test_bitmap_2[10] = 1;
    test_bitmap_2[12] = 1;
    test_bitmap_1 &= test_bitmap_2;
    ASSERT_EQ(test_bitmap_1[8], 0);
    ASSERT_EQ(test_bitmap_1[10], 1);
    ASSERT_EQ(test_bitmap_1[12], 0);
}

TEST_F(BitMapTestClass, Test_MapOr) {
    test_bitmap_1.reset();
    test_bitmap_1[10] = 1;
    test_bitmap_1[8] = 1;
    test_bitmap_2.reset();
    test_bitmap_2[10] = 1;
    test_bitmap_2[12] = 1;
    test_bitmap_1 |= test_bitmap_2;
    ASSERT_EQ(test_bitmap_1[8], 1);
    ASSERT_EQ(test_bitmap_1[10], 1);
    ASSERT_EQ(test_bitmap_1[12], 1);
}

TEST_F(BitMapTestClass, Test_MapFlip) {
    ASSERT_EQ(0, 0);
    test_bitmap_1.reset();
    test_bitmap_1[10] = 1;
    test_bitmap_1[8] = 1;
    test_bitmap_1.flip();
    ASSERT_EQ(test_bitmap_1[8], 0);
    ASSERT_EQ(test_bitmap_1[9], 1);
    ASSERT_EQ(test_bitmap_1[10], 0);
}

TEST_F(BitMapTestClass, Test_MapEqual) {
    test_bitmap_1.reset();
    test_bitmap_1[10] = 1;
    test_bitmap_1[8] = 1;
    test_bitmap_2.reset();
    test_bitmap_2[10] = 1;
    ASSERT_EQ(test_bitmap_1 == test_bitmap_2, false);
    test_bitmap_2[8] = 1;
    ASSERT_EQ(test_bitmap_1 == test_bitmap_2, true);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);//将命令行参数传递给gtest
    return RUN_ALL_TESTS(); //RUN_ALL_TESTS()运行所有测试案例
    system("pause");
}