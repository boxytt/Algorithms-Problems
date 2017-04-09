#include <stdio.h>

/*
    设计一个O(n^2)时间的算法，找出由n个数组成的序列的最长单调递增子序列
 */

#define n 10

int main() {

    int a[n] = {1, 2, 3, 1, 2, 1, 2, 3, 2, 1};
    
    int from_max[n] = {0};  // 最长单调递增子序列可能不止一个
    int len_max = 1;    // 最大单调递增子序列长度
    int count = 1;  // 最大单调递增子序列个数


    for (int i = 0; i < n - 1; i++) {
        // 以a[i]为起始
        int len_temp = 1;
        int from_temp = i;
        for (int j = i; j < n - 1; j++) {
            if (a[j+1] > a[j]) {
                len_temp++;
            } else {
                break;
            }
        }
        
        
        if (len_max < len_temp) {
            // 这才是最长的，替换
            len_max = len_temp;
            from_max[count - 1] = from_temp;
        } else if (len_max == len_temp) {
            // 跟最长的一样长
            count++;
            len_max = len_temp;
            from_max[count - 1] = from_temp;
        }

    }
    
    if (len_max == 1) {
        printf("最长子序列长度是1, 即每个元素都是最长子序列\n");
        return 0;
    }
    
    
    printf("有%d组最长单调递增子序列\n", count);
    for (int i = 0; i < count; i++) {
        printf("从%d开始，长度为%d个元素\n", from_max[i], len_max);
        for (int j = from_max[i]; j < from_max[i] + len_max; j++) {
            printf("%d ", a[j]);

        }
        printf("\n");

    }

    return 0;
    
}
