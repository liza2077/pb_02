#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::max;
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::ostream;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

// Определение структуры, предназначенной для хранения данных студента
struct Student_info {
	string name;  // Имя
	double midterm; // Оценка за КР
	double final;  // Оценка за экзамен
	vector<double> homework;  // Вектор оценок за самостоятельные работы
};	
// Точка с запятой здесь нужна!
//==============================================================================
// Функция, вычисляющая медиану вектора чисел типа double
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
// Функция, реализующая базовую формулу расчета итоговой оценки
double grade (double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
//==============================================================================
// Функция расчета итоговой оценки по КР, экзамену и вектору оценок за СР
double grade (double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("Отсутствуют оценки за самостоятельные работы!");
	return grade(midterm, final, median(hw));
}
//==============================================================================
// Функция, вычисляющая итоговую оценку студента по данным его записи
double grade (const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}
//==============================================================================
// Функция, считывающая оценки студента за СР из потока ввода
istream& read_hw (istream& in, vector<double>& hw) {
	if (in) {
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}

	char b;
	in >> b;

	return in;
}

//==============================================================================
// Функция, считывающая данные студента из потока ввода
istream& read (istream& is, Student_info& s) {
	// Считываем имя студента и оценки за КР и экзамен
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);  // Считываем оценки за СР в индивидуальный вектор студента
	return is;
}
//==============================================================================
// Определяем смысл сравнения двух записей о студентах (по алфавитному порядку имен)
bool compare (const Student_info& x, const Student_info& y) {return x.name > y.name;
}


//==============================================================================
int main () 
{
    // Готовим вектор для записей, запись для считывания данных, переменную для размера самого длинного имени
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	// Считываем данные об аттестации студентов, сохраняя их в векторе (по записи на каждого студента)
    // При считывании вычисляем длину имени и ищем максимальную
	while (read(cin, record)) {maxlen = max(maxlen, record.name.size() / 2);
		students.push_back(record);
	}

	// Сортируем записи о студентах по алфавиту
	sort(students.begin(), students.end(), compare);
	for (vector<Student_info>::size_type i = 0;
	     i != students.size(); ++i) {

		// Выводим имя студента и пробелы для выравнивания оценок
		cout << students[i].name << string(maxlen + 5 - students[i].name.size() / 2, '.');

		// Вычисляем (если получится) и выводим итоговую оценку
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e) {
			// Если оценку вычислить невозможно, выводим сообщение об ошибке (но программу не завершаем, обрабатываем записи других студентов)
			cout << e.what();
		}

		cout << endl;
	}

	return 0;
}