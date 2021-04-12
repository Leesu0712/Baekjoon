#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 10000
#define CmdMAX 11

struct deque {
	int capacity;
	int front;
	int rear;
	int size;
	int *Array;
};

typedef struct deque *Deque;

Deque MakeDeque(int capacity) {
	Deque D;

	D = malloc(sizeof(struct deque));
	D->capacity = capacity;
	D->front = 0;
	D->rear = 0;
	D->size = 0;
	D->Array = malloc(sizeof(int) * capacity);

	return D;
}

int IsEmpty(Deque D) {
	if(!D->size)
		return 1;
	else
		return 0;
}

static int succ(int Value, Deque D) {
	if(++Value == D->capacity)
		Value = 0;
	return Value;
}

static int pred(int Value, Deque D) {
	if(--Value < 0)
		Value = D->capacity - 1;
	return Value;
}

void Push_front(int X, Deque D) {
	if(D->size == D->capacity)
		printf("Error: Deque is full!!\n");
	else {
		D->front = pred(D->front, D);
		D->Array[D->front] = X;
		D->size++;
	}
}

void Push_back(int X, Deque D) {
	if(D->size == D->capacity)
		printf("Error: Deque is full!!\n");
	else {
		D->Array[D->rear] = X;
		D->rear = succ(D->rear, D);
		D->size++;
	}
}

int Pop_front(Deque D) {
	int ret;
	if(!D->size)
		return -1;
	else {
		ret = D->Array[D->front];
		D->front = succ(D->front, D);
		D->size--;
		return ret;
	}
}

int Pop_back(Deque D) {
	if(!D->size)
		return -1;
	else {
		D->rear = pred(D->rear, D);
		D->size--;
		return D->Array[D->rear];
	}
}

int Front(Deque D) {
	if(!D->size)
		return -1;
	else
		return D->Array[D->front];
}

int Back(Deque D) {
	if(!D->size)
		return -1;
	else
		return D->Array[pred(D->rear, D)];
}

void DeleteDeque(Deque D) {
	free(D->Array);
	free(D);
}

int main() {
	int N, i, X;
	char cmdline[CmdMAX];
	Deque D;
	scanf("%d", &N);
	D = MakeDeque(N);

	for(i = 0; i < N; i++) {
		scanf("%s", cmdline);
		if(!strcmp(cmdline, "push_back")) {
			scanf("%d", &X);
			Push_back(X, D);
		}
		else if(!strcmp(cmdline, "push_front")) {
			scanf("%d", &X);
			Push_front(X, D);
		}
		else if(!strcmp(cmdline, "pop_front"))
			printf("%d\n", Pop_front(D));
		else if(!strcmp(cmdline, "pop_back"))
			printf("%d\n", Pop_back(D));
		else if(!strcmp(cmdline, "size"))
			printf("%d\n", D->size);
		else if(!strcmp(cmdline, "empty"))
			printf("%d\n", IsEmpty(D));
		else if(!strcmp(cmdline, "front"))
			printf("%d\n", Front(D));
		else if(!strcmp(cmdline, "back"))
			printf("%d\n", Back(D));
		else
			printf("Error: Please enter the valid command!\n");
	}

	DeleteDeque(D);
	return 0;
}
