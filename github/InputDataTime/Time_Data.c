#include <stdio.h>
#include <locale.h>
#include <math.h>

// объ€вление главной функции
int main() {
	// настройки

	setlocale(LC_ALL, "rus");

	// объ€вление переменных

	int day, month, year, hour, minute, second;

	// инициализаци€

	printf("¬ведите дату: ");
	scanf_s("%d.%d.%d", &day, &month, &year);
	system("cls");
	printf("¬ведите врем€: ");
	scanf_s("%d:%d:%d", &hour, &minute, &second);
	system("cls");

	// выполнение задачи

	//вывод результата

	printf("я запомню %d.%d.%d %d:%d:%d\n", day, month, year, hour, minute, second);
	system("pause");
	return 0;
}
