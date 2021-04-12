#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

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
		printf("Error: Stack is empty!\n");
	else
		S->TopOfStack--;
}

int main() {
	int K, i, x, sum = 0;
	Stack S;
	S = CreateStack(MAX);

	scanf("%d", &K);
	for(i = 0; i < K; i++) {
		scanf("%d", &x);
		if(x)
			Push(x, S);
		else
			Pop(S);
	}

	for(i = 0; i <= S->TopOfStack; i++) {
		sum += S->Array[i];
	}
	printf("%d\n", sum);

	return 0;
}
