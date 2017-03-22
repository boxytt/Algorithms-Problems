//
//  main.cpp
//  CPPTest
//
//  Created by boxytt on 2017/3/21.
//  Copyright © 2017年 boxytt. All rights reserved.
//

#include <iostream>
using namespace std;


typedef int ListData;
typedef struct node {
    ListData data;
    struct node *next;
}ListNode;
typedef ListNode *LinkedList;




void initList(LinkedList &first, int *array, int len) {
    // 初始化长度为len的链表fitst，并将数组array中的元素依次插入到链表fitst中
    first = NULL;
    ListNode *record = first;
    ListNode *tmp;
    
    for (int i = 0; i < len; i++) {
        
        // 新节点
        tmp = (ListNode *)malloc(sizeof(ListNode));
        tmp->data = array[i];
        tmp->next = NULL;
        
        
        if (first == NULL) {
            // 头节点
            first = tmp;
            record = first;
        } else {
            record->next = tmp;
            record = tmp;
        }
        
    }
}

void print_list(LinkedList first) {
    // 将链表fitst中的元素依次打印
    ListNode *tmp = first;
    
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}


LinkedList ListReverse(LinkedList first) {
    // 返回链表fitst的翻转链表
    
    if (!first | !first->next) {
        // 如果单链表为空活着只有一个节点，无需翻转
        return first;
    }
    
    ListNode *preverse = NULL; // 翻转后的新链表头指针，初始化为NULL
    ListNode *current = first;
    while (current) {
        ListNode *tmp = current;
        current = current->next;
        tmp->next = preverse;  // 将当前节点记录，插入新新链表的最前端
        preverse = tmp;
    }
    return preverse;
    
}



int main(int argc, const char * argv[]) {
    
    int array[] = {1, 2, 3, 4, 5};
    int n = 5;
    LinkedList fitst;
    initList(fitst, array, n);
    print_list(fitst);
    printf("\n");
    print_list(ListReverse(fitst));
    return 0;
}
