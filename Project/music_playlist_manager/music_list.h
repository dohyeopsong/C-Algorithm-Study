#ifndef MUSIC_LIST_H
#define MUSIC_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [수정] 매직 넘버 제거: 이름 길이를 상수로 관리
#define MAX_NAME_LEN 30

typedef struct node
{
    char song_name[MAX_NAME_LEN + 1]; // 널 문자를 고려해 +1
    struct node *next;
} Node;

// 함수 선언
void add_song(Node **head);
void delete_song(Node **head);
void print_all(Node **head);
void clear_all(Node **head);

#endif