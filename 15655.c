#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* num;
int* result;
int n, m;

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

void nm(int start, int depth) {
	//준비된 배열에 숫자가 다 차면 그대로 출력
	if (depth == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", result[i]);
		printf("\n");
		return;
	}

	//배열을 돌려 수열 찾기
	for (int i = start; i < n; i++) {
			result[depth] = num[i]; //depth자리에 숫자를 집어넣음
			//재귀호출을 통해 뒷자리에 어떤 수를 넣을지 결정! start인자를 증가시켜서 중복으로 뽑는 경우 방지
			nm(i + 1, depth + 1); 
	}
	
	

}

int main() {
	//n, m 입력받고 배열 초기화
	scanf("%d %d", &n, &m);
	num = (int*)malloc(sizeof(int) * n);
	
	//배열에 수열을 담아 초기화
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	//오름차순을 위한 qsort함수를 이용한 정렬
	qsort(num, n, sizeof(int), compare);
	result = (int*)malloc(sizeof(int) * m);

	nm(0, 0);
	free(num);
	free(result);
}