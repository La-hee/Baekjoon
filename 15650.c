#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* result;

void nm(int start,int end,  int m,  int depth) {
	//탈출 조건 : depth가 m과 같아지는 경우
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
		return; //해당 호출을 종료하고 바로 상위 호출로 돌아간다는 뜻
	}

	//백트래킹, 중복 없이 숫자를 골라 오름차순으로 출력함
	for (int i = start; i <= end; i++) {
		result[depth] = i;
		nm(i + 1, end, m, depth + 1);
	}
}

int main() {
	//n, m 문제 조건 입력받기
	int n, m;
	scanf("%d %d", &n, &m);

	result = (int*)malloc(sizeof(int) * m);
	nm(1, n, m, 0);
	free(result);
}