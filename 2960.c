#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int k;
	scanf("%d %d", &n, &k);
	int* prime = (int*)malloc((n+1) * sizeof(int));

	//prime배열 초기화
	//배열을 2부터 사용할 것이므로, prime[0], prime[i]은 따로 초기화를 해줘야 함
	prime[0] = 0;
	prime[1] = 0;

	for (int i = 2; i <= n; i++) {
		prime[i] = i;
	}

	int result = 0;

	while (1) {
		int remove = 0;

		//아직 지우지 않은 수 중 가장 작은 수 찾기
		for (int i = 2; i <= n; i++) {
			if (prime[i] != 0) {
				remove = prime[i];
				break;
			}
		}

		//지울 수가 없을 경우, 루프 탈출
		if (remove == 0) break;

		//수 지우기
		for (int i = remove; i <= n; i++) {
			//prime[i]가 0이 아니고, 지울 수로 나눠 떨어질 경우
			if ((prime[i] != 0) && (i % remove == 0)) {
				//result를 증가시킨 값이 k와 일치할 땐 출력하고 return으로 함수 종료.
				if (++result == k) {
					printf("%d", prime[i]);
					return 0;
				}
				//일치하지 않을 경우에는 prime[i]를 0으로 바꿔줌
				else 
					prime[i] = 0;
			}
		}

	}

	free(prime);

}




