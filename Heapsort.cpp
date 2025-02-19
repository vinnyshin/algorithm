//2017029870_신호중

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void MaxHeap(int arr[], int num, int integer)
{
	int p = integer;
	int left = 2*integer + 1;
	int right = 2*integer + 2;
	
	if (left < num && arr[left] > arr[p])
		p = left;
	if (right < num && arr[right] > arr[p])
		p = right;
	if (p != integer)
	{
		swap(arr[integer], arr[p]);
		MaxHeap(arr, num, p);
	}
}

void
HeapSort(int arr[], int num)
{
	for (int integer = num / 2 - 1; integer >= 0; integer--)
		MaxHeap(arr, num, integer);
	for (int integer=num-1; integer>=0; integer--)
	{
		swap(arr[0], arr[integer]);
		MaxHeap(arr, integer, 0);
	}
}


int main()
{
	int num, key;
	scanf("%d %d", &num, &key);

	int* arr = (int*)malloc(sizeof(int) * num);

	if( !(1<= num && num <= 1000000 ) || !( 1<= key && key <= 30)) {
		return -1;
	}

	for(int integer = 0; integer < num; integer++) {
		scanf("%d", &arr[integer]);
	}

	HeapSort(arr, num);

	for (int integer = num-1; integer >= num-key; integer--)
	{
		printf("%d ", arr[integer]);
	}
	printf("\n");
	for(int integer = num-key-1; integer >= 0; integer--) {
		printf("%d ", arr[integer]);
	}
	
	return 0;
}