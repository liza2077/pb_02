#include "Student_info.h"
#include <iostream>
#include <string>
#include <vector>

using std::istream;
using std::string;
using std::vector;


//==============================================================================
bool compare (const studentInfo& x, const studentInfo& y) {
	return x.name < y.name;
}

//==============================================================================
istream& read_hw (istream& in, vector<double>& hw) {
	if (in) {
		hw.clear();

		for (double x; in >> x;) hw.push_back(x);

		in.clear();
	}
	return in;
}


//==============================================================================
istream& read (istream& is, studentInfo& s) {
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);

	return is;
}