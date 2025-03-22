#include "Week1double.h"

int main() {
    doublyLinkedList list;
    initDoublyLinkedList(&list);

    int choice, data, targetData;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // 销毁链表
                freeDoublyLinkedList(&list);
                printf("链表已销毁。\n");
                break;

            case 2: // 从头插入
                printf("输入要插入的数据：");
                scanf("%d", &data);
                insertAtHead(&list, data);
                printf("数据已插入。\n");
                break;

            case 3: // 从尾插入
                printf("输入要插入的数据：");
                scanf("%d", &data);
                insertAtTail(&list, data);
                printf("数据已插入。\n");
                break;

            case 4: // 在指定节点前插入
                printf("输入目标节点的数据：");
                scanf("%d", &targetData);
                printf("输入要插入的数据：");
                scanf("%d", &data);
                insertBeforeNode(&list, targetData, data);
                printf("数据已插入。\n");
                break;

            case 5: // 删除节点
                printf("输入要删除的数据：");
                scanf("%d", &data);
                deleteNode(&list, data);
                printf("数据已删除。\n");
                break;

            case 6: // 查找节点
                printf("输入要查找的数据：");
                scanf("%d", &data);
                if (findNode(&list, data)) {
                    printf("节点存在！\n");
                } else {
                    printf("节点不存在！\n");
                }
                break;

            case 7: // 正向打印链表
                printListForward(&list);
                break;

            case 8: // 反向打印链表
                printListBackward(&list);
                break;

            case 9: // 退出
                freeDoublyLinkedList(&list);
                printf("正在退出...\n");
                return 0;

            default:
                printf("无效输入，请重试！\n");
                break;
        }

        // 暂停并等待用户按回车键
        if (choice != 9) {
            printf("\n按回车键继续...");
            while (getchar() != '\n'); // 清除输入缓冲区
            getchar(); // 等待用户按下回车键
            system("cls"); // 清屏
        }
    } while (choice != 9);

    return 0;
}