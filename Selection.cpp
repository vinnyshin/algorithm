//2017029870_신호중

#include <stdio.h>
#include <stdlib.h>

int
main() {
	int numOfKey, count, min;
	scanf("%d %d", &numOfKey, &count);

	if(!((1<= numOfKey && numOfKey<= 30000) || (1<=count && count<= 30000))) {
		return -1;
	}

	int* array = (int*)malloc(sizeof(int) * numOfKey);
	
	for(int i = 0; i < numOfKey; ++i) {
		scanf("%d", &array[i]);
	}
	
	for(int i = 0; i < count; ++i){
		min = array[i];
		int index = i;
		for(int j = i + 1; j < numOfKey; ++j){	
			if(min > array[j]){
				min = array[j];
				index = j;
			}
		}
		int tmp = array[i];
		array[i] = array[index];
		array[index] = tmp;
	}

	for(int i = 0; i < numOfKey; ++i){
		printf("%d\n", array[i]);
	}

	return 0;
}

