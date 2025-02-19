//2017029870_신호중

#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

void printOptimal(int**s, int i, int j){
    if (i == j){
        printf("%d", i);
    }
    else {
        printf("(");
        printOptimal(s,i,s[i][j]);
        printOptimal(s,s[i][j]+1,j);
        printf(")");
    }
}

int
main(){
    int num;

    scanf("%d", &num);
    if(num < 1 || num > 100){
        return -1;
    }

    //p is a zero based array
    int* p = (int*)malloc(sizeof(int) * (num + 1));

    for(int i = 0; i < (num + 1); ++i)
    {
        scanf("%d", &p[i]);
    }

    //m is the one based array
    int** m = (int**)malloc(sizeof(int) * (num + 1));

    for(int i = 0; i < (num + 1); ++i){
        m[i] = (int*)malloc(sizeof(int)* (num + 1));
    }

    //s is the one based array
    int** s = (int**)malloc(sizeof(int) * (num + 1));

    for(int i = 0; i < (num + 1); ++i){
        s[i] = (int*)malloc(sizeof(int) * (num + 1));
    }

    for(int i = 1; i < (num + 1); ++i){
        m[i][i] = 0;
    }

    for(int l = 2; l < (num + 1); ++l){
        for(int i = 1; i < num - l + 2; ++i){
            int j = i + l - 1;
            
            m[i][j] = __INT_MAX__;
            int q;
            for(int k = i; k < j; ++k){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    
    printf("%d\n", m[1][num]);
    printOptimal(s,1,num);

    return 0;
}