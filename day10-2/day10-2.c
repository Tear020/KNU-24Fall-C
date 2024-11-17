#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 50

enum Rank {
    BRONZE = 3,
    SILVER = 2,
    GOLD = 1
};

struct Customer {
    char customerName[NAME_MAX];
    enum Rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
};

struct Customer* head;

struct Customer* create_customer(char* name, enum Rank rank, int order_amount, int point) {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    strcpy_s(new_customer->customerName, NAME_MAX, name);
    new_customer->rank = rank;
    new_customer->order_amount = order_amount;
    new_customer->point = point;
    new_customer->prev = NULL;
    new_customer->next = NULL;
    return new_customer;
}

struct Customer* find_insert_position(enum Rank rank, int order_amount, int point) {
    struct Customer* cur = head->next;

    while (cur != NULL)
    {
        // �� ����� �������� �켱������ ���� > �״��� �ֹ��� Ŭ���� > �״��� ����Ʈ ��������
        if (cur->rank > rank) {
            return cur;
        }

        else if (cur->rank == rank) {
            if (cur->order_amount > order_amount) {
                return cur;
            }

            else if (cur->order_amount == order_amount) {
                if (cur->point > point) {
                    return cur;
                }
            }
        }
        cur = cur->next;
    }
    return NULL;
}

void insert_customer(char* name, enum Rank rank, int order_amount, int point)
{
    struct Customer* new_customer = create_customer(name, (enum Rank)rank, order_amount, point);
    struct Customer* insert_pos = find_insert_position(rank, order_amount, point);

    if (insert_pos == NULL)
    {
        struct Customer* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_customer;
        new_customer->prev = tail;
    }
    else
    {  
        new_customer->next = insert_pos;
        new_customer->prev = insert_pos->prev;
        if (insert_pos->prev != NULL)
        {
            insert_pos->prev->next = new_customer;
        }
        insert_pos->prev = new_customer;
    }
}

int delete_customer(char* name)
{
    struct Customer* cur = head->next;

    while (cur != NULL) {
        if (strcmp(cur->customerName, name) == 0)
        {
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            }
            if (cur->next != NULL)
            {
                cur->next->prev = cur->prev;
            }
            free(cur->customerName);
            free(cur);  
            return 1;  
        }
        cur = cur->next;
    }
    return 0;
}

int modify_customer(char* name, enum Rank new_rank, int new_order_amount, int new_point) {
    struct Customer* cur = head->next;

    while (cur != NULL)
    {
        if (strcmp(cur->customerName, name) == 0) {
            cur->rank = new_rank;
            cur->order_amount = new_order_amount;
            cur->point = new_point;
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

void print_all_customers() {
    struct Customer* cur = head->next;
    printf("-----------------------------------------------------\n");
    printf("�� �̸�   ���   �ֹ���   ����Ʈ\n");
    printf("-----------------------------------------------------\n");

    while (cur != NULL)
    {
        printf("%s %d  %d  %d\n", cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->next;
    }

    printf("-----------------------------------------------------\n");
}

int main() {
    head = (struct Customer*)malloc(sizeof(struct Customer));
    head->prev = NULL;
    head->next = NULL;

    int choice;
    char name[NAME_MAX];
    enum Rank rank;
    int order_amount, point;

    while (1)
    {
        printf("1. �� �߰�\n");
        printf("2. �� ����\n");
        printf("3. �� ����\n");
        printf("4. ��ü ����Ʈ ���\n");
        printf("5. ���α׷� ����\n");

        printf("����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("�� �̸�: ");
            scanf_s("%s", name, NAME_MAX);
            printf("�� ��� (1: GOLD, 2: SILVER, 3: BRONZE): ");
            scanf_s("%d", &rank);
            printf("��ü �ֹ���: ");
            scanf_s("%d", &order_amount);
            printf("����Ʈ: ");
            scanf_s("%d", &point);
            insert_customer(name, (enum Rank)rank, order_amount, point);
            break;
        case 2:
            printf("������ �� �̸�: ");
            scanf_s("%s", name, NAME_MAX);
            if (delete_customer(name)) {
                printf("�� ���� ����\n");
            }
            else {
                printf("���� ã�� �� �����ϴ�\n");
            }
            break;
        case 3:
            printf("������ �� �̸�: ");
            scanf_s("%s", name, NAME_MAX);
            printf("���ο� ��� (1: GOLD, 2: SILVER, 3: BRONZE): ");
            scanf_s("%d", &rank);
            printf("���ο� �ֹ���: ");
            scanf_s("%d", &order_amount);
            printf("���ο� ����Ʈ: ");
            scanf_s("%d", &point);
            if (modify_customer(name, rank, order_amount, point)) {
                printf("�� ���� ���� ����\n");
            }
            else {
                printf("���� ã�� �� �����ϴ�\n");
            }
            break;
        case 4:
            print_all_customers();
            break;
        case 5:
            free(head);
            return 0;
        default:
            printf("�߸��� �����Դϴ�\n");
            break;
        }
    }

    return 0;
}