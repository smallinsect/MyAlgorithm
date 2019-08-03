

#include "Heap.h"

//堆从下标1开始
#define PARENT(x)	(x>>1)
#define LEFT(x)		(x<<1)
#define RIGHT(x)	(x<<1|1)

#define HEAP_SIZE 1000

typedef struct _heap {
	int elem[HEAP_SIZE];
	int heapSize;//堆当前元素个数
	int length;//数组元素的个数
} HEAP, *PHEAP;

HEAP heap;

//输入数据
void SCAN_DATA() {
	cout << "heap length>>";
	cin >> heap.length;
	for (int i = 1; i <= heap.length; ++i) {
		cin >> heap.elem[i];
	}
}

//打印数据
void PRINT_DATA() {
	cout << "heap length: " << heap.length << endl;
	for (int i = 1; i <= heap.length; ++i) {
		cout << heap.elem[i] << " ";
	}
	cout << endl;
}

//维护最大堆
void MAX_HEAPIFY(int idx) {
	int l = LEFT(idx);
	int r = RIGHT(idx);
	int largest = idx;
	if (l <= heap.heapSize && heap.elem[l] > heap.elem[largest]) {
		largest = l;
	}
	if (r <= heap.heapSize && heap.elem[r] > heap.elem[largest]) {
		largest = r;
	}
	if (largest != idx) {
		swap(heap.elem[largest], heap.elem[idx]);
		MAX_HEAPIFY(largest);
	}
}

//创建堆
void BUILD_MAX_HEAP() {
	heap.heapSize = heap.length;
	for (int i = heap.heapSize >> 1; i > 0; --i) {
		MAX_HEAPIFY(i);
	}
} 

//堆排序
void HEAP_SORT() {
	BUILD_MAX_HEAP();
	for (int i = heap.heapSize; i > 1; --i) {
		swap(heap.elem[1], heap.elem[i]);
		heap.heapSize = heap.heapSize - 1;
		MAX_HEAPIFY(1);
	}
}