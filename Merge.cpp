//2017029870_신호중
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

void Merge(int* arr, int l,int m, int r){
    int i, j, k;
    int n1 = m+1-l;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i = 0; i<n1; i++)
        L[i] = arr[l+i];
    for(j = 0; j<n2; j++)
        R[j] = arr[m+1+j];

    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2){
        if(L[i] >= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void MergeSort(int* arr, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        MergeSort(arr, p, q);
        MergeSort(arr, q+1, r);
        Merge(arr, p, q, r);
    }
}

int
main(){
    int N;

    scanf("%d", &N);
    
     if(!(1 <= N && N <= MAX_N))
        return -1;

    int* arr = (int*)malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        scanf("%d", arr + i);
    }

    MergeSort(arr, 0, N-1);

    for(int i = 0; i < N; i++){
        printf("%d\n", *(arr + i));
    }
    return 0;
}