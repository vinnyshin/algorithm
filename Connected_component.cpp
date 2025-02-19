//2017029870_신호중


#include<stdio.h>

#define MAX_BUF 1001
#define TRU 1
#define FAL 0



int num[MAX_BUF];
int cnk [MAX_BUF];

int arrayy[MAX_BUF][MAX_BUF]={0,};

void DFS(int index, int eachVerNum, int vertexCnt)
{
	int i;
	if(cnk[index] == TRU)
		return;
	num[index] = eachVerNum;
	cnk[index] = TRU;

	for (i = 1; i <= vertexCnt; i++) {
		if(arrayy[index][i] == TRU && cnk[i] == FAL)
			DFS(i,eachVerNum,vertexCnt);
	}

}
int main(void)
{
	int x=0,y=0,vertexCnt=0;
	scanf("%d",&vertexCnt);
	int i=0,cnt=0,eachVerNum=0;
	while(2 == scanf("%d %d", &x,&y)){
		arrayy[x][y] = arrayy[y][x] = TRU;
	}

	for (i = 1; i <= vertexCnt; i++) {
		if (cnk[i] == TRU)
			continue;
		else
			DFS(i, ++eachVerNum, vertexCnt);
		cnt++;
	}
	printf("%d\n", cnt);

	for (i = 1; i <= vertexCnt; i++) {
		printf("%d\n", num[i]);
	}

	return 0;

}
