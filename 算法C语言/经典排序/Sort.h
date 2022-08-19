//
//  Sort.h
//  算法C语言
//
//  Created by caohx on 2022/8/16.
//

/* 八大排序 （给出的demo都是升序排序）
 交换位置：
 1、冒泡排序
 2、快速排序 （分治 递归思想）
 
 3、
 */

#ifndef Sort_h
#define Sort_h

#include <stdio.h>
#include <stdlib.h>
//  全局存储数组的长度 或者用入参 带出size，此时注意要用指针
static int ArrayLength = 0;

void quickSort(int *arr, int left, int right);
int *bubbleSort(int *arr, int size);
void selectSort(int *arr, int size);
void insertSort(int *arr, int size);

void sortCallEntry(void);
int *readArray(int *arrySize);
void printArray(int *arr, int size);
void swapTwo(int *a, int *b);
#endif /* Sort_h */
