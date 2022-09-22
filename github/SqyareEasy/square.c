#include <stdio.h>
#include <locale.h>
#include <math.h>

// объ€вление главной функции
int main() {
	// настройки
	setlocale(LC_ALL, "rus");

	// объ€вление переменных
	int a = 5, h = 3;
	float s;

	// инициализаци€
	
	printf("¬ведите основание и высоту треугольника (в формате <a h>): ");
	scanf_s("%d %d", &a, &h);

	// выполнение задачи
	s = 0.5 * a * h;

	//вывод результата
	printf("ѕлощадь треугольника со стороной %d и высотой %d равна %2f\n", a, h, s);
	system("pause");
	return 0;
}
