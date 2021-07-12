int errorCount;
char* errorMessage;

void throws(char message[])
{
	extern int errorCount;
	extern char* errorMessage;

	errorCount++;
	errorMessage = message;
}