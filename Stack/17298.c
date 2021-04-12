#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

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

int Pop(Stack S) {
	if(S->TopOfStack == -1)
		return -1;
	else
		return S->Array[S->TopOfStack--];
}

int Top(Stack S) {
	if(S->TopOfStack == -1)
		return -1;
	else
		return S->Array[S->TopOfStack];
}

int IsEmpty(Stack S) {
	if(S->TopOfStack == -1)
		return 1;
	else
		return 0;
}

void DeleteStack(Stack S) {
	free(S->Array);
	free(S);
}

int main() {
	int N, i, x, NGE[MAX];
	Stack Sin, Sa, Sb;
	Sin = CreateStack(MAX);
	Sa = CreateStack(MAX);
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &x);
		Push(x, Sin);
	}

	NGE[N-1] = -1;
	Push(Pop(Sin), Sa);
	for(i = N-2; i >= 0; i--) {
		NGE[i] = -1;
		while(!IsEmpty(Sa)) {
			if(Top(Sin) >= Top(Sa)) {
				Pop(Sa);
				continue;
			}
			else if(Top(Sin) < Top(Sa)) {
				NGE[i] = Top(Sa);
				break;
			}
		}
		Push(Pop(Sin), Sa);
	}

	for(i = 0; i < N; i++)
		printf("%d ", NGE[i]);
	printf("\n");

	DeleteStack(Sin);
	DeleteStack(Sa);
	return 0;
}
