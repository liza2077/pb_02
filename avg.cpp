#include <iomanip>
#include <ios>
#include <iostream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;


int main () {
	// Запрос имени студента и вывод приветствия
	cout << "Пожалуйста, введите ваше имя: ";
	string name;
	cin >> name;
	cout << "Здравствуй, " << name << "!" << endl;

	// Запрос оценок за контрольную работу и экзамен и считывание их
	cout << "Введите свои оценки за контрольную работу и экзамен: ";
	double midterm, final;
	cin >> midterm >> final;

	// Запрос оценок за самостоятельные работы
	cout << "Введите оценки за самостоятельные работы, "
	        "после завершения списка введите команду завершения ввода (Ctrl-D): ";

	// В процессе считывания оценок за самостоятельные работы суммируем их и подсчитываем количество оценок
	int count = 0;
	double sum = 0;

	// Переменная для очередной оценки за СР
	double x;

	//  Пока из потока считываются оценки, считываем, суммируем и подсчитываем их
	while (cin >> x) {
		++count;
		sum += x;
	}

	// Выводим сообщение об итоговой оценке и саму оценку, окончательный расчет выполняем непосредственно при выводе
	streamsize prec = cout.precision();{
	cout << name << ", ваша итоговая оценка: " << setprecision(3)
	     << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
	     << setprecision(prec) << endl;

	return 0;

}
}
