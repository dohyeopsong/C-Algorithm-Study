#include "music_list.h"

int main(void)
{
    char choice[10]; // 넉넉하게 버퍼 확보
    Node *head = NULL;

    while (1)
    {
        printf("\n1.Add  2.Delete  3.Print  4.Clear  5.Exit\n");
        printf("Choose: ");

        if (scanf("%9s", choice) != 1)
            break;
        while (getchar() != '\n')
            ;

        if (strcmp(choice, "1") == 0)
            add_song(&head);
        else if (strcmp(choice, "2") == 0)
            delete_song(&head);
        else if (strcmp(choice, "3") == 0)
            print_all(&head);
        else if (strcmp(choice, "4") == 0)
            clear_all(&head);
        else if (strcmp(choice, "5") == 0)
            break;
        else
            printf("!! Invalid selection !!\n");
    }

    // [수정] 프로그램 종료 전 반드시 메모리 해제
    clear_all(&head);
    printf("Exiting system...\n");
    return 0;
}