#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

int main(int argc, char *argv[]) {

	SCAN_DATA();
	PRINT_DATA();

	HEAP_SORT();

	PRINT_DATA();

	system("pause");
	return 0;
}