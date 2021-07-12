/*
*	Summary
*	- replace tabs with equivelant spaces.
*/

#include <stdio.h>

/*
*	I consider here tab = 4 spaces
*		to be equal to txt editor tabs
*/
#define TABSPACING 4


int main() {

	FILE* file = freopen("testfile.txt", "r", stdin);
	char c;
	int col, row;

	col = 0;
	row = 1;
	while ((c = getchar()) != EOF)
	{
		
		if (c == '\t') {
			int remind = TABSPACING - (col % TABSPACING);
			for (int i = 0; i < remind; i++)
			{
				printf("%c", ' ');
				col++;
			}
		}
		else 
		{
			printf("%c", c);
			col++;
		}

		if (c == '\n'){
			col = 0;
			++row;
		}
	}
	

	fclose(stdin);
	return 0;
}