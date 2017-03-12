#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char str[] = "Welcome To C++ Study";
	char *chp;
	chp = (char *)malloc(sizeof(char) * strlen(str));
	strcpy(chp, str);
	printf("chp : %s\n", chp);

	getchar();

	free(chp);
	return 0;
}