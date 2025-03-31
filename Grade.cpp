#include "Grade.h"
#include "Median.h"
#include "Student_info.h"
#include <stdexcept>
#include <vector>

using std::vector;

//==============================================================================
double grade (double midterm, double final, double homework) {
	return (0.2 * midterm + 0.4 * final + 0.4 * homework);
}


//==============================================================================
double grade (double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0) throw std::domain_error("Отсутствуют оценки за самостоятельные работы!");

	return grade(midterm, final, median(hw));
}


//==============================================================================
double grade (const studentInfo& s) {
	return grade(s.midterm, s.final, s.homework);
}