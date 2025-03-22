#ifndef WEEK1DOUBLE_H
#define WEEK1DOUBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义双向链表节点结构
typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} dNode;

// 定义双向链表结构
typedef struct {
    dNode* head;
    dNode* tail; // 增加尾指针方便尾部操作
} doublyLinkedList;

// 函数声明
void initDoublyLinkedList(doublyLinkedList* list);
void freeDoublyLinkedList(doublyLinkedList* list);
dNode* createDNode(int data);
void insertAtHead(doublyLinkedList* list, int data);
void insertAtTail(doublyLinkedList* list, int data);
void insertBeforeNode(doublyLinkedList* list, int targetData, int newData);
void deleteNode(doublyLinkedList* list, int key);
dNode* findNode(doublyLinkedList* list, int key);
void printListForward(doublyLinkedList* list);
void printListBackward(doublyLinkedList* list);
void printMenu();

#endif // WEEK1DOUBLE_H