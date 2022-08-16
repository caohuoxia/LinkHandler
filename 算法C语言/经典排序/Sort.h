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
//  全局存储数组的长度
static int ArrayLength = 0;

//int *quickSort(int *arr, int left, int right);
int *bubbleSort(int *arr, int size);


void sortCallEntry(void);
int *readArray(void);
void printArray(int *arr, int size);
void swapTwo(int *a, int *b);
#endif /* Sort_h */
