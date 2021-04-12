#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000
#define MaxLine 6

struct StackInfo {
	int Capacity;
	int TopOfStack;
	int *Array;
};

typedef struct StackInfo *Stack;

Stack CreateStack(int Max) {
	Stack S;

	S = malloc(sizeof(struct StackInfo));
	S->Array = malloc(sizeof(int) * Max);
	S->Capacity = Max;
	S->TopOfStack = -1;

	return S;
}

void Push(int X, Stack S) {
	S->Array[++S->TopOfStack] = X;
}

void Pop(Stack S) {
	if(S->TopOfStack == -1)
		printf("%d\n", -1);
	else
		printf("%d\n", S->Array[S->TopOfStack--]);
}

void PrintSize(Stack S) {
	printf("%d\n", S->TopOfStack + 1);
}

void IsEmpty(Stack S) {
	if(S->TopOfStack == -1)
		printf("%d\n", 1);
	else
		printf("%d\n", 0);
}

void PrintTop(Stack S) {
	if(S->TopOfStack == -1)
		printf("%d\n", -1);
	else
		printf("%d\n", S->Array[S->TopOfStack]);
}

int main() {
	int N, i, x;
	char cmdline[MaxLine];
	Stack S;

	S = CreateStack(MAX);

	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%s", cmdline);
		if(!strcmp(cmdline, "push")) {
			scanf("%d", &x);
			Push(x, S);
		}
		else if(!strcmp(cmdline, "pop"))
			Pop(S);
		else if(!strcmp(cmdline, "size"))
			PrintSize(S);
		else if(!strcmp(cmdline, "empty"))
			IsEmpty(S);
		else if(!strcmp(cmdline, "top"))
			PrintTop(S);
		else
			printf("Error: Please enter the valid command!\n");
	}
	return 0;
}
