#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

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

void MakeEmpty(Deque D) {
	D->size = 0;
	D->front = 0;
	D->rear = 0;
}

void DeleteDeque(Deque D) {
	free(D->Array);
	free(D);
}

/*
void PrintDeque(Deque D) {
	int i, cnt = 0;
	for(i = D->front; cnt < D->size; i = succ(i, D)) {
		printf("%d ", D->Array[i]);
		cnt++;
	}
	printf("\n");
}
*/

void PrintDeque(Deque D) {
	int i, cnt = 0;
	for(i = D->front; cnt < D->size; i = succ(i, D)) {
		if((i == D->front) && (cnt == D->size - 1))
			printf("[%d]", D->Array[i]);
		else if(i == D->front)
			printf("[%d,", D->Array[i]);
		else if(cnt == D->size - 1)
			printf("%d]", D->Array[i]);
		else
			printf("%d,", D->Array[i]);
		cnt++;
	}
	printf("\n");
}

void PrintRevDeque(Deque D) {
	int i, cnt = 0;
	for(i = pred(D->rear, D); cnt < D->size; i = pred(i, D)) {
		if((i == pred(D->rear, D)) && (cnt == D->size - 1))
			printf("[%d]", D->Array[i]);
		else if(i == pred(D->rear, D))
			printf("[%d,", D->Array[i]);
		else if(cnt == D->size - 1)
			printf("%d]", D->Array[i]);
		else
			printf("%d,", D->Array[i]);
		cnt++;
	}
	printf("\n");
}

int main() {
	int T, n, i, j, k, x, back = 0, error = 0;
	char pcmd[MAX+1], par, com;
	Deque D;
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		scanf("%s %d", pcmd, &n);
		D = MakeDeque(n);
		scanf(" %c", &par);
		for(j = 0; j < n; j++) {
			scanf("%d", &x);
			Push_back(x, D);
			if(j == (n-1))
				break;
			scanf("%c", &com);
		}
		scanf("%c", &par);
		
		for(j = 0; pcmd[j] != '\0'; j++) {
			if(pcmd[j] == 'R') {
				back = ~back;
			}
			else if(pcmd[j] == 'D') {
				if(IsEmpty(D)) {
					error = 1;
					break;
				}
				else if(back)
					Pop_back(D);
				else
					Pop_front(D);
			}
		}
		if(error)
			printf("error\n");
		else if(!D->size)
			printf("[]\n");
		else if(back)
			PrintRevDeque(D);
		else
			PrintDeque(D);
		DeleteDeque(D);
		back = 0;
		error = 0;
	}
	return 0;
}
