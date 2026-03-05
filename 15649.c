#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* result;
int* check;

void num(int end, int m, int depth) {

	//탈출 조건, 배열에 값이 다 채워지는 경우, 배열의 값을 출력하고 넘어감
	if (depth == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", result[i]);

		printf("\n");
		return;
	}

	for (int i = 1; i <= end; i++) {
		//숫자가 이미 사용된 건지 안 된 건지 확인
		if (!check[i]) { //사용이 안 됐을 경우
			result[depth] = i;
			check[i] = 1;
			num(end, m, depth + 1);

			//백트래킹으로 사용 후 다시 초기화
			check[i] = 0;
		}
	}

	}


int main() {
	int n;
	int m;

	//n, m을 입력받음
	scanf("%d %d", &n, &m);

	//재귀함수를 통해 그 내용을 채울 배열
	result = (int*)malloc(sizeof(int) * m);

	//해당 숫자가 쓰였는지 안 쓰였는지 확인하기 위한 배열 및 초기화(0: 미사용, 1: 사용)
	check = (int*)malloc(sizeof(int) * (n+1));
	for (int i = 0; i <= n; i++)
		check[i] = 0;

	num( n, m, 0);

}