#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//퀵정렬의 기준을 설정하기 위한 함수
int compare(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);
}

int main() {
	int num;
	int temp;
	
	scanf("%d", &num);

	//입력받을 수 있는 수의 범위가 매우 크므로 malloc을 통한 동적 할당
	int* sort = (int*)malloc(sizeof(int) * num);

	//혹시 모를 오류 발생을 위한 보험
	if (sort == NULL) {
		printf("오류");
		return 1;
	}

	for (int i = 0; i < num; i++) {
		scanf("%d", &sort[i]);
	}

	//c에서 제공하는 정렬 알고리즘 이용
	qsort(sort, num, sizeof(num), compare);

	//정렬된 수 출력
	for (int k = 0; k < num; k++) {
		printf("%d \n", sort[k]);
	}

	//메모리 할당 해제
	free(sort);
}
