#include <stdio.h>
#include <locale.h>
#include <time.h>

int main() {

	setlocale(LC_ALL, "rus");
	srand(time(0));

	int n = 0;
	int mass[100000];

	printf("������� ����� ������� < 100000: ");
	while (n <= 0 || n > 100000) {
		scanf_s("%d", &n);
	}

	for (int i = 0; i < n; i++) {
		mass[i] = -10 + rand() % 21;
		printf("%d ", mass[i]);
	}
	int numb;

	printf("\n������� ����� �����: ");
	scanf_s("%d", &numb);

	for (int i = 0; i < n; i++) {
		if (mass[i] % numb == 0) {
			mass[i] = mass[i] * mass[i];
		}
		printf("%d ", mass[i]);
	}

	printf("\n������ � �������� �������: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", mass[n - i - 1]);
	}
	int a;

	printf("\n������ � �������� ������� �� �����: \n");
	for (int i = 0; i < n; i++) {
		a = mass[i];
		mass[i] = mass[n - i - 1];
		mass[n - i - 1] = a;
		printf("%d ", mass[i]);
	}
	return 0;
}