#include "Week1.h"

//菜单
void printMenu() {
    printf("\n===== 交互系统（请输入以下数字，作业里的链表数据仅有一项整数） =====\n");
    printf("                           1. 销毁链表\n");
    printf("                          2. 从头插入链表\n");
    printf("                          3. 从尾插入链表\n");
    printf("                           4. 删除节点\n");
    printf("                           5. 寻找节点\n");
    printf("                           6. 打印链表\n");
    printf("                             7. 退出\n");
    printf("                              请选择： ");
}

// 清空输入缓冲区
void clearInput(int c) {

    while ((c = getchar()) != '\n' && c != EOF) {}
}

// 初始化链表
void initLinkedList(linkedList* list) {
    list->head = NULL;
}

//创建新节点
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
    }

//销毁链表
void freeList(linkedList* list) {
    node* temp = list->head;
    while (temp != NULL) {
        node* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}

// 插入节点到链表头部
void insertAtHead(linkedList* list, int data) {
    node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// 插入节点到链表尾部
void insertAtTail(linkedList* list, int data) {
    node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 删除链表中的节点
void deleteNode(linkedList* list, int key) {
    node* temp = list->head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        list->head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// 查找链表中的节点
node* findNode(linkedList* list, int key) {
    node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == key) return temp;
        temp = temp->next;
    }
    return NULL;
}


// 打印链表
void printList(linkedList* list) {
    node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
