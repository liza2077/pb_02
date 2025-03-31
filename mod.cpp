#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Student_info.h"
#include "Grade.h"

using std::max;

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

int main () {
	vector<studentInfo> students;
	string::size_type maxlen = 0;
	for (studentInfo record; read(cin, record);) {
		maxlen = max(maxlen, record.name.size() / 2);
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);


	for (vector<studentInfo>::size_type i = 0; i != students.size(); ++i) {

		cout << students[i].name
		<< string(maxlen + 4 - students[i].name.size() / 2, '.');

		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}