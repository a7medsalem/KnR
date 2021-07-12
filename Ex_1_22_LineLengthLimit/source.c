/*
*	Summary
*	- print lines with max length of 80 chars.
*/


#include <stdio.h>

#define MAXLENGTH 80
#define IN 1
#define OUT 0


int main() {

	FILE* file = freopen("testfile.txt", "r", stdin);
	
	int c;
	int charCount;
	int col, row;
	int state;

	printf("VVVVV\t\t\tThis is 80 char-line-length.\t\t\tVVVVV\n");
	printf("01234567890123456789012345678901234567890123456789012345678901234567890123456789\n\n");

	charCount = col = 0;
	row = 1;
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		col++;
		if (c == '\t' || c == ' ')
		{
			state = OUT;
			charCount = 0;
		}
		else {
			state = IN;
			charCount++;
		}

		if (col > MAXLENGTH) {
			if (state == OUT)
			{
				printf("\n");
				col = 0;
			}
			else
			{
				if (charCount <= 1) 
				{
					printf("\n%c", c);
				}
				else 
				{
					printf("-\n%c", c);
				}
				col = 1;
			}

			row++;
			continue;
		}
		else
			printf("%c", c);


		if (c == '\n') 
		{
			row++;
			col = 0;
		}
	}


	fclose(stdin);
	return 0;
}


