//
//  Sort.c
//  算法C语言
//
//  Created by caohx on 2022/8/16.
//

#include "Sort.h"

// 快速排序 （分治策略、递归算法）
// 找基准点，这个点的左边比它都小，右边比它都大(不是这样就交换成这样)
int partition(int *arr, int left, int right) {
    int key = arr[left];
    while (left<right) {
        while (left<right && arr[right]>=key) --right;
        swapTwo(&arr[left], &arr[right]);
        while (left<right && arr[left]<=key) ++left;
        swapTwo(&arr[left], &arr[right]);
    }
    return left;
}
void quickSort(int *arr, int left, int right) {
    if (left<right) {
        int privot = partition(arr, left, right);
        quickSort(arr, left, privot-1);
        quickSort(arr, privot+1, right);
    }
}


//  冒牌排序
int *bubbleSort(int *arr, int size) {
    int flag = 0;
    for (int i=0; i<size; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swapTwo(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break; // 已经排好序了，退出循环
        }
    }
    
    return arr;
}

#pragma mark-  public method
void sortCallEntry(void) {
//    int *arr = readArray();
    // bubble里面也没问题，为什么quicksort里面 read就出错呢。不read硬编码也没问题 奇怪！！！
//    int *p = bubbleSort(arr, ArrayLength);
//    int *p = quickSort(arr, 0, ArrayLength-1);
    int a[6] = {9,3,1,5,7,2};
    quickSort(a, 0, 5);
    printf("排序后的数组：\n");
    printArray(a, 6);
}

// 从终端读取数组 （指针函数 重点是函数，函数指针 是指针 只不过是指向函数的指针）
int *readArray(void) {
    printf("输入数组长度(小于20)：\n");
    scanf("%d", &ArrayLength);
    // 法一：数组 此时不需要释放
    int arr[ArrayLength];
    int *p = arr;
//    int *arr = (int*)malloc(sizeof(int)*ArrayLength); // 法二：动态申请内存，注意适时释放
    for (int i=0; i<ArrayLength;i++) {
        scanf("%d",&arr[i]);
    }
    return p;
}

// 打印数组
void printArray(int *arr, int size) {
    if (size <= 0 ) {
        printf("空数组无需打印\n");
    }
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swapTwo(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

