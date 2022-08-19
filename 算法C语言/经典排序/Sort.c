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

//  冒牌排序： 两两比较 大的往下沉
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

// 选择排序：从未排序的序列中 选择最小的 放入已排序的列表中  默认第一个最小
void selectSort(int *arr, int size) {
    int min;
    for (int i=0; i<size-1; i++) {
        min = i;
        for (int j=i+1; j<size; j++) {
            if (arr[j]<arr[min]) {
                min = j; // 记录最小值
            }
        }
        if (min !=i) {
            swapTwo(&arr[min], &arr[i]);
        }
    }
    printArray(arr, size);
}

// 插入排序
void insertSort(int *arr, int size) {
    int i,j,temp;
    for (i=1; i<size; i++) {
        temp = arr[i];
        for (j=i; j>0 && arr[j-1]>temp; j--) {
            arr[j] = arr[j-1]; // 大的往后移
        }
        arr[j] = temp;
    }
}

#pragma mark-  public method
void sortCallEntry(void) {
    int size = 0;
    int *arr = readArray(&size);
//    int arr1[] = {7,3,2,4,8};
    selectSort(arr, size);
    // bubble里面也没问题，为什么quicksort里面 read就出错呢。不read硬编码也没问题 奇怪！！！
//    int *p = bubbleSort(arr, size);
//    int *p = quickSort(arr, 0, ArrayLength-1);
//    int a[6] = {9,3,1,5,7,2};
//    quickSort(a, 0, 5);
//    printf("排序后的数组：\n");
//    printArray(arr, size);
}

// 从终端读取数组 （指针函数 重点是函数，函数指针 是指针 只不过是指向函数的指针）
int *readArray(int *arrySize) {
    int num = 0;
    printf("输入数组长度(小于20)：\n");
    scanf("%d", &num);
    *arrySize = num;
    // 法一：数组 此时不需要释放
    static int arr[50];
//    int *p = arr;
//    int *arr = (int*)malloc(sizeof(int)*ArrayLength); // 法二：动态申请内存，注意适时释放
    for (int i=0; i<num;i++) {
        scanf("%d",&arr[i]);
    }
    return arr;
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

