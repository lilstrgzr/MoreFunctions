#include <iostream>

int NUM;//глобальная переменная
const double PI = 3.1415;//Глобальная константа
int ARR[3];//Глобальный массив

//Области применений статических элементов: 
//  1.Сохранение данных внутри функции для следующего её вызова
// 2.Щадащее отношение к памяти и быстродействию программы
// 3. Создание общей памяти для всех элементов, пренадлежащих одному множеству (классу или структуре)

void func() {
	static int a = 0;
	a++;
	std::cout << a << std::endl;
}

int power(int left, int right = 2) {
	int result = 1;
	for (int i = 1; i <= right; i++)
		result *= left;
	return result;
}


// Проблемы со встраиванием функции
// 1.Слишком большой размер функции
// 2.Функция повторяется в одном и том же выражении несколько раз
// 3. Функция содержит конструкции
// 4.Функция является рекурсивной
// 

inline int sum(int num1, int num2) {
	return(num1 + num2);
}

int max(int num1, int num2) {
	std::cout << "TWO INTS\n";
	return num1 > num2 ? num1 : num2;
}
double max(double num1, double num2) {
	std::cout << "TWO DOUBLES\n";
	return num1 > num2 ? num1 : num2;
}
char max(char sym1, char sym2) {
	std::cout << "TWO CHARS\n";
	return sym1 > sym2 ? sym1 : sym2;

}
int max(int num1, int num2, int num3) {
	std::cout << "THREE INTS\n";
	return max(max(num1, num2), num3);
}
//Все экземпляры перегруженной функции должны отличаться между собой по наборам параметров, а именно-их типам, или их колличествам.


template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}


int main() {
	setlocale(LC_ALL, "russian");
	int n, m;//Все локальные переменные строго ограничены блоком кода, в котором они были объявлены.

	//Области виидмости данных
	
	NUM = 7;
	std::cout << "NUM = " << NUM << std::endl;
	std::cout << "Pi = " << PI << std::endl;

	func();
	func();
	func();
	

	//Параметры по умолчанию
	
	std::cout << "7^2 = " << power(7 ) << std::endl;
	std::cout << "4^3 = " << power(4, 3) << std::endl;
	std::cout << "5^2 = " << power(5 ) << std::endl;
	std::cout << "10^5 = " << power(10, 5) << std::endl;
	

	//Встраиваемая функция
	
	std::cout << "Введите два числа -> ";
	std::cin >> n >>m;
	std::cout << n << " + " << m << " = " << sum(n, m) << std::endl;
	

	//Перегруженная функция
	
	std::cout << max(10, 8) << std::endl;
	std::cout << max(5.4, 5.04) << std::endl;
	std::cout << max('k', '0') << std::endl;
	std::cout << max(6, 23, 34) << std::endl;
	

	//Шаблонная функция
	const int size = 5;
	int arr[size]{ 7, 15, 42, 105, -77 };
	std::cout << "Массив:\n";
	print_arr(arr, size);






	return 0;
}