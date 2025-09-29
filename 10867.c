#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//qsort를 위한 비교 함수. a-b를 이용하므로 오름차순 정렬
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int n;
	int swap;

	scanf("%d", &n);

	//주어지는 입력이 100000개일 때를 위한 동적 할당
	int* arr = (int*)malloc(sizeof(int) * n);

	//배열에 수 할당
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}

	//qsort를 이용한 정렬
	qsort(arr, n, sizeof(int), compare);

	//출력하기
	printf("%d ", arr[0]);

	for (int i = 1; i < n; i++) {
		//만약 이전 수와 현재 수가 같다면 출력하지 않고 건너뜀
		if (arr[i - 1] == arr[i])
			continue;

		printf("%d ", arr[i]);
	}

	free(arr);
}
