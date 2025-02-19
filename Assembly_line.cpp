//2017029870_신호중
#include <cstdio>
#include <cstdlib>

int
min(int a, int b){
    return a < b ? a : b;
}


int
main(){
    int num;
    int aEntryTime, bEntryTime;
    int aExitTime, bExitTime;
    
    scanf("%d", &num);

    if(num < 1 || num > 100){
        return -1;
    }

    scanf("%d %d", &aEntryTime, &bEntryTime);

    if(aEntryTime < 1 || aEntryTime > 100 || bEntryTime < 1 || bEntryTime > 100 ){
        return -1;
    }

    scanf("%d %d", &aExitTime, &bExitTime);

    if(aExitTime < 1 || aExitTime > 100 || bExitTime < 1 || bExitTime > 100 ){
        return -1;
    }

    int * aLine = (int*)malloc(sizeof(int) * num);
    int * bLine = (int*)malloc(sizeof(int) * num);

    for(int i = 0; i < num; ++i){
        scanf("%d", &aLine[i]);
        if(aLine[i] < 1 || aLine[i] > 100){
            return -1;
        }
    }

    for(int i = 0; i < num; ++i){
        scanf("%d", &bLine[i]);
        if(bLine[i] < 1 || bLine[i] > 100){
            return -1;
        }
    }

    int * aTob = (int*)malloc(sizeof(int) * num - 1);
    int * bToa = (int*)malloc(sizeof(int) * num - 1);

    for(int i = 0; i < num - 1; ++i){
        scanf("%d", &aTob[i]);
        if(aTob[i] < 1 || aTob[i] > 100){
            return -1;
        }
    }

    for(int i = 0; i < num - 1; ++i){
        scanf("%d", &bToa[i]);
        if(bToa[i] < 1 || bToa[i] > 100){
            return -1;
        }
    }

    //making row
    int ** lTable = (int **)malloc(sizeof(int*) * 2);
    //making column
    for(int row = 0; row < 2; ++row){
        lTable[row] = (int*)malloc(sizeof(int)* num);
        lTable[row][0] = -1;
    }    

    //making row
    int ** sTable = (int **)malloc(sizeof(int*) * 2);
    //making column
    for(int row = 0; row < 2; ++row){
        sTable[row] = (int*)malloc(sizeof(int)* num);
    }    

    
    sTable[0][0]= aEntryTime + aLine[0];
    sTable[1][0]= bEntryTime + bLine[0];
    
    for(int i = 1; i < num; ++i){
        sTable[0][i] = min(sTable[0][i-1]+ aLine[i], sTable[1][i-1] + bToa[i - 1] + aLine[i]);
        if(sTable[0][i] == sTable[0][i-1]+ aLine[i]){
            lTable[0][i] = 0;
        }
        else{
            lTable[0][i] = 1;
        }
        
        sTable[1][i] = min(sTable[1][i-1]+ bLine[i], sTable[0][i-1] + aTob[i - 1] + bLine[i]);
        if(sTable[1][i] == sTable[1][i-1]+ bLine[i]){
            lTable[1][i] = 1;
        }
        else{
            lTable[1][i] = 0;
        }
    }
    int MIN = min(sTable[0][num - 1] + aExitTime, sTable[1][num-1] + bExitTime);
    printf("%d\n", MIN);
    int count = num;
    int * tmparray = (int*)malloc(sizeof(int) * num);
    if(MIN == sTable[0][num - 1] + aExitTime){    
        int tmp = 0;
        tmparray[count - 1] = 1;
        while(tmp != -1){
            count--;
            tmparray[count -1] = lTable[tmp][count] + 1;
            tmp = lTable[tmp][count];
        }    
    }
    else{
        int tmp = 1;
        tmparray[count - 1] = 2;
        while(tmp != -1){
            count--;
            tmparray[count -1] = lTable[tmp][count] + 1;
            tmp = lTable[tmp][count];
        }
    }

    for(int i = 0; i < num; ++i){
        printf("%d %d\n", tmparray[i], i + 1);
    }
    

    return 0;
}