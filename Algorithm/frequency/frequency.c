// #include <stdio.h>
// #include <string.h> // strlen 사용을 위해 필수
// #include <ctype.h>  // toupper 사용

// int main(void){
//     char str[1000]; // 넉넉한 문자열 공간
//     int counts[26] = {0}; // 알파벳 A~Z의 개수를 셀 사물함 (0으로 초기화 필수!)
    
//     // 1. 입력 받기
//     scanf("%s", str);
    
//     // 2. 문자열 길이 구하기 (sizeof 아님!)
//     int length = strlen(str);

//     // 3. 한 번만 훑으면서 개수 세기 (시스템 개발자의 방식: Direct Mapping)
//     for(int i = 0; i < length; i++){
//         char c = toupper(str[i]); // 대문자로 변환
//         // 핵심 로직: 'A'는 0번방, 'B'는 1번방... 주소 계산
//         // c가 'A'(아스키 65)라면 -> 65 - 65 = 0번 인덱스
//         counts[c - 'A']++; 
//     }

//     // 4. 사물함 26개만 열어보며 1등 찾기
//     int max_count = 0;
//     char answer = '?';

//     for(int i = 0; i < 26; i++){
//         if(counts[i] > max_count){
//             max_count = counts[i];
//             answer = (char)('A' + i); // 0번방이면 'A'로 복구
//         }
//         else if(counts[i] == max_count){
//             answer = '?'; // 동점자 발생
//         }
//     }

//     printf("%c\n", answer);

//     return 0;
// }   

#include <stdio.h>
#include <ctype.h>  // toupper()
#include <string.h> // strlen()

#define ALPHABET_COUNT 26

int main(void) {
    // 1. 메모리 할당: 스택에 넉넉하게 잡거나, 실제론 동적할당을 고려할 수 있음
    char str[1000001]; 
    if (scanf("%s", str) != 1) return 1; // 입력 예외 처리

    // 2. Lookup Table 초기화 (0으로 세팅)
    // 시스템 개발자는 초기화되지 않은 메모리(Garbage Value)를 가장 경계해야 함
    int counts[ALPHABET_COUNT] = {0}; 
    
    // 3. 데이터 처리 (O(N) - 한 번만 훑기)
    // strlen을 반복문 조건에 넣지 않고 변수로 뺌 (매번 길이 계산 방지)
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        // 대소문자 통일 (비트 연산으로 최적화 가능하지만 가독성을 위해 toupper 사용)
        char c = toupper(str[i]);
        
        // 유효성 검사: 알파벳인 경우만 카운팅 (Robustness)
        if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++; // 인덱스로 바로 접근 (Direct Access)
        }
    }

    // 4. 최댓값 찾기 (O(26) - 상수 시간)
    int max_freq = 0;
    char result = '?';
    
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        if (counts[i] > max_freq) {
            max_freq = counts[i];
            result = (char)('A' + i); // 인덱스를 다시 문자로 복원
        } else if (counts[i] == max_freq) {
            result = '?'; // 동점자 처리
        }
    }

    printf("%c", result);

    return 0;
}