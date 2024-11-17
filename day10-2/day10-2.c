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
        // 고객 등급이 낮을수록 우선순위가 높음 > 그다음 주문량 클수록 > 그다음 포인트 많을수록
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
    printf("고객 이름   등급   주문량   포인트\n");
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
        printf("1. 고객 추가\n");
        printf("2. 고객 삭제\n");
        printf("3. 고객 수정\n");
        printf("4. 전체 리스트 출력\n");
        printf("5. 프로그램 종료\n");

        printf("선택: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("고객 이름: ");
            scanf_s("%s", name, NAME_MAX);
            printf("고객 등급 (1: GOLD, 2: SILVER, 3: BRONZE): ");
            scanf_s("%d", &rank);
            printf("전체 주문량: ");
            scanf_s("%d", &order_amount);
            printf("포인트: ");
            scanf_s("%d", &point);
            insert_customer(name, (enum Rank)rank, order_amount, point);
            break;
        case 2:
            printf("삭제할 고객 이름: ");
            scanf_s("%s", name, NAME_MAX);
            if (delete_customer(name)) {
                printf("고객 삭제 성공\n");
            }
            else {
                printf("고객을 찾을 수 없습니다\n");
            }
            break;
        case 3:
            printf("수정할 고객 이름: ");
            scanf_s("%s", name, NAME_MAX);
            printf("새로운 등급 (1: GOLD, 2: SILVER, 3: BRONZE): ");
            scanf_s("%d", &rank);
            printf("새로운 주문량: ");
            scanf_s("%d", &order_amount);
            printf("새로운 포인트: ");
            scanf_s("%d", &point);
            if (modify_customer(name, rank, order_amount, point)) {
                printf("고객 정보 수정 성공\n");
            }
            else {
                printf("고객을 찾을 수 없습니다\n");
            }
            break;
        case 4:
            print_all_customers();
            break;
        case 5:
            free(head);
            return 0;
        default:
            printf("잘못된 선택입니다\n");
            break;
        }
    }

    return 0;
}