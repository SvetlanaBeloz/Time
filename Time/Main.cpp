#include "Time.h"

int main()
{
	Time current;
	std::cout << current;

	Time a(1, 50, 45);
	std::cout << a--;
	a.Print();
	

	Time b;
	b = a + 1200;
	b.Print();

	if (a > b)
		std::cout << "ok!\n";
	else std::cout << "no!\n";

	if (a < b)
		std::cout << "ok!\n";
	else std::cout << "no!\n";

	if (a == b)
		std::cout << "ok!\n";
	else std::cout << "no!\n";

	if (a != b)
		std::cout << "ok!\n";
	else std::cout << "no!\n";

	Time c;
	std::cin >> c;
	std::cout << c;
}