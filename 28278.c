#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int stack[10000000];
int top = -1;

void push(int many) {
stack[++top] = many;
}

int pop() {
return stack[top--];
}

int what() {
return stack[top];
}


int main() {
char input[100];
int command;
int many;
int arg;

int n;
scanf("%d", &n);
//scanf의 개행문자 제거
getchar();

for (int i = 0; i < n; i++) {
//입력을 받아 공백 기준으로 명령어를 나눔
fgets(input, sizeof(input), stdin);
arg = sscanf(input, "%d %d", &command, &many);

//명령어 개수에 따른 처리, 1번 push 연산
if (arg == 2) {
push(many);
}

else if (arg == 1) {
//2번 스택에 정수가 존재할 경우 맨 위의 정수를 빼고 출력. 전형적인 pop()
if (command == 2) {
if (top == -1)
printf("-1\n");
else
printf("%d\n", pop());
}

//3번, 스택에 들어있는 정수 개수 출력
else if (command == 3)
//top이 -1부터 시작하므로 개수는 +1을 해줘야 함
printf("%d\n", top+1);

//4번 스택이 비어있는지 확인
else if (command == 4) {
if (top == -1)
printf("1\n");

else
printf("0\n");
}

//5번, 스택에 정수가 있다면 맨 위의 정수 출력
else if (command == 5) {
if (top == -1)
printf("-1\n");
else
printf("%d\n", what());
}

}

}


}