//2017029870_신호중

#include <stdio.h>
#include <stdlib.h>

typedef struct ad_list
{
	int nodeNum;
	int weight;
	ad_list *next;
}ad_list;

#define INFINITE 276447231

int main()
{
	int N, i = 0, j = 0, *bit, *queue, min = -1;

	if ( scanf("%d", &N) != 1 || N < 1 || N > 5000 )
		return -1;

	bit = (int*)malloc(sizeof(int)*N);
	queue = (int*)malloc(sizeof(int)*(N + 1));
	ad_list **adList = (ad_list**)malloc(sizeof(ad_list*)*N);

	for ( i = 0; i < N; i++ )
	{
		queue[i] = INFINITE;
		bit[i] = 0;
		adList[i] = (ad_list*)malloc(sizeof(ad_list));
		adList[i]->next = NULL;
		adList[i]->nodeNum = i + 1;
		adList[i]->weight = 0;
	}
	queue[0] = 0;
	queue[N] = INFINITE;

	for ( i = 0; i < N; i++ )
	{
		int idx;
		int cnt;
		if ( scanf("%d %d", &idx, &cnt) != 2 || cnt < 1 || cnt > N )
			return -1;

		for ( j = 0; j < cnt; j++ )
		{
			ad_list* nVtex = (ad_list*)malloc(sizeof(ad_list));
			nVtex->next = NULL;
			if ( scanf("%d %d", &nVtex->nodeNum, &nVtex->weight) != 2 )
				return -1;

			ad_list* tmp = adList[idx - 1];
			while ( tmp->next != NULL )
				tmp = tmp->next;
			tmp->next = nVtex;
		}
	}

	for ( i = 0; i < N; i++ )
	{
		int min = N;
		for ( j = 0; j < N; j++ )
			if ( queue[min] > queue[j] && bit[j] == 0 )
				min = j;
		if ( min != N )
		{
			bit[min] = 1;
			ad_list *tmp = adList[min]->next;
			while ( tmp != NULL )
			{
				if ( queue[tmp->nodeNum - 1] > tmp->weight + queue[min] )
					queue[tmp->nodeNum - 1] = tmp->weight + queue[min];
				tmp = tmp->next;
			}
		}
	}

	for ( i = 0; i < N; i++ )
		if ( min < queue[i] && queue[i] != INFINITE )
			min = queue[i];

	printf("%d\n", min);

	return 0;
}