#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::ostream;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;


//==============================================================================
// Функция, вычисляющая медиану набора чисел типа double
// Параметр vec передается по значению, т.е. при вызове функции создается внутренняя копия вектора
// Копирование требуется, потому что вычисление медианы требует изменения порядка элементов вектора
double median (vector<double> vec) {
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("Вектор пуст! Вычисление медианы невозможно.");

	sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}


//==============================================================================
// Функция, вычисляющая итоговую оценку по трем числам: оценке за КР, оценке за экзамен и медиане оценок за СР
// Предполагается, что медиана оценок СР вычислена ранее
double grade (double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


//==============================================================================
// Вариант функции grade, использующий в качестве третьего параметра
// вектор оценок за СР.
double grade (double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("Отсутствуют оценки за самостоятельные работы!");
	return grade(midterm, final, median(hw));
}


//==============================================================================
// Функция, считывающая оценки за СР из потока ввода и помещающая их в динамический массив
istream& read_hw (istream& in, vector<double>& hw) {
	if (in) {
		// Очистка вектора, кроме считанных оценок других данных в векторе быть не должно
		hw.clear();

		// Считывание оценок за СР
		double x;
		while (in >> x)
			hw.push_back(x);

		// При считывании EOF поток "ломается", для дальнейших считываний приводим поток в исходное состояние
		in.clear();
	}
	char b;
	in >> b;
	return in;
}


//==============================================================================
int main () {
	// Запрашиваем имя студента и выводим приветствие
	cout << "Пожалуйста, введите своё имя: ";
	string name;
	cin >> name;
	cout << "Здравствуй, " << name << "!" << endl;

	// Запрашиваем и считываем оценки за контрольную работу и экзамен
	cout << "Введите оценки за контрольную работу и экзамен: ";
	double midterm, final;
	cin >> midterm >> final;

	// Запрашиваем оценки за самостоятельные работы
	cout << "Введите ваши оценки за самостоятельные работы, "
	        "завершив ввод признаком EOF (end of file): ";

	vector<double> homework;

	// Считываем оценки за СР
	read_hw(cin, homework);

	// Пытаемся вычислить итоговую оценку, если это возможно
	try {
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << name << ", ваша итоговая оценка: " << setprecision(3)
		     << final_grade << setprecision(prec) << endl;
	} catch (domain_error) {
		cout << endl << "Необходимо ввести оценки за самостоятельные работы!  "
			"Попробуйте еще раз." << endl;
		return 1;
	}

	return 0;
}

