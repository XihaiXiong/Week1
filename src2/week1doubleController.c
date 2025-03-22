#include "Week1double.h"

// 打印菜单
void printMenu() {
    printf("\n  ===== 双向链表系统 =====\n");
    printf("       1. 销毁链表\n");
    printf("      2. 从头插入链表\n");
    printf("      3. 从尾插入链表\n");
    printf("     4.在指定节点前插入\n");
    printf("       5. 删除节点\n");
    printf("       6. 寻找节点\n");
    printf("      7. 正向打印链表\n");
    printf("      8. 反向打印链表\n");
    printf("          9. 退出\n");
    printf("          请选择： ");
}

// 初始化双向链表
void initDoublyLinkedList(doublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

// 创建新节点
dNode* createDNode(int data) {
    dNode* newNode = (dNode*)malloc(sizeof(dNode));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 销毁双向链表
void freeDoublyLinkedList(doublyLinkedList* list) {
    dNode* temp = list->head;
    while (temp != NULL) {
        dNode* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

// 在头部插入节点
void insertAtHead(doublyLinkedList* list, int data) {
    dNode* newNode = createDNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

// 在尾部插入节点
void insertAtTail(doublyLinkedList* list, int data) {
    dNode* newNode = createDNode(data);
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// 在指定节点前插入新节点
void insertBeforeNode(doublyLinkedList* list, int targetData, int newData) {
    dNode* targetNode = findNode(list, targetData);
    if (targetNode == NULL) {
        printf("未找到目标节点！\n");
        return;
    }
    dNode* newNode = createDNode(newData);
    newNode->prev = targetNode->prev;
    newNode->next = targetNode;
    if (targetNode->prev != NULL) {
        targetNode->prev->next = newNode;
    } else {
        list->head = newNode;
    }
    targetNode->prev = newNode;
}

// 删除指定节点
void deleteNode(doublyLinkedList* list, int key) {
    dNode* temp = list->head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("未找到要删除的节点！\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        list->head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        list->tail = temp->prev;
    }
    free(temp);
}

// 查找节点
dNode* findNode(doublyLinkedList* list, int key) {
    dNode* temp = list->head;
    while (temp != NULL) {
        if (temp->data == key) return temp;
        temp = temp->next;
    }
    return NULL;
}

// 正向打印链表
void printListForward(doublyLinkedList* list) {
    dNode* temp = list->head;
    printf("正向打印链表： ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 反向打印链表
void printListBackward(doublyLinkedList* list) {
    dNode* temp = list->tail;
    printf("反向打印链表： ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
