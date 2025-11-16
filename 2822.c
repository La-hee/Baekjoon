#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int score[8];
int index[8];

//score에 있는 점수들을 내림차순으로 정렬하기 위한 함수
int sort(const void* a, const void* b) {
	int i = *(int *)a;
	int j = *(int*)b;

	return score[j] - score[i];
}

//index배열을 오름차순으로 정렬하기 위한 함수
int order(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int main() {

	int sum = 0;

	//score배열 초기화
	for (int i = 0; i < 8; i++) {
		scanf("%d", &score[i]);
	}

	//index배열 초기화
	for (int i = 0; i < 8; i++) {
		index[i] = i;
	}

	//index를 score 배열의 수를 기준으로 정렬
	qsort(index, 8, sizeof(int), sort);
	
	//가장 높은 점수 5개의합 구하기
	for (int i = 0; i < 5; i++) {
		sum += score[index[i]];
	}

	printf("%d \n", sum);
	
	//문제 번호가 증가하는 순으로 출력하기 위한 index배열 오름차순으로 정렬하기
	qsort(index, 5, sizeof(int), order); //2번째 인수가 정렬할 요소의 갯수므로 5로 지정하면 배열에서 5개의 요소를 정렬하겠단 뜻
	
	//문제 번호 출력
	for (int i = 0; i < 5; i++) {
		printf("%d ", index[i]+1);
	}


}
