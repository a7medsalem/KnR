/*
*	Summary
*	- read only lines that exceed limit of 80 chars, ignore shorter lines.
*/

#include <stdio.h>

#define MAXLINE 1000
#define PRINTLIMIT 80

int getLine(char[], int);


int main() {

	FILE* file = freopen("testfile.txt", "r", stdin);

	int len;
	char line[MAXLINE];

	printf("VVVVV\t\t\tThis is 80 char-line-length.\t\t\tVVVVV\n");
	printf("01234567890123456789012345678901234567890123456789012345678901234567890123456789\n\n");

	while ((len = getLine(line, MAXLINE)) > 0)
	{
		if (len > PRINTLIMIT) {
			printf("%s\b", line);
		}
	}


	fclose(stdin);
	return 0;
}


int getLine(char line[], int limit) {

	// read chars from line unless it's end of file or new line or exceed the limit.
	int c = '\0', i = 0;
	for (; i < limit-1 && (c=getchar())!=EOF && c!='\n'; i++)
		line[i] = c;
	
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';


	if (i == limit - 1) {
		while ((c = getchar()) != EOF && c != '\n')
			i++;
	}

	return i;
}

