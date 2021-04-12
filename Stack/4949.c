#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define StrMAX 100

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
	char p, str[StrMAX+1];
	Stack S;
	S = CreateStack(StrMAX);

	while(1) {
		fgets(str, StrMAX+1, stdin);
		if((str[0] == '.') && (str[1] == '\n'))
			break;
		for(j = 0; str[j] != '.'; j++) {
			if((str[j] != '(') && (str[j] != ')') && (str[j] != '[') && (str[j] != ']'))
				continue;
			else if((Top(S) == '(') && (str[j] == ')'))
				Pop(S);
			else if((Top(S) == '[') && (str[j] == ']'))
				Pop(S);
			else
				Push(str[j], S);
		}
		printf("%s\n", IsEmpty(S) ? "yes" : "no");
		MakeEmpty(S);
	}
	return 0;
}
