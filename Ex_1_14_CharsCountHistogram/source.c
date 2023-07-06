/*
*	Summary
*	- draw vertical histogram its height represents number of uses for each char..
* 	- allow multiple lines, use EOF to finish,
*		"enter an empty line and press ctrl+z to enter EOF in console".
*/


#include <stdio.h>

#define IN 1
#define OUT 0
#define UPPER_OFFSET 65
#define LOWER_OFFSET 97
#define CHAR_COUNT 26

void printHorizontalHistogram();
void printVerticalHistogram();



int main() {

	printf("\n\n\t#### Chars Histogram ####\n");
	printf("\tEnter any text (new lines are allowed) to count its characters occurrence.\n");
	printf("\t\"To finish typing, enter EOF (Ctrl+Z in Windows) in empty line then press Enter\"\n\n");
	printVerticalHistogram();
}



void printHorizontalHistogram()
{

	char c;
	int state;
	int charOffset = UPPER_OFFSET;
	int chars[CHAR_COUNT];

	state = OUT;
	for (int i = 0; i < CHAR_COUNT; i++)
	{
		chars[i] = 0;
	}


	while ((c = getchar()) != EOF)
	{
		if (c >= 'A' && c <= 'Z')
			c += 32;

		if (c >= 'a' && c <= 'z')
			chars[c - 'a']++;
	}

	for (int i = 0; i < CHAR_COUNT; i++)
	{
		if (chars[i] != 0) {
			printf("%c\t", charOffset + i);
			for (int j = 0; j < chars[i]; j++)
			{
				printf("#");
			}
			printf("\n");
		}
	}

}


void printVerticalHistogram()
{
	char c;
	int state;
	int charOffset = UPPER_OFFSET;
	int chars[CHAR_COUNT];

	state = OUT;
	for (int i = 0; i < CHAR_COUNT; i++)
	{
		chars[i] = 0;
	}


	while ((c = getchar()) != EOF)
	{
		if (c >= 'A' && c <= 'Z')
			c += 32;

		if (c >= 'a' && c <= 'z')
			chars[c - 'a']++;
	}

	// get max count
	int max = 0;
	for (int i = 0; i < CHAR_COUNT; i++)
	{
		if (chars[i] > max)
			max = chars[i];
	}

	printf("\n\n\n");

	// draw vertical histogram
	for (int i = max; i > 0; i--)
	{
		for (int j = 0; j < CHAR_COUNT; j++)
		{
			if (chars[j] >= i)
				printf("# ");
			else
				printf("  ");
		}

		printf("\n");
	}
	for (int i = 0; i < CHAR_COUNT; i++)
	{
		printf("%c ", charOffset + i);
	}

	printf("\n\n\n");
}