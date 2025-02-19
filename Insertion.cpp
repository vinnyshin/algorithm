//2017029870_신호중
#include <stdio.h>
#include <stdlib.h>


#define MAX_N 30000

int
main(){
    int N, key, i, j; 
    scanf("%d", &N);
    if(!(1 <= N && N <= MAX_N))
        return -1;

    int* arr = (int*)malloc(sizeof(int) * N);

    for(i = 0; i < N; i++){
        scanf("%d", arr + i);
    }
    
    for(j = 1; j < N; j++){
        key = arr[j];
        i = j-1;
    
        while(0 <= i && key > arr[i]){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;    
    }


    for(i = 0; i < N; i++){
        printf("%d\n", *(arr + i));
    }
	return 0;
}
