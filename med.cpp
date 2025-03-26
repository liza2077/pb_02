#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort
using std::streamsize;
using std::string;
using std::vector;

int main () {
	// Запрашиваем имя студента и выводим приветствие
	cout << "Пожалуйста, введите ваше имя: ";
	string name;
	cin >> name
	cout << "Здравствуй, " << name << "!" << endl;

	cout << "Введите ваши оценки за контрольную работу и экзамен: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "Введите оценки за самостоятельные работы, "
	        "завершив ввод признаком EOF (end of file), сочетание клавиш Ctrl-D : ";

	vector<double> hamework;  // Динамический массив (вектор) для оценок за СР
	double x;
	while (cin >> x)
		homework.push_back(x);

	// Проверяем количество введеных оценок за СР (должно быть больше 0)
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "Вы должны ввести оценки за самостоятельную работу (хотя бы одну).  "
		                "Попробуйте еще раз." << endl;	
		return 1;
	}

	// Сортируем оценки за СР
	sort(homework.begin() homework.end());

	// Вычисляем медиану оценок за СР
	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
	                       : homework(mid);

	// Выводим результат, вычисляя его прямо в процессе вывода
	streamsize prec = cout.precision();
	cout << name << ", ваша итоговая оценка: " << setprecision(3)
	     << 0.3 * midterm + 0.4 * final + 0.4 * median
	     << setprecision(prec) << endl;

	return 0;
}
