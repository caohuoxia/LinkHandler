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

#pragma mark- 反转单词序列 例如： iOSCoder. a am I  ->  I am a iOSCoder.
// 思路： 利用栈先进后出的特点  中间构建一个临时stack来转化  从尾部遍历到首部
char *reverseSentence(char *str) {
    int len = (int)strlen(str), end = len-1;
    char *stack = (char*)malloc(sizeof(char)*(len+1));
    char *ret = (char*)malloc(sizeof(char)*(len+1));
    int top = 0, j = 0;
    // 倒叙遍历原字符串
    while (end>=0) {
        if (str[end] != ' ') {
            stack[top++] = str[end]; // 不是空格 将单词入栈
        }else {
            while (top>0) {
                ret[j++] = stack[--top];
            }
            ret[j++] = ' ';
        }
        end--;
    }
    // 当end==0时 单词的最后一个字母或者是标点符号入栈，但未保存到ret数组中。so单独处理下
    while (top>0) {
        ret[j++] = stack[--top];
    }
    ret[j] = '\0';
    return ret;
}
#pragma mark- 替换字符串中的空格
char *replaceSace(char *str) {
    int len = (int)strlen(str), spaceCount = 0;
    // 空格的总数量
    for (int i=0; i<len; i++) {
        if (str[i] == ' ') {
            spaceCount++;
        }
    }
    // 动态申请新数组空间
    char *temp = (char*)malloc(sizeof(char)*(len+3*spaceCount+1));
    for (int i=0,j=0; i<len; i++,j++) {
        if(str[i] == ' ') {
            temp[j] = '%';
            temp[j+1] = '2';
            temp[j+2] = '0';
            j = j+2; // 与i保持同步 主要是这里
        }else {
            temp[j] = str[i]; // 注意是temp[j] 不是temp[i]
        }
    }
    return temp;
}

#pragma mark-  打印1到最大的n位数，如 输入3，则打印出1,2,3 一直到最大的三位数999
int* printNumbers(int n, int* returnSize ) {
    // write code here
    if(n>5) {
        printf("n 小于等于5，请重新输入");
        return NULL;
    }
    int max = 9;
    if(n == 1) {
        max = 9;
    }else if(n == 2) {
        max = 99;
    }else if(n==3) {
        max = 999;
    }else if(n==4) {
        max = 9999;
    }else {
        max = 99999;
    }
    int *temp = (int*)malloc(sizeof(int)*max);
    for(int i=1,j=0;i<=max;i++) {
        printf("%d ",i);
        temp[j++] = i;
    }
    return temp;
}
// 其实大概思路是一样的 只是最大位数进一，类似最大3位数是999 也即1000-1
static int a[100000];
int* printNumbers1(int n, int* returnSize) {
    if (n>5) {
        printf("请输入小于等于5的数");
        return NULL;
    }
    int k = 1;
    for (int i=0; i<n; i++) {
        k*=10;
    }
    *returnSize = k-1;
    for (int j=1; j<k; j++) {
        a[j-1]=j;
    }
    return a;
}
#pragma mark- 找出数组中重复元素 返回任意重复元素即可
int findDuplicateNum(int *arr, int size) {
    // 方法一：暴力法
    int *temp = (int*)malloc(sizeof(int)*size);
    for (int i=0; i<size; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i] == temp[j]) {
                return temp[j];
            }
        }
        temp[i] = arr[i];
    }
    free(temp);
    temp = NULL;
    return -1;
}
// {4,3,2,1,1,0}
int findDuplicateNum2(int *arr, int size) {
    // 方法二：数据重排
    int i = 0, end = size - 1;
    while (i<end) {
        if (arr[i] == i) { // 在正确位置上，已经是排好序的
            i++;
            continue;
        }else {
            if (arr[i] == arr[arr[i]]) {
                return arr[i];
            }else {
                swapTwo(&arr[i], &arr[arr[i]]);
            }
        }
    }
    return -1;
}
#pragma mark- 子数组最大和
// 求子数组最大和，第一眼看到题 可能觉得题有问题，求和肯定是整个都加起来大啊，其实不然 因为该数组元素是-100~100之间，so才会有子数组最大这么一说
int maxSubArrSum(int *arr, int size) {
    // 方法一：暴力法 两次循环 把所有的子数组都遍历相加一遍
//    int ret = 0;
//    int sum = 0;
//    for (int i=0; i<size; i++) {
//        // 每开一次循环，重设sum
//        sum = 0;
//        for (int j=i; j<size; j++) {
//            sum += arr[j];
//            ret = MaxValue(ret, sum);
//        }
//    }
    
    // 方法二：动态规划 dp为子数组和，dp[i]为以arr[i]结尾的子数组和，状态转化为 dp[i] = max(dp[i-1]+arr[i], arr[i])
//    int dp[20] = {0};
//    dp[0] = arr[0];
//    int ret = arr[0];
//    for (int i=1; i<size; i++) {
//        dp[i] = MaxValue(dp[i-1] + arr[i], arr[i]);
//        ret = MaxValue(ret, dp[i]);
//    }
    
    // 方法三：方法二优化  这种方法最优  时间复杂度O(n),空间复杂度O(1)
    int sum = 0;
    int ret = arr[0];
    for (int i=0; i<size; i++) {
        sum = MaxValue(sum + arr[i], arr[i]);
        ret = MaxValue(ret, sum);
    }
    return ret;
}

// 子数组最大和的 子数组
int *maxLongSubArr(int *array, int arrayLen, int *retLength) {
    int dp[30] = {0};
    static int retArr[30] = {0};
    dp[0] = array[0];
    int maxSum = dp[0]; //[1,-2,3,10,-4,7,2,-5]
    int left = 0,right = 0; // 左右游标
    int resl = 0 ,resr = 0; // 最大值相同的情况下 最长的子数组 两端游标
    for(int i=1;i<arrayLen;i++) {
        right++;
        dp[i] = MaxValue(dp[i-1]+array[i], array[i]);
        if(dp[i-1]+array[i] < array[i]) {
            left = right;
        }
        if((dp[i]>maxSum) || (dp[i]==maxSum && (left+right-1)>(resl+resr-1))) {
            maxSum = dp[i];
            resl = left;
            resr = right;
        }
    }
    // 取出数组
    for(int i = resl,j=0;i<=resr;i++) {
        retArr[j++] = array[i];
    }
    *retLength = resr-resl+1;
//    int *p = retArr; // 断点到这，retArr是正常的，算法是没有问题的。但是在外面调用接收的时候 打印3 32766 541901142 32767 2  却是不正常的. 那是因为这个p是个局部指针，当跳出该函数 就已经被释放了。  retArr 添加static 成局部静态变量
    return retArr;
}

#pragma mark- 跳台阶
// 方法一：逆向思维，从n级 下台阶有多少种下法，可以一级一级的下 下到n-1级，也可以一次下两级 下到n-2级。所有下法有f(n) = f(n-1) + f(n-2), 初始条件为f(0)=f(1) = 1;
// 用递归，代码简单 但非常慢： 时间复杂度为2的n次方，空间复杂度：递归栈的空间
int jumpFloor(int num) {
    // 递归退出条件 (或初始条件)
    if (num<=1) return 1;
    int ret = jumpFloor(num-1) + jumpFloor(num-2);
    return ret;
}

// 方法二：改进上面的递归，记忆搜索法.  借助空间换时间； 时间复杂度 O(n),空间复杂度 O(n)+递归栈空间
// 额外定义一个数组用来存 算过的f(number)
int f[50] = {0};
int jumpFloor1(int num) {
    if (num<=1) return 1;
    if (f[num]>0) return f[num];
    return f[num] = jumpFloor(num-1) + jumpFloor(num-2);
}

// 方法三: 动态规划  从一系列的子序列 直接得到结果; 时间复杂度 O(n), 空间复杂度O(n)
int jumpFloor2(int num) {
    if (num<=1) return 1;
    int dp[50] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<=num; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[num];
}

// 方法四：继续优化 时间复杂度O(n), 空间复杂度O(1)  // 牛客网上 内存占用比开辟数组递归那个 内存还要占用多点
int jumpFloor3(int num) {
    if (num<=1) return 1;
    int a = 1, b = 1, c = 0;
    for (int i=2; i<=num; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
