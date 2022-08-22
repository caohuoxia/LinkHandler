//
//  Questions.h
//  算法C语言
//
//  Created by caohx on 2022/8/15.
//

/* 动态规划题(贪心算法)：
 1、求储水面积最大
 2、求股票收益最大
 3、求连续子数组的最大和
 4、跳台阶（一次跳一级或跳两级，现在问要跳到n级台阶上 有多少种跳法）
 
 5、 找数组重复数字（数组长度0<=n<=10000,数组元素为0~n-1，这个信息很关键，因为有这个 才会有数据重排这个最优算法）
 */

#ifndef Questions_h
#define Questions_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../经典排序/Sort.h"

// 注意第一个a和b不需要括号
#define MaxValue(a,b)  ((a>=b)? (a):(b))
#define MinValue(a,b)  ((a<=b)? (a):(b))

// 声明接口
int maxWaterArea(int *heights, int size);
int maxProfit(int *shares, int size);
int maxSubArrSum(int *arr, int size);
int *maxLongSubArr(int *array, int arrayLen, int *retLength);

int jumpFloor(int num);
int jumpFloor1(int num);
int jumpFloor2(int num);
int jumpFloor3(int num);

int findDuplicateNum(int *arr, int size);
int findDuplicateNum2(int *arr, int size);

int* printNumbers(int n, int* returnSize);
int* printNumbers1(int n, int* returnSize);

char *replaceSace(char *str);
char *replaceSace1(char *str);
#endif /* Questions_h */
