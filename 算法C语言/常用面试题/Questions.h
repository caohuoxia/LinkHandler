//
//  Questions.h
//  算法C语言
//
//  Created by caohx on 2022/8/15.
//

/* 动态规划题：
 1、求储水面积最大
 2、求股票收益最大
 */

#ifndef Questions_h
#define Questions_h

#include <stdio.h>

// 注意第一个a和b不需要括号
#define MaxValue(a,b)  ((a>=b)? (a):(b))
#define MinValue(a,b)  ((a<=b)? (a):(b))

// 声明接口
int maxWaterArea(int *heights, int size);
int maxProfit(int *shares, int size);

#endif /* Questions_h */
