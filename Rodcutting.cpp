//2017029870_신호중
#include <cstdio>
#include <cstdlib>

#define MAX_NUM 100

void calculateSum(int *p, int num, int * rod, int * mostProfit){
    int partialRod = num;
    int sum = 0;
    while(partialRod > 0){
        sum = sum + rod[mostProfit[partialRod]];
        partialRod = partialRod - mostProfit[partialRod];
    }
    printf("%d\n", sum);

    partialRod = num;
    while(partialRod > 0){
        printf("%d ", mostProfit[partialRod]);
        partialRod = partialRod - mostProfit[partialRod];
    }
    printf("\n");
}

void bottomUp(int *p, int num, int * rod, int * mostProfit){
    //1 base
    rod[0] = 0;
    for(int i = 1; i <= num; ++i){
        int max = -1;
        for(int j = 1; j <= i; ++j){
            if(max < p[j] + rod[i - j]){
                max = p[j] + rod[i - j];
                mostProfit[i] = j;
            }
            rod[i] = max;
        }
    }
}

int
main(){
    ///////////initializing the variables.
    int num;
    int* price;
    
    scanf("%d", &num);
    if(num < 1 || num > 100){
        return -1;
    }

    int * rod = (int*)malloc(sizeof(int) * num + 1);
    int * mostProfit = (int*)malloc(sizeof(int) * num + 1);

    //1 base
    price = (int*)malloc(sizeof(int) * num + 1);
    price[0] = 0;

    for(int i = 1; i <= num; ++i){
        scanf("%d", &price[i]);
        if(price[i-1] > price[i]){
            return -1;
        }
    }
    ///////////

    bottomUp(price, num, rod, mostProfit);
    calculateSum(price, num, rod, mostProfit);
}