/*
*	Summary
*	- replace multiple spaces with equivelant tabs.
*/

#include <stdio.h>

#define INSPACE 1
#define OUTSPACE 0
/*
*	I consider here tab = 8 spaces
*		to be equal to console tabs
*/
#define TABSPACING 8


int getNextTab(int, int);


int main() {

	FILE* file = freopen("testfile.txt", "r", stdin);
	char c;
	int col, row;
	int state;
	int spaceCount;

	col = 0;
	row = 1;
	spaceCount = 0;
	state = OUTSPACE;
	while ((c = getchar()) != EOF)
	{
		
		if (c == ' ') 
		{
			state = INSPACE;
			spaceCount++;
			col++;
		}
		else if (c == '\t') 
		{
			spaceCount = 0;
			state = OUTSPACE;
			printf("\t");

			col = getNextTab(col, TABSPACING);
		}
		else 
		{
			if (state == INSPACE)
			{
				for (int i = 0; i < spaceCount; i++)
				{
					printf(" ");
					col++;
				}
				state = OUTSPACE;
				spaceCount = 0;
			}
			
			printf("%c", c);
			col++;
		}


		// replace 4 spaces with 1 tab
		if (state == INSPACE && col % TABSPACING == 0)
		{
			state = OUTSPACE;
			spaceCount = 0;
			printf("%c", '\t');
		}
		

		// count line number
		if (c == '\n'){
			col = 0;
			++row;
		}
	}
	

	fclose(stdin);
	return 0;
}



int getNextTab(int col, int tabspacing)
{
	int remind;
	int add;

	add = 0;
	if ((remind = col % tabspacing) > 0)
		add = tabspacing - remind;

	return col + add;
}