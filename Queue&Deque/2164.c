#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 500000

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
	int N, i;
	Queue Q;
	scanf("%d", &N);
	Q = MakeQueue(N);

	for(i = 1; i <= N; i++) {
		Push(i, Q);
	}

	for(i = 1; i < N; i++) {
		Pop(Q);
		Push(Pop(Q), Q);
	}

	printf("%d\n", Back(Q));

	DeleteQueue(Q);
	return 0;
}
