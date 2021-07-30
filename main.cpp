#include "head.h"
using std::list;

constexpr size_t SIZE = 10;

void swapInt(int* pa, int* pb) {
	if (!pa || !pb || pa == pb)
		return;

	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void funcSort1(int* const arr, const size_t size) {
	if (!arr || size < 2)
		return;

	size_t limit = size - 1;
	for (size_t i = 0; i < limit; i++) {
		for (size_t d = i + 1; d < size; ++d) {
			if (arr[i] > arr[d]) {
				swapInt(arr + i, arr + d);
			}
		}
	}
}

void funcSort2(int* const arr, const size_t size) {
	if (!arr || size < 2)
		return;

	size_t minIndex = 0;
	size_t limit = size - 1;
	for (size_t i = 0; i < limit; i++) {
		minIndex = i;
		for (size_t d = i + 1; d < size; d++) {
			if (arr[minIndex] > arr[d]) {
				minIndex = d;
			}
		}
		if (minIndex != i) {
			swapInt(arr + minIndex, arr + i);
		}
	}
}

void funcHeapSort(int* const arr, const size_t size) {
	list<int> stack;
}

void funcRandArr(int* const arr, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}
}

void funcShowArray(const int* const arr, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	putchar('\n');
}

void checkArr(const int* const arr1, const int* const arr2, const size_t size) {
	size_t d = 0;
	for (size_t i = 0; i < size; i++) {
		for (d = 0; d < size; d++) {
			if (arr1[i] == arr2[d]) {
				break;
			}
		}
		if (d == size) {
			printf("result: fault at %u\n", i);
			return;
		}
	}
	printf("result: true\n");
}

void showTime() {
	time_t t = time(NULL);
	tm s_tm;
	localtime_s(&s_tm, &t);
	char timeString[50];
	asctime_s(timeString, 50, &s_tm);
	puts(timeString);
}

void sortTest() {
	size_t size = SIZE;
	int* arr = (int*)calloc(size, sizeof(int));
	int* arrBack = (int*)calloc(size, sizeof(int));

	if (!arr || !arrBack) {
		puts("fetal error at sortTest");
		return;
	}

	srand((unsigned int)time(NULL));

	puts("s1");
	srand(abs(rand()));
	funcRandArr(arr, size);
	memcpy(arrBack, arr, size * sizeof(int));
	funcShowArray(arr, size);
	funcSort1(arr, size);
	funcShowArray(arr, size);
	checkArr(arr, arrBack, size);

	puts("s2");
	srand(abs(rand()));
	funcRandArr(arr, size);
	memcpy(arrBack, arr, size * sizeof(int));
	funcShowArray(arr, size);
	funcSort2(arr, size);
	funcShowArray(arr, size);
	checkArr(arr, arrBack, size);

	free(arr);
	free(arrBack);
}

int main(void) {
	showTime();
	sortTest();
	return 0;
}