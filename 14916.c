#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int charge(int n) {
	int two;
	int many;

	//5원을 최대 가능한 개수부터 시작해 최소 0개까지 거슬러주는 모든 경우의 수 고려 
	for (int i = n / 5; i >= 0; i--) {

		//5원을 거슬러주고 남은 금액
		 many = n - (5 * i);

		 //만약 many가 2로 나누어 떨어지면 two+i을 리턴
		if (many % 2 == 0) {
			two = many / 2;
			return two + i;
		}
	}
	//for문을 다 돌았음에도 가능한 경우를 찾지 못한 경우, -1리턴
	return -1;

}



int main() {
	int n;

	scanf("%d", &n);
	printf("%d", charge(n));
}