#include <stdio.h>

int main(void){
    int limited;
    int count = 0;

    printf("2 이상의 정수를 입력하세요: ");
    scanf("%d", &limited);

    for( int i = 2; i <= limited; i++){

        int is_prime = 1;

        for(int j = 2; j < i; j++){
            if(i % j == 0){
                is_prime = 0;
                break;
            }
        }

        if(is_prime == 1){//1
            printf("%d ", i);
            count++;

            if(count % 5 == 0){
            printf("\n");
        }
        }
    }
    printf("\n");
    return 0;
}