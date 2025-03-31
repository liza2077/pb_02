#include "Median.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

using std::sort;
using std::vector;

double median(std::vector<double> vec) {
	size_t size = vec.size();
	if (size == 0) throw std::domain_error("Вектор пуст! Вычисление медианы невозможно.");

	sort(vec.begin(), vec.end());
	size_t mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
} 