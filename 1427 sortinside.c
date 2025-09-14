#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int num;
    int i = 0;
    int temp;
    int save[10] = { 0 };


    scanf("%d", &num);

    //입력한 수를 분해해서 배열에 저장
    while (num > 0) {
        save[i] = num % 10;
        num = num / 10;
        i++;
    }

    //버블정렬, i-1까지로 범위를 제한해야 인덱스 초과 접근이 발생하지 않음
    for (int k = 0; k < i-1; k++) {

        //이미 정렬된 부분은 다시 정렬할 필요가 없으므로 i-k-1
        for (int j = 0; j < i-k-1; j++) {
            if (save[j] < save[j + 1]) {
                temp = save[j];
                save[j] = save[j + 1];
                save[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < i; k++) {
        printf("%d", save[k]);
    }


}