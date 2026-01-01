//self reference struct

#include <stdio.h>

struct list{            // 자기 참조 구조체
    int num;            // 데이터를 저장하는 멤버
    struct list *next;  // 구조체 자신을 가리키는 포인터 멤버
};

int main(void){
    struct list a = {10, 0}, b = {20, 0}, c = {30, 0};       // 구조체 변수 초기화
    struct list *head = &a, *current;  // 헤드 포인터 초기화

    a.next = &b;                        // a의 포인터가 b를 가리킴
    b.next = &c;                        // b의 포인터가 c를 가리킴

    printf("head -> num : %d\n", head->num);                 // head가 가리키는 a의 num 멤버 사용
    printf("head -> next -> num : %d\n", head->next->num);   // head로 b의 num 멤버 사용

    printf("list all : ");
    current = head;                            // first current pointer indicate a
    while (current != NULL){                   // finish repeat last structure variable
        printf("%d ", current->num);           // print num of structure vatiable that current point to
        current = current->next;               // make current indicating next structure variable
    }
    printf("\n");

    return 0;
}

