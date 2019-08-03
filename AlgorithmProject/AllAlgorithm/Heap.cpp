

#include "Heap.h"

//�Ѵ��±�1��ʼ
#define PARENT(x)	(x>>1)
#define LEFT(x)		(x<<1)
#define RIGHT(x)	(x<<1|1)

#define HEAP_SIZE 1000

typedef struct _heap {
	int elem[HEAP_SIZE];
	int heapSize;//�ѵ�ǰԪ�ظ���
	int length;//����Ԫ�صĸ���
} HEAP, *PHEAP;

HEAP heap;

//��������
void SCAN_DATA() {
	cout << "heap length>>";
	cin >> heap.length;
	for (int i = 1; i <= heap.length; ++i) {
		cin >> heap.elem[i];
	}
}

//��ӡ����
void PRINT_DATA() {
	cout << "heap length: " << heap.length << endl;
	for (int i = 1; i <= heap.length; ++i) {
		cout << heap.elem[i] << " ";
	}
	cout << endl;
}

//ά������
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

//������
void BUILD_MAX_HEAP() {
	heap.heapSize = heap.length;
	for (int i = heap.heapSize >> 1; i > 0; --i) {
		MAX_HEAPIFY(i);
	}
} 

//������
void HEAP_SORT() {
	BUILD_MAX_HEAP();
	for (int i = heap.heapSize; i > 1; --i) {
		swap(heap.elem[1], heap.elem[i]);
		heap.heapSize = heap.heapSize - 1;
		MAX_HEAPIFY(1);
	}
}