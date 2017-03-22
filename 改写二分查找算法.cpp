//
//  main.cpp
//  CPPTest
//
//  Created by boxytt on 2017/3/21.
//  Copyright © 2017年 boxytt. All rights reserved.
//

#include <iostream>
using namespace std;


#include <stdio.h>

#define n 10

/*
 设a[0: n-1]是已排好序的数组。请改写二分搜索算法，使得:
 当搜索元素x不在数组中时，返回小于x的最大元素位置i和大于x的最小元素位置j。
 当搜索元素在数组中时，i和j相同，均为x在数组中的位置。
 */
void binary_search(int a[], int low, int high, int x) {
    
    // 存储i和j
    int i;
    int j;
    
    int mid = (low + high) / 2;
    
    
    if (low <= high) {
        
        if (x == a[mid]) {
            i = mid;
            j = mid;
            printf("找到了，i = %d, j = %d\n", i, j);
            
        } else if (x < a[mid]) {
            
            return binary_search(a, low, mid - 1, x);
        } else if (x > a[mid]) {
            
            return binary_search(a, mid + 1, high, x);
        }
        
    } else {
        // 此时，low > high
        i = high;
        j = low;
        printf("找不到,i = %d, j = %d\n", i, j);
    }
    
}

int main(int argc, char *argv[])
{
    // 有序数组a
    int a[n] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    
    //搜索元素x, 打印i和j
    int x = 45;
    binary_search(a, 0, n - 1 ,x);  // 找不到,i = 2, j = 3
    
    int y = 40;
    binary_search(a, 0, n - 1, y);  // 找到了，i = 3, j = 3
    
    
    return 0;
}
