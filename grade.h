#ifndef GRADE_H
#define GRADE_H

#include "student_info.h"

#include <vector>


double grade(double midterm, double final, double homework);

double grade(double midterm, double final, const std::vector<double>& hw);

double grade(const Student_info& s);

#endif // GRADE_H
