#include "music_list.h"

void add_song(Node **head)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Title of song: ");
    char name[MAX_NAME_LEN + 1];
    // [수정] %s 대신 길이를 제한하여 버퍼 오버플로우 방지
    scanf("%30s", name);
    while (getchar() != '\n')
        ; // 입력 버퍼 비우기

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
    printf("'%s' added successfully.\n", name);
}

void delete_song(Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("Title to delete: ");
    char name[MAX_NAME_LEN + 1];
    scanf("%30s", name);
    while (getchar() != '\n')
        ;

    Node *target = *head;
    Node *pre_node = NULL;

    // [수정] target이 NULL인지 먼저 검사하여 안전성 확보
    while (target != NULL && strcmp(target->song_name, name) != 0)
    {
        pre_node = target;
        target = target->next;
    }

    if (target == NULL)
    {
        printf("Cannot find title: %s\n", name);
        return;
    }

    // 삭제 로직
    if (pre_node == NULL)
    { // 첫 번째 노드인 경우
        *head = target->next;
    }
    else
    {
        pre_node->next = target->next;
    }

    free(target);
    printf("Deleted successfully.\n");
}

void print_all(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *target = *head;
    printf("\n--- Playlist ---\n");
    while (target != NULL)
    {
        printf("- %s\n", target->song_name);
        target = target->next;
    }
    printf("----------------\n");
}

void clear_all(Node **head)
{
    Node *target = *head;
    while (target != NULL)
    {
        Node *next = target->next;
        free(target);
        target = next;
    }
    *head = NULL;
    printf("All nodes cleared.\n");
}