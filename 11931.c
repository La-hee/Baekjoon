#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//qsort를 사용하기 위한 compare함수 세팅
int compare(const void* a, const void* b) {
	//b-a를 기준으로 둬 내림차순 정렬
	return (*(int*)b - *(int*)a);
}

	int main() {
		int n;
		scanf("%d", &n);
		
		//배열의 크기가 정해져있지 않으므로 동적 할당
		int* arr = (int*)malloc(sizeof(int) * n);

		//입력받은 수를 배열에 하나씩 저장
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			arr[i] = num;
		}

		//내림차순 정렬
		qsort(arr, n, sizeof(int), compare);

		//정렬된 배열 출력
		for (int i = 0; i < n; i++) {
			printf("%d \n", arr[i]);
		}
		

	}
