#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 100

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
	int T, N, M, i, j, k, sw1 = 0, sw2 = 0, cnt = 0, Pr[NMAX] = { 0, };
	Queue Q;
	scanf("%d", &T);

	for(i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
		Q = MakeQueue(N);
		for(j = 0; j < N; j++) {
			scanf("%d", &Pr[j]);
			Push(j, Q);
		}

		while(!IsEmpty(Q)) {
		for(j = 0; j < N; j++) {
			if(!Pr[j])
				continue;
			for(k = j+1; k < N; k++) {
				//printf("Pr[%d] = %d, Pr[%d] = %d\n", k, Pr[k], j, Pr[j]);
				if(!Pr[k])
					continue;
				else if(Pr[k] > Pr[j]) {
					sw1 = 1;
					break;
				}
			}
			for(k = 0; k < j; k++) {
				//printf("Pr[%d] = %d, Pr[%d] = %d\n", k, Pr[k], j, Pr[j]);
				if(!Pr[k])
					continue;
				else if(Pr[k] > Pr[j]) {
					sw1 = 1;
					break;
				}
			}
			if(sw1) {
				//printf("Push %d\n", Front(Q));
				Push(Pop(Q), Q);
				sw1 = 0;
			}
			else {
				cnt++;
				//printf("Pop %d\n", Front(Q));
				if(Pop(Q) == M) {
					sw2 = 1;
					break;
				}
				Pr[j] = 0;
			}
		}
		if(sw2)
			break;
		}
		printf("%d\n", cnt);
		cnt = 0;
		sw2 = 0;
		DeleteQueue(Q);
		for(j = 0; j < NMAX; j++)
			Pr[j] = 0;
	}

	return 0;
}
