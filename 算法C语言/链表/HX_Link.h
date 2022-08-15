//
//  HX_Link.h
//  面试算法C语言
//
//  Created by caohx on 2022/8/9.
//

/* 链表相关操作，包含的功能：
 1、创建头结点
 2、根据值创建新节点
 3、从终端读取链表（头插法和尾插法）
 4、释放链表
 5、打印链表
 6、逆序链表-头插法
 7、逆序链表-三指针变量法
 8、合并两个升序链表
 9、判断回文链表（快慢指针）
 */

#ifndef HX_Link_h
#define HX_Link_h

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
// 定义节点, 简便使用 重命名成Node
typedef struct node
{
    ElementType data;
    struct node *next;
}Node;

// 声明方法列表
Node* create_link_head(void);
Node* create_new_node(int node_data);
int add_node_head(Node* head, Node* new_node);
void display_link(Node *head);
void free_link(Node *head);
// 头插法
Node* reverse_link(Node* head);
// 三个指针法
Node* reverse_link2(Node* head);

// 合并两个升序链表
Node *readLink(void);
Node *mergeLink(Node *l1,Node *l2);

// 判断单链表是否为回文链表, 是返回1，不是返回0
int isHuiwen(Node *head);

// 调用入口
void callMyMergeLink(void);
void callReverseLink(void);

#endif /* HX_Link_h */
