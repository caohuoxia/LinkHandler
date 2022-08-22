//
//  StackToQueue.c
//  算法C语言
//
//  Created by caohx on 2022/8/22.
//

#include "StackToQueue.h"
typedef int ElementType;
typedef struct MyStack{
    ElementType data;
    struct MyStack *next;
} Stack;

// 声明两个栈
Stack *s1;
Stack *s2;

// 创建头结点
Stack *createHead(void) {
    Stack *head = (Stack*)malloc(sizeof(Stack));
    if (head == NULL) {
        printf("空间不足,创建头结点失败\n");
        return NULL;
    }
    head->data = -1;
    head->next = NULL;
    return head;
}
// 创建新节点
Stack *createNode(ElementType data) {
    Stack *p = (Stack*)malloc(sizeof(Stack));
    if (p == NULL) {
        printf("创建新节点失败\n");
        return NULL;
    }
    p->data = data;
    p->next = NULL;
    return p;
}

// 新节点添加到链表中 (入栈 头插法)
Stack *pushNode(Stack *head, ElementType data) {
    if (head == NULL) {
        return NULL;
    }
    Stack *temp = createNode(data);
    if (temp != NULL) {
        temp->next = head->next;
        head->next = temp;
    }
    return head;
}

// 出栈 （从头部先出栈 符合栈的特点：先进后出，后进先出的特点）
ElementType popNode(Stack *head) {
    if (head == NULL || head->next == NULL) {
        return -1;
    }
    Stack *temp = head->next;
    ElementType data = temp->data;
    head->next = temp->next;
    free(temp);
    temp = NULL;
    return data;
}

// 队列 入队：  思路就是s1入栈， s2用来pop的
// 例如 依次输入 2,3，4  那么s1栈为：4->3->2,；当s2 pop的时候，若没有元素则把s1先入栈到s2 即s1 pop ，s2 push pop是从右首开始
void push(ElementType node) {
    if (s1 == NULL) {
        s1 = createHead();
    }
    if (s2 == NULL) {
        s2 = createHead();
    }
    printf("%d 入队\n",node);
    pushNode(s1, node);
}

//  出队
ElementType pop(void) {
    if (s1 == NULL) {
        s1 = createHead();
    }
    if (s2 == NULL) {
        s2 = createHead();
    }
    // 若pop 栈为空 那先把s1栈的元素依次全压入s2，之后再pop s2栈顶元素
    ElementType data;
    if (s2->next == NULL) {
        while (s1->next != NULL) {
            data = popNode(s1);
            pushNode(s2, data);
        }
    }
    if (s2->next == NULL) {
        printf("队列已经空了\n");
    }
    data = popNode(s2);
    return data;
}

#pragma mark - 调用入口
void callStackToQueue(void) {
    push(2);
    push(3);
    printf("%d 出队\n",pop());
    push(5);
    printf("%d 出队\n",pop());
}
