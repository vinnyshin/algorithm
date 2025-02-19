//2017029870_신호중

#include <stdio.h>
#include <stdlib.h>

#define BLACK 2
#define GRAY 1
#define WHITE 0

int cost = 0, N, *bit, is = 0;

typedef struct ad_list
{
	int nodeNum;
	ad_list *next;
}ad_list;

typedef struct graph
{
	int nodeNum;
	int d;
	int f;
	int color;
}graph;

void passby(graph* topologicalSort, ad_list **L, int i)
{

	ad_list *subList = L[i];
	cost += 1;
	topologicalSort[i].d = cost;
	topologicalSort[i].color = GRAY;

	bit[i] = 1;

	while ( subList->next != NULL )
	{
		if ( bit[subList->next->nodeNum] == 1 )
		{
			printf("0\n");
			is = 1;
		}
		if ( topologicalSort[subList->next->nodeNum].color == WHITE )
			passby(topologicalSort, L, subList->next->nodeNum);
		else
			subList = subList->next;
	}

	bit[i] = 0;
	topologicalSort[i].color = BLACK;
	cost += 1;
	topologicalSort[i].f = cost;
}

int main()
{
	int x, y, i = 0, *array, j = 0;

	if ( scanf("%d", &N) != 1 || N < 0 || N > 1000 )
		return -1;

	graph *topologicalSort = (graph*)malloc(sizeof(graph)*(N + 1));
	ad_list **L = (ad_list**)malloc(sizeof(ad_list*)*(N + 1));
	bit = (int*)malloc(sizeof(int)*(N + 1));
	array = (int*)malloc(sizeof(int)*N);

	for ( i = 1; i <= N; i++ )
	{
		bit[i] = 0;
		topologicalSort[i].nodeNum = i;
		topologicalSort[i].color = WHITE;
		topologicalSort[i].d = 0;
		topologicalSort[i].f = 0;
		L[i] = (ad_list*)malloc(sizeof(ad_list));
		L[i]->nodeNum = i;
		L[i]->next = NULL;
	}

	while ( scanf("%d %d", &x, &y) != EOF )
	{

		if ( x < 0 || x > 1000 || y < 0 || y > 1000 )
			return -1;
		
		ad_list *new_graph = (ad_list*)malloc(sizeof(ad_list));
		ad_list *temp = L[x];
		
		new_graph->next = NULL;
		new_graph->nodeNum = y;

		while ( temp->next != NULL && temp->next->nodeNum < new_graph->nodeNum )
			temp = temp->next;

		ad_list *temp2 = temp->next;
		temp->next = new_graph;
		new_graph->next = temp2;
	}


	for ( i = 1; i <= N; i++ )
		if ( topologicalSort[i].color == WHITE )
			passby(topologicalSort, L, i);

	
	for ( i = 1; i <= N; i++ )
	{
		int max = i;
		for ( j = i + 1; j <= N; j++ )
			if ( topologicalSort[max].f < topologicalSort[j].f )
				max = j;

		array[i - 1] = topologicalSort[max].nodeNum;
		graph temp = topologicalSort[i];
		topologicalSort[i] = topologicalSort[max];
		topologicalSort[max] = temp;

	}

	if ( is == 0 )
	{
		printf("1\n");
		for ( i = 0; i < N; i++ )
			printf("%d ", array[i]);
		printf("\n");
	}
	return 0;
}
