// #include <stdio.h>

// int main(void){
//     int n, min, max;
    
//     scanf("%d", &n);
    
//     int ary[n];
    
//     for(int i = 0; i < n; i++){
//         scanf("%d", &ary[i]);

//         if(i == 0){
//             min = ary[0];
//             max = ary[0];
//             continue;
//         }

//         if(ary[i] > max){
//             max = ary[i];
//         }

//         if(ary[i] < min){
//             min = ary[i];
//         }
//     }

//     printf("%d %d\n", min, max);

//     return 0;

// }

//최적화
#include <stdio.h>

int main(void) {
    int n;
    int current;   // 배열 대신 현재 숫자 하나만 담을 그릇
    int min, max;

    // 1. 입력 검증 (Defensive Coding)
    // scanf가 숫자를 제대로 못 받았거나, n이 1보다 작으면 프로그램을 종료합니다.
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("유효하지 않은 입력입니다.\n");
        return 1; // 에러 코드 반환 (OS에게 "나 문제 있어서 꺼졌어"라고 알림)
    }

    // 2. 첫 번째 숫자는 따로 처리 (초기화)
    // 루프 안에서 매번 if(i==0)을 검사하는 것보다, 밖에서 한 번 처리하는 게 CPU 성능상 이득입니다.
    scanf("%d", &current);
    min = current;
    max = current;

    // 3. 나머지 n-1개만 반복 (Streaming 방식)
    for (int i = 1; i < n; i++) {
        scanf("%d", &current); // 배열에 저장 안 하고 current에 덮어씁니다.

        if (current > max) {
            max = current;
        }
        // else if를 쓰지 않는 이유: 같은 숫자일 수도 있으니 각각 체크하거나
        // 여기서는 독립적이므로 if 두 개가 맞습니다. (최적화를 위해선 else if 가능)
        if (current < min) {
            min = current;
        }
    }

    printf("%d %d\n", min, max);

    return 0; // 정상 종료
}