#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* time;
int* pay;

int dp(int n) {
	int* result = (int*)malloc(sizeof(int) * (n+2)); //최대 pay를 담을 배열
	//result배열 초기화
	for (int i = 0; i <= n+1; i++) {
		result[i] = 0;
	}

	for (int i = n; i >= 1; i--) {
		int next = i + time[i];

		//상담이 끝나는 날짜가 퇴사일을 넘어서지 않는 경우만 가능하므로 확인.
		if (next <= n+1) { //퇴사 하루 전에도 상담을 받을 수 있는 경우 고려
			if (result[next] + pay[i] > result[i+1]) //상담을 진행했을 때 얻을 수 있는 금액이 상담을 하지 않았을 때의 값보다 큰 경우
				result[i] = result[next] + pay[i]; //이 날짜의 상담을 진행했을 때, 얻을 수 있는 금액을 저장함

			else
				result[i] = result[i + 1]; //그렇지 않은 경우, 다음 날의 상담을 진행하므로 다음 날의 결과를 가져옴
		}

		else
			result[i] = result[i + 1]; //날짜를 넘어가서 상담을 못하는 경우, 다음날의 결과를 가져와야 함
	}

	int last = result[1];
	free(result);
	return last;


}

int main() {
	int n;
	scanf("%d", &n);

	//배열 세팅 및 초기화, 1부터 시작하기 위해 범위를 넉넉하게 잡음
	time = (int*)malloc(sizeof(int) * (n+2)); //퇴사 하루 전에도 상담을 하는 경우가 있으므로 이를 고려해 크기 할당
	pay = (int*)malloc(sizeof(int) * (n+1));

	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &time[i], &pay[i]);
	}

	printf("%d", dp(n));
	free(time);
	free(pay);

}