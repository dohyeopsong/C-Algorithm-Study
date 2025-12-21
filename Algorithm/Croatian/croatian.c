// #include <stdio.h>
// #include <string.h>

// int main(void){
//     // char croatian[8][3] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
//     char str[101];
//     int cnt = 0;
    
//     if(scanf("%s", str) != 1)   return 0;

//     size_t len = strlen(str);

//     // [수정된 뒤로 걷기 코드]
// for(int i = len-1; i >= 0; i--){
//     if(str[i] == '-'){
//         // i가 0보다 클 때만 앞을 본다
//         if(i > 0) i--; 
//     }
//     else if(str[i] == '='){
//         // dz= 검사: i가 2 이상이어야 함
//         if(i >= 2 && str[i-1] == 'z' && str[i-2] == 'd'){
//             i -= 2;
//         }
//         // c=, s=, z= 검사: i가 1 이상이어야 함
//         else if(i > 0) { 
//             i--; 
//         }
//     }
//     else if(str[i] == 'j'){
//         // lj, nj 검사: i가 1 이상이어야 함
//         if(i > 0 && (str[i-1] == 'l' || str[i-1] == 'n')){
//             i--;
//         }
//     }
//     cnt++;

//     printf("%d\n", cnt);

//     return 0;
// }

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[101];
    if (scanf("%s", str) != 1) return 0;

    int cnt = 0;
    // '\0'을 만날 때까지 반복 (strlen을 미리 안 구해도 됨 -> 한 번 더 최적화)
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        
        // 1. 'c=' 또는 'c-'
        if (c == 'c') {
            if (str[i+1] == '=' || str[i+1] == '-') {
                i++; // 다음 글자 건너뜀
            }
        }
        // 2. 'dz=' 또는 'd-'
        else if (c == 'd') {
            if (str[i+1] == '-') {
                i++;
            }
            // dz= 인 경우 (3글자 처리)
            else if (str[i+1] == 'z' && str[i+2] == '=') {
                i += 2; // 두 글자 건너뜀
            }
        }
        // 3. 'lj', 'nj'
        else if (c == 'l' || c == 'n') {
            if (str[i+1] == 'j') {
                i++;
            }
        }
        // 4. 's=', 'z='
        else if (c == 's' || c == 'z') {
            if (str[i+1] == '=') {
                i++;
            }
        }
        
        cnt++; // 무슨 일이 있었든 글자 하나(혹은 크로아티아 글자 하나)로 침
    }

    printf("%d\n", cnt);
    return 0;
}