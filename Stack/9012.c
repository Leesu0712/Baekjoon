#include <stdio.h>
#include <stdlib.h>
#define PSMAX 50

struct StackInfo {
	int Capacity;
	int TopOfStack;
	char *Array;
};

typedef struct StackInfo *Stack;

Stack CreateStack(int Max) {
	Stack S;

	S = malloc(sizeof(struct StackInfo));
	S->Array = malloc(sizeof(char) * Max);
	S->Capacity = Max;
	S->TopOfStack = -1;

	return S;
}

void MakeEmpty(Stack S) {
	S->TopOfStack = -1;
}

void Push(char p, Stack S) {
	S->Array[++S->TopOfStack] = p;
}

void Pop(Stack S) {
	if(S->TopOfStack == -1)
		printf("Error: Stack is empty!\n");
	else
		S->TopOfStack--;
}

char Top(Stack S) {
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

int main() {
	int T, i, j;
	char p, PS[PSMAX+1];
	Stack S;
	S = CreateStack(PSMAX);

	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%s", PS);
		Push(PS[0], S);
		for(j = 1; PS[j] != '\0'; j++) {
			if((Top(S) == '(') && (PS[j] == ')'))
				Pop(S);
			else
				Push(PS[j], S);
		}
		printf("%s\n", IsEmpty(S) ? "YES" : "NO");
		MakeEmpty(S);
	}
	return 0;
}
