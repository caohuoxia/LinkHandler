//
//  main.c
//  算法C语言
//
//  Created by caohx on 2022/8/15.
//

/* 该工程是通过 macos下->application->commend line tool 选择c语言 建立的
 1、建立完更改下签名那 让sign to loacal
 2、c语言 需在h文件里声明方法接口，才能在main里正常调用
 */

/* 弃：若按之前ios 正常工程新建，在终端里面执行程序
 终端里面编译执行：
 编译: gcc XXX.c -o XXX
 运行：./XXX
 问题：Xcode里编写c代码的时候，编写的过程中一跳一跳，也没有代码补齐提示，特别难受不方便，最重要的还不能lldb调试
 */

#include <stdio.h>
#include "HX_Link.h"
#include "./常用面试题/Questions.h"
#include "./经典排序/Sort.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
//    callMyMergeLink();
//    int heights[] = {1,8,6,2,5,4,8,3,7};
//    // c语言里 求数组长度
//    int size = sizeof(heights)/sizeof(int);
//    int ret = maxWaterArea(heights, size);
//    printf("最大储水量为：%d\n",ret);
    
//    int shares[] = {7,1,5,3,6,4};
//    // c语言里 求数组长度
//    int len = sizeof(shares)/sizeof(int);
//    int ret1 = maxProfit(shares, len);
//    printf("最大股票收益为：%d\n",ret1);
    
//    Node *head = readLink();
//    display_link(head);
//    isHuiwen(head);
//    printf("输入要删的数据：\n");
//    int toDelete = 0;
//    scanf("%d",&toDelete);
//    deleteNode(head, toDelete);
//    deleteDup(head);
//    display_link(head);
    sortCallEntry();
    return 0;
}
