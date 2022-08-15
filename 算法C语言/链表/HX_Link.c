//
//  HX_Link.c
//  面试算法C语言
//
//  Created by caohx on 2022/8/9.
//

// 单链表反转
// 1 方法一： 头插法
// 2 方法二： 3个指针变量法

#include "HX_Link.h"

// 反转单链表调用入口
void callReverseLink() {
    Node *head = create_link_head();
    for (int i = 1; i<8; i++) {
        add_node_head(head, create_new_node(i));
    }
    display_link(head);
    reverse_link2(head);
    display_link(head);
    
    free_link(head);
    display_link(head);
}

void callMyMergeLink() {
    Node *l1, *l2, *l;
    l1 = readLink();
    l2 = readLink();
    display_link(l1);
    display_link(l2);
    l = mergeLink(l1, l2);
    display_link(l);
}

// 回文链表判断 快慢指针法
int isHuiwen(Node *head) {
    if (head == NULL || head->next == NULL) {
        printf("只有一个节点 是回文链表");
        return 1;
    }
    Node *slow = head;
    Node *fast = head;
    // 逆序后半部链表 变量定义
    Node *head1 = create_link_head(); // 注意这个赋值，不要直接=head
    Node *pre = NULL, *temp = NULL,*p = NULL;
    while (fast!=NULL && fast->next!= NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    p = slow->next;
    // 逆序后半部分链表 三个变量指针法
    while (p) {
        temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
    }
    // 注意是head1->next,不是head1。注意赋值的是pre不是 p，p此时已经是NULL了
    head1->next = pre;
    // 两链表依次比较值，看是否相同，若都相同则是回文链表，否则不是
    while ((head = head->next) !=NULL && (head1 = head1->next) !=NULL) {
        if (head->data != head1->data) {
            printf("不是回文链表\n");
            return 0;
        }
    }
    printf("是回文链表\n");
    return 1;
}

Node *deleteNode(Node *head, int val) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node *temp = head->next, *pre = head;
    // 第一个节点就是 要删除的节点
    if (temp->data == val) {
        head->next = temp->next;
        free(temp);
        return head;
    }
    while (temp!=NULL && pre!=NULL) {
        if (temp->data == val) {
            pre->next = temp->next;
            free(temp);
            break;
        }
        pre = temp;
        temp = temp->next;
    }
    return head;
}

// 删除链表中重复的节点，例如1->2->3->3->5,删除重复的3节点之后 为1->2->5
Node *deleteDup(Node *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node *curr = head->next, *pre = head;
    while (curr->next!=NULL && pre!=NULL) {
        int temp = curr->data;
        if (curr->data == curr->next->data) { // 有相邻重复的
            while (curr->next != NULL && curr->next->data == temp) {
                curr->next = curr->next->next;
            }
            pre->next = curr->next;
        }else {
            pre = curr;
            curr = curr->next;
        }
    }
    return head;
}

// 读取升序链表
Node *readLink() {
    Node *head,*l;
    head=l= (Node*)malloc(sizeof(Node));
    l->next = NULL;
    int len;
    printf("输入链表长度：\n");
    scanf("%d", &len);
    for (int i=0; i<len; i++) {
        l->next = (Node*)malloc(sizeof(Node));
        scanf("%d", &l->next->data);
        l = l->next;
    }
    l->next = NULL;
    return head;
}

Node *mergeLink(Node *l1,Node *l2) {
    Node *head, *l;
    head=l= (Node*)malloc(sizeof(Node));
    l->next = NULL;
    Node *p = l1->next,*s = l2->next;
    while (p != NULL && s!= NULL) {
        if (p->data <= s->data) {
            l->next = p;
            p = p->next;
            l = l->next;
        }else {
            l->next = s;
            s = s->next;
            l = l->next;
        }
    }
    if (p == NULL) {
        l->next = s;
    }
    if (s == NULL) {
        l->next = p;
    }
    l1->next = NULL;
    l2->next = NULL;
    return head;
}

// 方法实现
// 创建表头
Node* create_link_head() {
    Node *head = (Node*)malloc(sizeof(Node));
    if (head != NULL) {
        head->data = -1;
        head->next = NULL;
    }
    return head;
}

// 创建新节点
Node* create_new_node(int node_data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->data = node_data;
        new_node->next = NULL;
    }
    return new_node;
}

// 将新加的节点插入到链表中；头插法；return 0成功，return -1 失败
int add_node_head(Node* head, Node* new_node) {
    if (head == NULL || new_node == NULL) {
        return -1;
    }
    new_node->next = head->next;
    head->next = new_node;
    return 0;
}

// 打印链表
void display_link(Node *head) {
    if (head == NULL) {
        printf("sorry, link is NULL. \n");
        return;
    }
//    printf("%d \n", head->data);
    Node *temp = head;
    printf("link data: ");
    while (NULL != (temp = temp->next)) {
        printf("%d  ", temp->data);
    }
    printf("\n");
}

// 单链表reverse 头插法
Node* reverse_link(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node *p = head->next;
    head->next = NULL;
    Node *temp = NULL;
    while (p) {
        temp = p->next;
        add_node_head(head, p);
        p = temp;
    }
    return head;
}

// 单链表逆序2 用三个指针的方法
Node* reverse_link2(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node *pre = NULL;
    Node *p = head->next;
    Node *temp = NULL;
    while (p) {
        temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
    }
    head->next = pre;
    return head;
}

// 释放链表
void free_link(Node *head) {
    if (head == NULL) {
        return;
    }
    Node *p = head;
    while (NULL != (p = p->next)) {
        head->next = p->next;
        free(p);
        p = head;
    }
    free(head);
    head = NULL;
}
