#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int t; //테스트 케이스의 수
	int n, m;

	scanf("%d", &t);

	//테스트 케이스만큼 반복
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		scanf("%d", &m);

		//수가 커서 int 타입에는 안 담기므로, long long타입으로 지정
		long long up = 1;
		long long down = 1;
		long long result;

		//조합 구현
		//n이 1일 경우, 그냥 m출력
		if (n == 1) {
			printf("%d \n", m);
			continue;
		}

		//m=n인 경우 1출력
		if (m == n) {
			printf("1 \n");
			continue;
		}

		//m-n이 기존 n보다 작은 경우, n을 m-n으로 바꿈.(조합의 성질)
		if ((m - n) < n)
			n = m - n;

		//조합 계산 윗부분
		for (int k = m; k > m-n; k--) {
			up = up * k;
		}

		//조합 계산 아랫부분
		for (int k = 1; k <= n; k++) {
			down = down * k;
		}

		//위, 아래를 나눠 결과 출력
		result = up / down;
		printf("%d \n", result);


	}


}