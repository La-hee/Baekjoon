#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>


int main() {
	int n;
	scanf("%d", &n);

	int* card = (int*)malloc(2 * n * sizeof(int));

	//card배열 초기화
	for (int i = 0; i < n; i++) {
		card[i] = i+1;
	}

	int front = 0;
	int rear = n;

	//카드가 2장 이상 남아 있을 때만 반복, rear - front =1이나 0일 경우 카드가 한 장 남았거나, 큐가 비어있단 뜻.
	while (rear - front > 1) {
		//맨 윗장의 카드를 버림
		front++;
		//마지막을 늘려서 거기에 윗장의 카드를 보냄 => 카드를 위에서 맨 아래로 보내는 로직
		card[rear++] = card[front];
		front++;
	}

	printf("%d", card[front]);
	free(card);

}


