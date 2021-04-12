#include <stdio.h>
#include <stdlib.h>
#define NMAX 50

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

void PrintDeque(Deque D) {
	int i, cnt = 0;
	for(i = D->front; cnt < D->size; i = succ(i, D)) {
		printf("%d ", D->Array[i]);
		cnt++;
	}
	printf("\n");
}

int main() {
	int N, M, i, j, X, right = 0, left, sum = 0;
	Deque D;
	scanf("%d %d", &N, &M);
	D = MakeDeque(N);
	for(i = 1; i <= N; i++)
		Push_back(i, D);

	for(i = 0; i < M; i++) {
		scanf("%d", &X);
		if(Front(D) == X)
			Pop_front(D);
		else {
			for(j = D->front; D->Array[j] != X; j = succ(j, D))
				right++;
			left = D->size - right;
			if(right <= left) {
				for(j = 0; j < right; j++)
					Push_back(Pop_front(D), D);
				Pop_front(D);
				sum += right;
			}
			else {
				for(j = 0; j < left ; j++)
					Push_front(Pop_back(D), D);
				Pop_front(D);
				sum += left;
			}
			right = 0;
		}
	}
	printf("%d\n", sum);

	DeleteDeque(D);
	return 0;
}
