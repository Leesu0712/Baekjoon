#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

struct queue {
	int capacity;
	int front;
	int rear;
	int size;
	int *Array;
};

typedef struct queue *Queue;

Queue MakeQueue(int capacity) {
	Queue Q;

	Q = malloc(sizeof(struct queue));
	Q->capacity = capacity;
	Q->front = 0;
	Q->rear = 0;
	Q->size = 0;
	Q->Array = malloc(sizeof(int) * capacity);

	return Q;
}

int IsEmpty(Queue Q) {
	if(!Q->size)
		return 1;
	else
		return 0;
}

static int succ(int Value, Queue Q) {
	if(++Value == Q->capacity)
		Value = 0;
	return Value;
}

static int pred(int Value, Queue Q) {
	if(--Value < 0)
		Value = Q->capacity - 1;
	return Value;
}

void Push(int X, Queue Q) {
	if(Q->size == Q->capacity)
		printf("Error: Queue is full!!\n");
	else {
		Q->Array[Q->rear] = X;
		Q->rear = succ(Q->rear, Q);
		Q->size++;
	}
}

int Pop(Queue Q) {
	int ret;
	if(!Q->size)
		return -1;
	else {
		ret = Q->Array[Q->front];
		Q->front = succ(Q->front, Q);
		Q->size--;
		return ret;
	}
}

int Front(Queue Q) {
	if(!Q->size)
		return -1;
	else
		return Q->Array[Q->front];
}

int Back(Queue Q) {
	if(!Q->size)
		return -1;
	else
		return Q->Array[pred(Q->rear, Q)];
}

void DeleteQueue(Queue Q) {
	free(Q->Array);
	free(Q);
}

int main() {
	int N, K, i, k, Yose[NMAX];
	Queue Q;
	scanf("%d %d", &N, &K);
	Q = MakeQueue(N);

	for(i = 1; i <= N; i++)
		Push(i, Q);

	for(i = 0; Q->size > 1; i++) {
		for(k = 1; k < K; k++)
			Push(Pop(Q), Q);
		Yose[i] = Pop(Q);
	}
	Yose[i] = Pop(Q);

	for(i = 0; i < N; i++) {
		if(!i && (i == N-1))
			printf("<%d>\n", Yose[i]);
		else if(!i)
			printf("<%d, ", Yose[i]);
		else if(i == N-1)
			printf("%d>\n", Yose[i]);
		else
			printf("%d, ", Yose[i]);
	}

	DeleteQueue(Q);
	return 0;
}
