#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* num;
int n;

int compare(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int subset(int target) {
	int left = 0;
	int right = n - 1;
	int cnt = 0;

	//투 포인터 알고리즘 사용
	while (left < right) { //오른쪽, 왼쪽이 만나기 전까지 계속 반복함
		int sum = num[left] + num[right];

		//합이 target인 경우 cnt를 올리고 while문을 계속함
		if (sum == target) {
			cnt++;
			//그 값을 찾은 경우 포인터를 둘 다 한 칸씩 옮겨줘야 무한 루프에 빠지지 않음
			left++;
			right--;
		}

		//합이 target보다 작은 경우, 더 큰 수를 더해야 하므로 left를 오른쪽으로 한 칸 이동시킴
		else if (sum < target)
			left++;

		//합이 target보다 큰 경우 더 작은 수를 더해야 하므로 right를 왼쪽으로 한 칸 이동시킴
		else
			right--;
	}

	return cnt;
}

int main() {
	int a, target;
	//수열의 크기를 입력받고 수열을 담을 배열의 크기 조정 및 값을 집어넣음
	scanf("%d", &n);

	num = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}

	scanf("%d", &target);

	//subset함수로 넘기기 전, 배열을 정렬해줌
	qsort(num, n, sizeof(int), compare);
	printf("%d", subset(target));

}