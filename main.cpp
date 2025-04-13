#include "locale_string.h"
#include "student_info.h"
#include "grade.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


//==============================================================================
int main () {
	std::vector<Student_info> students;
	std::size_t maxlen = 0;

	for (Student_info record; read(std::cin, record);) {
		maxlen = std::max(maxlen, string_lenght(record.name));
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (std::size_t i = 0; i != students.size(); ++i) {

		std::cout << students[i].name
		     << std::string(maxlen + 2 - string_lenght(students[i].name), ' ');

		try {
			double final_grade = grade(students[i]);
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade << std::setprecision(prec);
		}
		catch (std::domain_error e) {
			std::cout << e.what();
		}

		std::cout << std::endl;
	}

	return 0;
}
