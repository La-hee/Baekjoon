#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int sum(int num) {
	int* dp;
	dp = (int*)malloc(sizeof(int) * (num+1));

	//base case. 1,2,3의 합으로 나타낼 것이기 때문에 초기 케이스를 1, 2, 3으로 잡아줌
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	if (num == 1) {
		return 1;
	}

	if (num == 2) {
		return 2;
	}

	if (num == 3) {
		return 4;
	}

	//점화식, 작은 수부터 차례대로 값을 구해서 목표 숫자의 방법의 수를 구함
	for (int i = 4; i <= num; i++) {
		//마지막에 1을 더해주는 경우, 2를 더해주는 경우, 3을 더해주는 경우의 수를 더함
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return dp[num];
}

int main() {
	int t; //test case
	scanf("%d", &t);

	int n;
	//목표 숫자를 입력 받고 dp를 이용한 함수를 돌림
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%d \n", sum(n));
	}
}