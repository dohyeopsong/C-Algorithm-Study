#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char **ps);

int main(void){
    char temp[80]; // 임시 char 배열
    char *str[21] = { 0 }; // 동적 할당 영역을 연결할 포인터 배열, 널 포인터로 초기화
    int i = 0; // 반복 제어 변수

    while (i < 20){
        printf("문자열을 입력하세요 : ");
        fgets(temp, sizeof(temp), stdin);           // 문자열 입력
        if(strcmp(temp, "end\n") == 0) break;         // end가 입력되면 반복 종료, Include "\n" because fgets 
        str[i] = (char *)malloc(strlen(temp) + 1);  // 문자열 저장 공간 할당
        strcpy(str[i], temp);                       // 동적 할당 영역에 문자열 복사
        i++;
    }

    print_str(str);                                 // print str

    for(i = 0; str[i] != NULL; i++){                // when not exist linked str
        free(str[i]);                               // return dynamic allocation area
    }
    return 0;
}

void print_str(char **ps){
    while(*ps != NULL){
        printf("%s", *ps);
        ps++;
    }
}