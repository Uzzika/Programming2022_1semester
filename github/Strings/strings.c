#include <stdio.h>
#include <malloc.h>
int main() {
	char* str;
	str = (char*)malloc(sizeof(char) * 100);

	gets(str);  //scanf


	int size = 0;
	while (str[size] != '\0') {
		size++;
	}

	str[5] = '\0';
	puts(str);  //printf


	printf("String %s have len %d", str, size);
	free(str);
	return 0;
}