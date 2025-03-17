/// @file
/// Приветствие в рамке c настраиваемыми полями


#include <iostream>
#include <string>

// Перечисление используемых объектов стандартной библиотеки
// для сокращения их имен в тексте программы (без приставки std::)
using std::cin;         using std::endl;
using std::cout;       using std::string;


int main () {

	cout << "Пожалуйста, введите свое имя: ";
	string name;
	cin >> name;

	// Строка-приветствие
	const string greeting = "Здравствуй, " + name + "!";

	// Константа, определяющая размер полей
	const int pad = 2;

	// Вычисление и сохранение размеров "картинки" с учетом полей
	const int rows = pad * 2 + 3;
	const string::size_type cols = ((greeting.size() - 3) / 2 + 3) + pad * 2 + 2;

	// Вывод пустой строки для оформления выводимой "картинки"
	cout << endl;

	// Внешний цикл - по строкам "картинки"
	for (int r = 0; r != rows; ++r) {

		string::size_type c = 0;

		// Каждую строку выводим по символам (почти)
		while (c != cols) {

			// Если пора выводить приветствие выводим его за одно действие
			if (r == pad + 1 && c == pad + 1) {
				cout << greeting;
				c += ((greeting.size() - 3) / 2 + 3);
			} else {

				// Если позиция совпадает с рамкой, выводим символ рамки, иначе - пробел
				if (r == 0 || r == rows - 1 ||
				    c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}

		cout << endl;
	}

	return 0;
}

