/*
*	Summary
*	- define functions.
*	- draw horizontal histogram its height represents words length.
*/


#include <stdio.h>

#define IN 1
#define OUT 0


void printHorizontalHistogram();

int main() {

	printf("\n\n\t#### Words Histogram ####\n");
	printf("\tEnter some words and press Enter to print histogram represent words length.\n\n");
	printHorizontalHistogram();
}



void printHorizontalHistogram() {

	char c;
	int state, wordLength, wordCount;

	state = OUT;
	wordLength = 0;
	wordCount = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\n' || c == ' ' || c == '\t') {

			if (state == IN)
			{
				for (int i = 0; i < wordLength; i++)
					printf("#");
				printf("\n");
				wordLength = 0;
			}
			state = OUT;
		}
		else if (state == OUT)
		{
			wordCount++;
			state = IN;
		}

		if (state == IN)
			wordLength++;
	}
}