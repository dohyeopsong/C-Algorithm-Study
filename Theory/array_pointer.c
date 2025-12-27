#include <stdio.h> // 이거 빠지면 안 됩니다!
#include <string.h> // strlen 사용 시 필요 (선택 사항)

/*
//배열명에 정수 연산을 수행해 배열 요소 사용
int main(void){
    int ary[3];
    int i;

    *(ary + 0) = 10; //ary[0] = 10
    *(ary +1) = *(ary + 0) + 10; //ary[1] = ary[0] + 10

    printf("세 번째 배열 요소에 키보드 입력 : ");
    scanf("%d", ary + 2); //&ary[2]

    for (i = 0; i < 3; i++){
        printf("%5d\n", *(ary + i)); //ary[i]
    }

    return 0;
}
*/

//배열명처럼 사용되는 포인터
/*
int main(void){
    int ary[3];
    int *pa = ary;
    int i;

    *pa = 10;
    *(pa + 1) = 20;
    pa[2] = pa[0] + pa[1];

    for(i = 0; i < 3; i++){
        printf("%5d\n", pa[i]);
    }

    return 0;
}
*/

/*
//배열에 값을 입력하는 함수
void input_ary(double *pa, int size);
double find_max(double *pa, int size);

int main(void){
    double ary[5];
    double max;
    int size = sizeof(ary) / sizeof(ary[0]);

    input_ary(ary, size);
    max = find_max(ary, size);
    printf("배열의 최댓값 : %.1lf\n", max);

    return 0;
}

void input_ary(double *pa, int size){
    int i;

    printf("%d개의 실수값 입력: ", size);
    for(i = 0; i < size; i++){
        scanf("%lf", pa + i);
    }
}

double find_max(double *pa, int size){
    double max;
    int i;

    max = pa[0];
    for(i = 1; i< size; i++){
        if(pa[i] > max) max = pa[i];
    }

    return max;
}
*/

/*
int main(void){
    int num, grade;

    printf("학번 입력 : ");
    scanf("%d", &num);
    getchar(); //while(getchar() != '\n')
    printf("학점 입력 :");
    grade = getchar();
    printf("학번 : %d, 학점 : %c", num, grade);
    printf("\n");

    return 0;
}
*/

//real practice challenge
/* 입력문자열 문자 개수
int main(void){
    int max = 0;
    int current_cnt = 0;
    int ch; // getchar의 반환형은 int입니다 (EOF 처리를 위해)

    // 1. 글자를 하나씩 Stream에서 가져온다. (Fetch)
    while((ch = getchar()) != EOF){
        
        // 2. 만약 개행문자(Enter)라면? -> 단어가 끝난 것 (End of Word)
        if(ch == '\n'){
            // 현재까지 센 길이가 max보다 큰지 Update
            if(current_cnt > max){
                max = current_cnt;
            }
            // 다음 단어를 위해 카운터 Reset
            current_cnt = 0; 
        }
        // 3. 일반 문자라면? -> 길이 증가 (Counting)
        else {
            current_cnt++;
        }
    }

    // Edge Case 처리: 파일 끝(EOF)에 도달했을 때, 마지막 단어 처리
    if(current_cnt > max){
        max = current_cnt;
    }

    printf("가장 긴 단어의 길이 : %d\n", max);

    return 0;
}
*/

//입력한 단어 길이가 5자를 넘는 경우 6자부터 별(*) 출력

// 함수 원형 선언
/*
int check_limit(const char *str);
void change_str(char *str); // 반환값이 안 쓰이므로 void로 변경

int main(void){
    char str[20]; // 불필요한 new_str 제거
    
    printf("단어 입력 : ");
    // [Safety] 버퍼 오버플로우 방지 (최대 19글자)
    if (scanf("%19s", str) != 1) return 1; 

    printf("입력한 단어 : %s\n", str); // 가독성을 위해 개행(\n) 추가

    if(check_limit(str)){
        change_str(str);
        // "생략한" 보다는 "변형된"이 문맥상 자연스러움
        printf("수정한 단어 : %s\n", str); 
    } else {
        printf("수정 불필요 (5글자 이하)\n");
    }

    return 0;
}

int check_limit(const char *str){
    // [Optimization] 굳이 끝까지 셀 필요 없음. 
    // strlen(str) > 5 로 대체해도 되지만, 직접 구현한다면:
    
    int limit = 5;
    int cnt = 0;
    
    while (*str != '\0'){
        cnt++;
        str++;
        // 5글자 넘는 순간 바로 True 반환 (조기 종료)
        if(cnt > limit) return 1; 
    }
    return 0;
}

// 굳이 포인터를 리턴할 필요가 없어서 void로 바꿈
void change_str(char *str){
    // [Pointer Arithmetic] 5칸 점프! 아주 좋습니다.
    str += 5; 
    
    while(*str != '\0'){
        *str = '*';
        str++;
    }
}
*/

//1차원 배열을 2차원 배열처럼 사용될떄 
/*
int main(void){
    int ary1[4] = {1, 2, 3, 4}; //요소4개 이므로 가비지값
    int ary2[5] = {5, 6, 7, 8}; //요소5개 이므로 뒤에 0 자동 추가
    int ary3[5] = {9, 10, 11, 12, 13};

    int *pary[3] = {ary1, ary2, ary3};
    int i, j;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 5; j++){
            printf("%5d", pary[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/

#include <stdio.h>

int main(void){
    // [Data Segment] 
    // 마지막 행(index 4)과 마지막 열(index 5)은 합계를 위해 비워둠
    // 명시적으로 0을 채우지 않아도 {} 초기화 덕분에 0이 되지만,
    // 로직의 안전성을 위해 아래에서 초기화를 고려하는 게 좋음.
    int ary[5][6] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    int sum_row;
    // ary[4]는 '세로 합'이 저장될 마지막 행의 시작 주소
    int *ptr_col_sum = ary[4]; 
    int sum_all = 0;
    int i, j;

    // [Safety First] 누적 연산을 위해 마지막 행(세로 합 저장소)을 0으로 명시적 초기화
    // 시스템 개발자는 '자동 초기화'를 믿지 않습니다.
    for(j=0; j<5; j++) {
        *(ptr_col_sum + j) = 0;
    }

    for (i = 0; i < 4; i++){
        sum_row = 0;    // [Reset] 행 합계 초기화
        for (j = 0; j < 5; j++){
            // 1. 전체 합계 누적
            sum_all += ary[i][j];   
            
            // 2. 가로(Row) 합계 누적
            sum_row += ary[i][j];   
            
            // 3. 세로(Column) 합계 누적 (포인터 연산 사용)
            // ary[4][j] += ary[i][j] 와 동일
            *(ptr_col_sum + j) += ary[i][j]; 
        }
        // 계산된 가로 합을 마지막 열(5번 인덱스)에 저장
        ary[i][5] = sum_row; 
    }

    // 전체 합을 우측 하단(4, 5)에 저장
    ary[4][5] = sum_all;

    // [Output] 결과 출력 (Alignment 적용)
    printf("Result Table:\n");
    for (i = 0; i < 5; i++){
        for (j = 0; j < 6; j++){
            // %4d: 4칸을 확보하고 오른쪽 정렬 (줄 맞춤)
            printf("%4d", ary[i][j]); 
        }
        printf("\n");
    }

    return 0;
}
