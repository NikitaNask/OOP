#include <vector>
#pragma once
template<typename T>
void mix(std::vector<T>& v) { 
	if (v.size() <= 1)
		return;
	for (size_t i = 0; i <= v.size() - 1 - (v.size() % 2); i += 2) {
		std::swap(v[i], v[i + 1]);
	}
}
