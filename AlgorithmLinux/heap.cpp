
#include "heap.h"

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 1000

#define PARENT(idx) (idx>>1)
#define LEFT(idx)	(idx<<1)
#define RIGHT(idx)	(idx<<1|1)

struct HEAP{
	int data[MAXSIZE];
	int length;//数组元素个数
	int heapsize;//堆有效元素个数
};

HEAP h;

void INPUT(){
	h.length = 10;
	h.heapsize = 0;
	for(int i = 1; i <= 10; ++i){
		cin >> h.data[i];
	}
}

void PRINT(){
	for(int i = 1; i <= 10; ++i){
		cout << h.data[i] << " ";
	}
	cout << endl;
}

//维护最大堆
void MAX_HEAPIFY(int idx){
	int largest = idx;
	int l = LEFT(idx);
	int r = RIGHT(idx);
	if(l <= h.heapsize && h.data[l] > h.data[largest]){
		largest = l;
	}
	if(r <= h.heapsize && h.data[r] > h.data[largest]){
		largest = r;
	}
	if(largest != idx){
		swap(h.data[largest], h.data[idx]);
		MAX_HEAPIFY(largest);
	}
}

//建立最大堆
void BUID_MAX_HEAP(){
	h.heapsize = h.length;
	for(int idx = h.length >> 1; idx > 0; --idx){
		MAX_HEAPIFY(idx);
	}

}

//堆排序
void HEAP_SORT(){
	BUID_MAX_HEAP();
	for(int idx = h.heapsize; idx > 1; --idx){
		swap(h.data[idx], h.data[1]);
		--h.heapsize;
		MAX_HEAPIFY(1);
	}
}

void testHeap(){
	INPUT();
	HEAP_SORT();
	PRINT();
}

