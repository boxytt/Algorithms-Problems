#include <iostream>

void printTimesOfEachNum(int pages) {
    // 给定一个正整数页数pages, 求从 1～pages 页中 0～9 出现的次数
    
    if (pages <= 0) {
        printf("输入不正确");
    }
    
    // 用来存储每个数字出现的次数
    int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    // 用%求最地位，用／去掉最低位
    for (int i = 1; i <= pages; i++) {
        
        int n = i; // 用来存储 / 后得出的除去最低位数后剩余的数
        int a = 0; // 用来存储mod后得出的最低位数
        
        while (n != 0) {
            a = n % 10;
            array[a]++;
            n = n / 10;
        };
        
    }
    
    // 打印
    for (int i = 0; i <= 9; i ++) {
        printf("数字%d有%d个\n", i, array[i]);
    }
}

int main(int argc, const char * argv[]) {
    
    int pages = 329;
    
    printTimesOfEachNum(pages);
    
    return 0;
}
