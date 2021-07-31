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

void funcShowArray(const int* const arr, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		printf("%d ", *(arr + i));
	}
	putchar('\n');
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
	if (!arr || size < 2)
		return;

	list<size_t> stack;
	puts("--");
	for (size_t i = 1; i < size; i++) {
		long curRoot = i % 2 == 0 ? (i - 2) / 2 : (i - 1) / 2;
		stack.push_back(curRoot);
		funcShowArray(arr, size);
		while (stack.size()) {
			curRoot = stack.back();
			stack.pop_back();

			size_t cLeft = 2 * curRoot + 1;
			size_t cRight = 2 * curRoot + 2;
			long target = curRoot % 2 == 0 ? (curRoot - 2) / 2 : (curRoot - 1) / 2;

			if (cRight < size) {
				if (arr[cRight] < arr[cLeft])
					swapInt(arr + cRight, arr + cLeft);

				if (arr[cLeft] < arr[curRoot]) {
					swapInt(arr + cLeft, arr + curRoot);
				}
			}
			else if (cRight >= size && cLeft < size) {
				if (arr[cLeft] < arr[curRoot]) {
					swapInt(arr + cLeft, arr + curRoot);
				}
			}

			if (curRoot != 0 && target >= 0) {
				stack.push_back(target);
			}
		}
	}
	puts("--");
}

void funcRandArr(int* const arr, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}
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

	for (size_t i = 0; i < size - 1; i++) {
		if (arr1[i] > arr1[i + 1]) {
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

	//puts("s1");
	//srand(abs(rand()));
	//funcRandArr(arr, size);
	//memcpy(arrBack, arr, size * sizeof(int));
	//funcShowArray(arr, size);
	//funcSort1(arr, size);
	//funcShowArray(arr, size);
	//checkArr(arr, arrBack, size);

	//puts("s2");
	//srand(abs(rand()));
	//funcRandArr(arr, size);
	//memcpy(arrBack, arr, size * sizeof(int));
	//funcShowArray(arr, size);
	//funcSort2(arr, size);
	//funcShowArray(arr, size);
	//checkArr(arr, arrBack, size);

	puts("s3");
	srand(abs(rand()));
	funcRandArr(arr, size);
	memcpy(arrBack, arr, size * sizeof(int));
	funcShowArray(arr, size);
	funcHeapSort(arr, size);
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