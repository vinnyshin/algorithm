//2017029870_신호중

#include <stdio.h>
#include <stdlib.h>

typedef struct set
{
	int value;
	struct set *next;
}set;

int main()
{

	int *fLine, *sLine, x, y, i = 0, cnt = 0;
	;
	

	if ( scanf("%d", &x) != 1 )
		return -1;
	if ( scanf("%d", &y) != 1 )
		return -1;

	fLine = (int*)malloc(sizeof(int)*x);
	sLine = (int*)malloc(sizeof(int)*y);
	
	set** Htable = (set**)malloc(sizeof(set*) * 1000);

	for ( i = 0; i < 1000; i++ )
	{
		Htable[i] = (set*)malloc(sizeof(set));
		Htable[i]->value = -1;
		Htable[i]->next = NULL;
	}
	
	for ( i = 0; i < x; i++ )
		if ( scanf("%d", &fLine[i]) != 1 || fLine[i] < 0 || fLine[i] > 100000 )
			return -1;

	for ( i = 0; i < y; i++ )
		if ( scanf("%d", &sLine[i]) != 1 || sLine[i] < 0 || sLine[i] > 100000 )
			return -1;

	for ( i = 0; i < x; i++ )
	{
		set *new_set = (set*)malloc(sizeof(set));
		set *tmp = Htable[fLine[i] % 1000];
		new_set->value = fLine[i];
		new_set->next = NULL;
		while ( tmp->next != NULL )
			tmp = tmp->next;
		tmp->next = new_set;
	}

	for ( i = 0; i < y; i++ )
	{
		set *tmp = Htable[sLine[i] % 1000];
		while ( tmp != NULL )
		{
			if ( tmp->value == sLine[i] )
				cnt++;
			tmp = tmp->next;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
