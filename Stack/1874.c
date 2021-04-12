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
	int n, i, j, k = 0, latest, A[MAX] = { 0, };
	char OP[2*MAX];
	Stack S;
	S = CreateStack(MAX);

	scanf("%d", &n);
	for(j = 0; j < n; j++)
		scanf("%d", &A[j]);

	for(i = 0; A[i] != 0; i++) {
		if(!i) {
			for(j = 1; j <= A[i]; j++) {
				Push(j, S);
				OP[k++] = '+';
			}
			latest = Pop(S);
			OP[k++] = '-';
		}
		else if(Top(S) == A[i]) {
			Pop(S);
			OP[k++] = '-';
		}
		else if(A[i] > latest) {
			for(j = latest + 1; j <= A[i]; j++) {
				Push(j, S);
				OP[k++] = '+';
			}
			latest = Pop(S);
			OP[k++] = '-';
		}
		else {
			printf("NO\n");
			return 0;
		}
	}
	for(i = 0; i < k; i++)
		printf("%c\n", OP[i]);

	DeleteStack(S);
	return 0;
}
