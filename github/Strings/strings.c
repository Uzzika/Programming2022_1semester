#include <stdio.h>
#include <malloc.h>
#include <locale.h>

void replacementString(strin) {
	setlocale(LC_ALL, "rus");
	printf("")
	gets(strin);
	puts(strin);
}

int main() {
	setlocale(LC_ALL, "rus");
	char* str;
	str = (char*)malloc(sizeof(char) * 1000);

	printf("¬ведите строку длиной < 1000\n");
	
	gets(str);  //scanf

	replacementString(str);

	free(str);
	return 0;
}
