#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, j;
    printf("양수 입력 : ");
    if (scanf("%d", &n) != 1 || n < 2) return 1;

    // 1. 필요한 행(rows) 계산 (5열 기준)
    int rows = (n / 5) + 1;

    // 2. 행 관리자 할당 (int* 가 들어갈 공간임을 명시!)
    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) return 1;

    // 3. 각 행 할당
    for (i = 0; i < rows; i++) {
        arr[i] = (int *)calloc(5, sizeof(int)); // 0으로 초기화
        if (arr[i] == NULL) return 1;
    }

    // 4. 소수 계산 및 저장
    int count = 0;
    for (i = 2; i <= n; i++) {
        int is_prime = 1;
        for (j = 2; j * j <= i; j++) { // 최적화: 루트 i까지만 검사
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        int r = count / 5;
        int c = count % 5;
        
        if (is_prime) arr[r][c] = i;  // 소수면 숫자 저장
        else arr[r][c] = 0;          // 아니면 0 저장 (X 대신)
        
        count++;
    }

    // 5. 출력
    for (i = 0; i < count; i++) {
        int val = arr[i / 5][i % 5];
        if (val == 0) printf("  X ");
        else printf("%3d ", val);
        if ((i + 1) % 5 == 0) printf("\n");
    }

    // 6. 반환 (자식 -> 부모 순서!)
    for (i = 0; i < rows; i++) free(arr[i]);
    free(arr);

    return 0;
}