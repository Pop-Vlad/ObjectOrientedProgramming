#include <stdio.h>

int main()
{
	char some_message[100];
	scanf("%[^\n]s", &some_message);
	printf("%s", some_message);
	return 0;
}