#include <iostream>
#include "Header.h"

int main() {
	std::vector<int> t2 = { 2, 1, 4, 3, 5 };
	mix(t2);
	for (int x : t2) {
		std::cout << x << " ";
	}
	system ("pause");
}