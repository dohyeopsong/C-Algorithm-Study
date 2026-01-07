#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
add_song(char *name): 노래를 리스트의 맨 뒤에 추가 (malloc 필수).

delete_song(char *name): 특정 노래를 찾아서 삭제하고, 끊어진 기차를 다시 연결 (free 필수, 포인터 연결 바꾸기).

print_all(): 첫 노래부터 끝까지 순회하며 출력.

clear_all(): 프로그램 종료 전 모든 노드 free (메모리 누수 방지).
*/
typedef struct node
{
    char song_name[30];
    struct node *next; // 다음 노래를 가리키는 포인터
} Node;

void add_song(Node **head);
void delete_song(Node **head);
void print_all(Node **head);
void clear_all(Node **head);

int main(void)
{
    char function[2] = "";
    Node list[5];
    Node *head = NULL;

    while (strcmp(function, "5") != 0)
    {
        printf("choose number : 1.add  2.delete  3.print all  4.clear all  5.end\n");
        scanf("%1s", function);
        while (getchar() != '\n')
            ;

        if (strcmp(function, "1") == 0)
        {
            add_song(&head);
        }
        else if (strcmp(function, "2") == 0)
        {
            delete_song(&head);
        }
        else if (strcmp(function, "3") == 0)
        {
            print_all(&head);
        }
        else if (strcmp(function, "4") == 0)
        {
            clear_all(&head);
        }
        else if (strcmp(function, "5") != 0)
        {
            printf("!!choose number!!\n");
        }
    }
    printf("logout...\n");
    return 0;
}

void add_song(Node **head)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
        return;
    printf("title of song : ");
    char name[31];
    scanf("%30s", name);
    strcpy(new_node->song_name, name);
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *target = *head;
        while (target->next != NULL)
        {
            target = target->next;
        }
        target->next = new_node;
    }
}

void delete_song(Node **head)
{
    if (*head == NULL)
    {
        printf("any song exist.\n");
        return;
    }

    printf("title of song : ");
    char name[31];
    scanf("%30s", name);

    Node *target = *head;
    Node *pre_node = NULL;

    while (strcmp(target->song_name, name) != 0)
    {
        if (target->next == NULL)
        {
            printf("cannot find title.\n");
            return;
        }
        else
        {
            pre_node = target;
            target = target->next;
        }
    }
    if (target != *head)
    {
        pre_node->next = target->next;
    }
    else
    {
        *head = target->next;
    }
    free(target);
}

void print_all(Node **head)
{
    if (*head == NULL)
    {
        printf("any song exist.\n");
        return;
    }

    Node *target = *head;

    while (target != NULL)
    {
        printf("%s\n", target->song_name);
        target = target->next;
    }
}

void clear_all(Node **head)
{
    if (*head == NULL)
    {
        printf("any song exist.\n");
        return;
    }

    Node *target = *head;
    Node *pre_node = target;

    while (target != NULL)
    {
        target = target->next;
        free(pre_node);
        pre_node = target;
    }

    *head = NULL;
}