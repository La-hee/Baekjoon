#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

//큐
int queue[100000];
int front = -1;
int back = -1;

//push연산, back을 증가시키고 삽입
void push(int many) {
	queue[++back] = many;
}

//pop연산, front를 증가시키고 출력
int pop() {
	if (front == back)
		return -1;
	else 
		return queue[++front];
}

int main() {
	char input[100]; //전체 문자열 입력 버퍼
	char command[10]; // 명령어 저장
	int many; // 명령과 함께 들어오는 숫자 저장
	int arg; // sccanf로 입력받은 항목 갯수

	int n;
	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++) {
		fgets(input, sizeof(input), stdin);
		arg = sscanf(input, "%s %d", command, &many);

		//push명령어 구현
		if (arg == 2) {
			push(many);
		}

		else {
			//pop 명령어 구현
			if (strcmp(command, "pop") == 0) {
				printf("%d\n", pop());
			}

			//size 명령어 구현
			if (strcmp(command, "size") == 0) {
				printf("%d\n", back - front);
			}

			//empty 명령어 구현
			if (strcmp(command, "empty") == 0) {
				if (front == back)
					printf("1\n");
				else
					printf("0\n");
			}

			//front 명령어 구현
			if (strcmp(command, "front") == 0) {
				if (front == back)
					printf("-1\n");
				else
					printf("%d\n", queue[front+1]);
			}

			//back 명령어 구현
			if (strcmp(command, "back") == 0) {
				if (front == back)
					printf("-1\n");
				else
					printf("%d\n", queue[back]);
			}
		}


	}

}