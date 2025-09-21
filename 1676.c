#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num; //입력받을 수
	int check[10000] = { 1 };
	int n = 1; //값이 저장된 위치를 저장하는 변수
	int fact; // 곱셈 계산값을 저장할 변수
	int result = 0; //결과값

	scanf("%d", &num);

	//팩토리얼 구하기, 세로셈 하듯이 계산한다고 생각.
	for (int i = 1; i <= num; i++) { //1부터 num까지 곱하기 위해, for사용
		int carry = 0; //계속 초기화되어야 하므로 for루프 안에 넣음

		for (int k = 0; k < n; k++) { //배열에 저장된 값에 하나하나 곱셈을 수행함
			fact = check[k] * i + carry; //각 자리수별 계산
			check[k] = fact % 10; //배열에 저장하는 값은 한 자리수.
			carry = fact / 10; //나머지를 carry로 올림
		}

		while (carry) { //carry의 값이 12, 23같은 여러 자리 수일 수 있으므로 while루프 사용
			check[n] = carry % 10; //carry값을 저장함으로써 배열 확장
			carry = carry / 10;
			n++;
		}
	}
	
	//0이 얼마나 나오는지 확인
	for (int i = 0; i < n; i++) {
		if (check[i] == 0) //0일 경우 result++을 하고 계속 루프 진행
			result++;
		else //0이 아닐 경우 루프 탈출
			break;
	}

	//결과 출력
	printf("%d", result);


}