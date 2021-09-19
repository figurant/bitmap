# C++实现的bitmap
##主要文件  
source 目录下为类定义与实现  
test/tests 目录下为单元测试  
##基本用法  
//创建建一个1024位的bitmap  
BitMap bitmap = BitMap(1024);  
//为第10位赋值1  
bitmap[10] = 1;  
//打印第8位  
std::cout << bitmap[8] << std::endl;  

更多用法可见单元测试：test/tests/bitmap_test.cpp  
