//2017029870_신호중

#include <stdio.h>
#include <stdlib.h>

int main()
{

	char fLine[500], sLine[500];
	int x, y, i = 0, j = 0;


	if ( scanf("%s", sLine) != 1 )
		return -1;

	if ( scanf("%s", fLine) != 1 )
		return -1;


	while ( fLine[i] != '\0' )
		i++;

	y = i + 1;
	i = 0;

	while ( sLine[i] != '\0' )
		i++;
	
	x = i + 1;

	int **arrayA = (int**)malloc(sizeof(int*)*x);
	for ( i = 0; i < x; i++ )
		arrayA[i] = (int*)malloc(sizeof(int)*y);

	for ( i = 0; i < x; i++ )
	{
		for ( j = 0; j < y; j++ )
		{
			if ( i == 0 || j == 0 )
				arrayA[i][j] = 0;
			else
			{
				if ( fLine[j - 1] == sLine[i - 1] )
					arrayA[i][j] = arrayA[i - 1][j - 1] + 1;
				else if ( arrayA[i - 1][j] >= arrayA[i][j - 1] )
					arrayA[i][j] = arrayA[i - 1][j];
				else if ( arrayA[i - 1][j] <= arrayA[i][j - 1] )
					arrayA[i][j] = arrayA[i][j - 1];
			}
		}
	}

	i = 1;
	for ( j = 1; j < y;)
		if ( fLine[j - 1] == sLine[i - 1] )
		{
			printf("%c", fLine[j - 1]);
			i++;
			j++;
		}
		else
			j++;
	printf("\n");

	return 0;
}
