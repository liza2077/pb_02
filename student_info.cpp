#include "student_info.h"



//==============================================================================
std::istream& read_hw (std::istream& in, std::vector<double>& hw) {
	if (in) {
		hw.clear();
		
		for (double x; in >> x;) hw.push_back(x);

		in.clear();
	}
	return in;
}


//==============================================================================
std::istream& read (std::istream& is, Student_info& s) {
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);

	return is;
}


//==============================================================================
bool compare (const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}
