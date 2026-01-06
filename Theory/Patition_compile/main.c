#include <stdio.h>
#include "my_functions.h" // 만든 헤더 파일 포함

int main(void) {
    int a, b;
    double avg;

    input_data(&a, &b);
    avg = average(a, b);
    printf("average of %d and %d : %.1f\n", a, b, avg);

    return 0;
}