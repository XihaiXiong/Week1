//
// Created by d4ncer on 25-3-17.
//

#ifndef WEEK1_H
#define WEEK1_H

//头文件区
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义节点类别
typedef struct Node {
    int data;
    struct Node* next;
} node;

//定义链表类别
typedef struct {
    node* head;
} linkedList;

//函数声明区
void initLinkedList(linkedList* list);
void freeList(linkedList* list);
node* createNode(int data);
void insertAtHead(linkedList* list, int data);
void insertAtTail(linkedList* list, int data);
void deleteNode(linkedList* list, int key);
node* findNode(linkedList* list, int key);
void printList(linkedList* list);
void printMenu();
void clearInput();


#endif //WEEK1_H
