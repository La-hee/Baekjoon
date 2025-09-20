#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//각 자리수를 더하는 함수 d(n)
int d(int n) {
	int next = 0;
	next += n;

	while (n > 0) {
		next += n % 10;
		n = n / 10;
	}

	return next;
	
}

int main() {
	int num[10000] = { 0 };
	int start = 1;
	int result;

	//초기 배열에 값 할당하기
	for (int i = 0; i < 10000; i++) {
		num[i] = start;
		start++;
	}

	//d(n)함수의 값으로 나오는 수들의 순서에 해당하는 배열 값을 0으로 만들어 값 제거
	for (int i = 1; i <= 10000; i++) {
		result = d(i);
		if ( result <= 10000)
			num[result - 1] = 0;
	}


	//배열의 값이 0이 아닌 수들만 출력(self number들만 출력)
	for (int i = 0; i < 10000; i++) {
		if (num[i] != 0)
			printf("%d \n", num[i]);
	}


}
