#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int stack[1000000];
int top = -1;

void push(int many) {
	if (top < 1000000 - 1)
		stack[++top] = many;
}

int pop() {
	//스택이 비어 있는 경우 -1리턴
	if (top == -1)
		return -1;

	else {
		int value = stack[top];
		top--;

		return value;
	}
}


int main() {
	char input[100];
	char command[10];
	int many;
	int arg;

	//주어지는 명령의 수 입력받음
	int n;
	scanf("%d", &n);
	getchar(); //줄바꿈 문자 \n 제거

	for (int i = 0; i < n; i++) {
		fgets(input, sizeof(input), stdin);

		//입력을 명령어와 숫자로 분리함
		arg = sscanf(input, "%s %d", command, &many);

		//숫자도 같이 들어온 경우 = push
		if (arg == 2) {
			push(many);
		}

		//나머지 경우
		else {
			//pop
			if (strcmp(command, "pop") == 0) {
				printf("%d\n", pop());
			}

			//size, 스택에 들어있는 정수의 개수 출력
			else if (strcmp(command, "size") == 0) {
				printf("%d\n", top+1);
			}

			//empty, 스택이 비어있으면 1, 아니면 0 출력
			else if (strcmp(command, "empty") == 0) {
				if (top == -1)
					printf("1\n");

				else
					printf("0\n");
			}

			//top, 스택에 가장 위에 있는 정수 출력. 만약 스택에 정수가 없다면 -1출력
			else if (strcmp(command, "top") == 0) {
				if (top == -1)
					printf("-1\n");

				else
					printf("%d\n", stack[top]);
			}

		}

	}
}


