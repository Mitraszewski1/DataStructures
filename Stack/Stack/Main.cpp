#include <iostream>
#include <cstdlib>
#include "Stack.h"
int main()
{
	Stack<int> s;
	std::cout << s.size() << " " << s.Capacity()<<"\n";
	for (int i = 0; i < 8; ++i) {
		s.push(i);
		std::cout << s.size() << " " << s.Capacity()<<" "<<s.Top()<<"\n";
	}
	system("pause");
	return 0;
}