#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	int store[9] = { 0 };
	int many = 0;
	int where = 0;

	scanf("%d", &n);
	
	//자릿수별로 나눠서 저장하는데 6과 9를 합쳐서 하나로 6에 저장(6은 9로, 9는 6으로 사용 가능하므로)
	while (n > 0) {
		int temp = n % 10;
		if (temp == 6 || temp == 9) {
			store[6]++;
		}

		else {
			store[temp]++;
		}
		
		n = n / 10;
	}

	//1개 세트로으로 6, 9를 만들 수 있으니 짝수인 경우 2로 나누고, 홀수인 경우 2로 나눈 것에 1을 더함
	if (store[6] % 2 == 0) {
		store[6] = store[6] / 2;
	}

	else {
		store[6] = store[6] / 2 + 1;
	}

	
	//store배열을 돌면서 가장 많이 필요한 숫자의 개수 = 세트의 개수를 구함.
	for (int i = 0; i < 9; i++) {
		if (store[i] > many) {
			many = store[i];
			where = i;
		}
	}

	printf("%d", many);


}