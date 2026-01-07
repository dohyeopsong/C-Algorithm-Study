#include <stdio.h>
#include <stdlib.h>
#include <string.h> // [FIX 1] 문자열 함수 헤더 추가

#define ATTEND      (1 << 0)
#define HOMEWORK    (1 << 1)
#define EXAM        (1 << 2)

struct student {
    char name[20];
    char grade;
    unsigned int status; // int로 명확히
};

void change_status(char *status, struct student *profile, int i);

int main(void) {
    char name_buffer[21];
    char status_buffer[20] = { 0 }; // 크기 넉넉하게
    int n_st;

    printf("How many students will enroll? : ");
    if (scanf("%d", &n_st) != 1) return 1; // [FIX 2] scanf로 변경 및 에러 체크
    
    // [FIX 3] 버퍼 비우기 (중요!)
    // scanf 뒤에 남은 \n을 제거해야 다음 fgets가 정상 작동함
    while (getchar() != '\n'); 

    struct student *profile;
    profile = (struct student *)malloc(sizeof(struct student) * n_st);
    if (profile == NULL) return 1; // 메모리 할당 실패 방어

    // [FIX 4] 파일은 루프 밖에서 한 번만 열거나, 안에서 "a" 모드로 열어야 함
    // 효율성을 위해 밖에서 엽니다.
    FILE *grade_data = fopen("grade_data.txt", "w");
    if (grade_data == NULL) {
        printf("cannot open file\n");
        free(profile); // 종료 전 해제
        return 1;
    }

    for (int i = 0; i < n_st; i++) {
        // 1. 이름 입력
        printf("Name of student %d: ", i + 1);
        if (fgets(name_buffer, sizeof(name_buffer), stdin) == NULL) break;
        name_buffer[strcspn(name_buffer, "\n")] = '\0';
        strcpy((profile + i)->name, name_buffer);

        // 2. 학점 입력
        printf("Grade: ");
        (profile + i)->grade = fgetc(stdin);
        while (getchar() != '\n'); // [FIX 3] fgetc 뒤 엔터 제거

        // 3. 상태 입력
        (profile + i)->status = 0; // 초기화
        while (1) {
            // [FIX 5] 쌍따옴표 사용, 안내 메시지 수정
            printf("Enter status (attend/homework/exam) or 'end' to finish: ");
            fgets(status_buffer, sizeof(status_buffer), stdin);
            status_buffer[strcspn(status_buffer, "\n")] = '\0';

            if (strcmp(status_buffer, "end") == 0) break; // 종료 조건
            change_status(status_buffer, profile, i);
        }

        // 4. 상태 문자열 만들기 (비트 플래그 확인)
        // [FIX 6] 여러 상태를 누적해서 보여주기 위해 문자열 연결 방식 사용
        char status_str[50] = ""; 
        
        // else if가 아니라 각각 if로 검사해야 모든 상태 표시 가능
        if ((profile + i)->status & ATTEND) strcat(status_str, "ATTEND ");
        if ((profile + i)->status & HOMEWORK) strcat(status_str, "HOMEWORK ");
        if ((profile + i)->status & EXAM) strcat(status_str, "EXAM ");

        // 5. 파일 출력
        // [FIX 7] status_str은 문자열이므로 %s 사용
        fprintf(grade_data, "%-20s %-5c %-25s\n", (profile + i)->name, (profile + i)->grade, status_str);
    } // for loop end

    fclose(grade_data);
    
    // [FIX 8] 동적 할당 메모리 해제 (필수!)
    free(profile);
    profile = NULL;

    printf("Data saved to grade_data.txt\n");
    return 0;
}

void change_status(char *status, struct student *profile, int i) {
    // 문자열 비교는 대소문자 정확해야 함
    if (strcmp(status, "attend") == 0) (profile + i)->status |= ATTEND;
    else if (strcmp(status, "homework") == 0) (profile + i)->status |= HOMEWORK;
    else if (strcmp(status, "exam") == 0) (profile + i)->status |= EXAM;
}