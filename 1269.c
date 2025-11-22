#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

//오름차순 정렬을 위한 비교 함수
int compare(const void* A, const void* B) {
	return (*(int*)A - *(int*)B);
}

int main(){
	//집합 a의 원소의 개수, b의 원소의 개수
	int n, m;
	scanf("%d %d", &n, &m);
	
	//집합 a, b의 원소를 저장할 배열
	int* A = (int*)malloc(sizeof(int) * n);
	int* B = (int*)malloc(sizeof(int) * m);

	//a 초기화
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	//b 초기화
	for (int i = 0; i < m; i++)
		scanf("%d", &B[i]);

	//a, b오름차순 정렬
	qsort(A, n, sizeof(int), compare);
	qsort(B, m, sizeof(int), compare);

	//투 포인터를 이용한 배열 탐색
	int a = 0; int b = 0;
	int result = 0; // 대칭 차집합의 원소 개수를 저장할 변수 
	while (a < n && b < m) {

		//두 원소가 같다면 a, b동시 증가
		if (A[a] == B[b]) {
			a++;
			b++;
		}

		//A[a] > B[b] => A의 남은 모든 원소가 B[b]보다 크므로 result증가, b 증가
		else if (A[a] > B[b]) {
			b++;
			result++;
		}

		//A[a] < B[b] => B의 남은 모든 원소가 A[a]보다 크므로 result 증가, a 증가
		else if (A[a] < B[b]) {
			a++;
			result++;
		}
	}

	//남은 원소들 역시 대칭 차집합에 포함되므로 result값에 추가해줌
	while (a < n) { a++; result++; }
	while (b < m) { b++; result++; }

	printf("%d", result);
	free(A);
	free(B);

}




