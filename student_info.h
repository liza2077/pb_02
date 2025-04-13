#ifndef STUDENT_INFO
#define STUDENT_INFO

#include <string>
#include <vector>
#include <iostream>


struct Student_info {
	std::string name;
	double midterm;
	double final;
	std::vector<double> homework;
};


std::istream& read_hw(std::istream& in, std::vector<double>& hw);
std::istream& read(std::istream& is, Student_info& s);
bool compare(const Student_info& x, const Student_info& y);


#endif // STUDENT_INFO
