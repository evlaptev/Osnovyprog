// Лаба 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream> 
int main(void)
{
	// описание переменных 
	float V; // обьем бассейна 
	float v1; // скорость вытекания воды 
	float t; // время 
	float v2; // искомая скорость наполнения бассейна 
	float v0; // разность скоростей 
	// ввод исходных данных 
	// вывод на экран подсказки: V = 
	printf("V = ");
	// ввод с клавиатуры значения переменной V 
	scanf_s("%f", &V);
	// вывод на экран подсказки: v1 = 
	printf("v1 = ");
	// ввод с клавиатуры значения переменной v1 
	scanf_s("%f", &v1);
	// вывод на экран подсказки: t = 
	printf("t = ");
	// ввод с клавиатуры значения переменной t 
	scanf_s("%f", &t);
	// решение задачи 
	v0 = V / t; // вычисление разности скоростей 
	v2 = v0 - v1;// вычисление искомой скорости наполнения бассейна 
	// вывод результатов 
	// вывод на экран значения переменной v2 
	printf("speed = %f\n", v2);
	// программа возвращается признак корректного 
	// завершения 
	getchar();
	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
