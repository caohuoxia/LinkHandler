//
//  Questions.c
//  算法C语言
//
//  Created by caohx on 2022/8/15.
//

#include "Questions.h"

int maxWaterArea(int *heights, int size) {
    int i = 0, j = size-1;
    int ret = 0;
    while (i<j) {
        ret = MaxValue(ret, MinValue(heights[i],heights[j])*(j-i));
        heights[i]<=heights[j] ? i++:j--;
    }
    return ret;
}

// 要想收益最大，即最低买入，最高卖出，卖出点不能早于买入点
int maxProfit(int *shares, int size) {
    // 最小的买入点
    int ret = 0;
    for (int i=1, minBuy=shares[0]; i<size-1; i++) {
        ret = MaxValue(ret, shares[i]-minBuy);
        // 动态更新最低买入点
        minBuy = MinValue(minBuy, shares[i]);
    }
    return ret;
}
