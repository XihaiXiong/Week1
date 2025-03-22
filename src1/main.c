#include "Week1.h"


int main() {
    linkedList list;
    initLinkedList(&list);

    int choice;
    int data;

    do {
        printMenu();//打印菜单

        scanf("%d", &choice);
        switch (choice) {

            case 1: // 销毁链表
                freeList(&list);
            printf("已经销毁。\n");
            break;

            case 2: // 头部插入
                printf("输入你想从头插入的整数data：");
            scanf("%d", &data);
            insertAtHead(&list, data);
            printf("已经插入。\n");
            break;

            case 3: // 尾部插入
                printf("输入你想从尾插入的整数data： ");
            scanf("%d", &data);
            insertAtTail(&list, data);
            printf("已经插入。\n");
            break;

            case 4: // 删除节点
                printf("输入你想删除的数据： ");
            scanf("%d", &data);
            deleteNode(&list, data);
            printf("已经删除。\n");
            break;

            case 5: // 查找节点是否存在
                printf("输入你想查找的数据：");
            scanf("%d", &data);
            if (findNode(&list, data) != NULL) {
                printf("存在！\n");
            } else {
                printf("不存在！\n");
            }
            break;

            case 6: // 打印结果
                printf("打印结果： ");
            printList(&list);
            break;

            case 7: // Exit
                freeList(&list); // 先要释放内存
            printf("正在退出...\n");
            return 0;

            default:
                printf("\n无效输入，请重试！\n");
            continue;
        }

        // 暂停并等待用户按任意键
        if (choice != 7) {
            printf("\n按回车键继续...");
            getchar();    // 等待用户按下回车键
            clearInput();
            system("cls"); // 清屏
        }

    }while (choice != 7);

    return 0;
}





