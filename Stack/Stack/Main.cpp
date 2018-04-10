#include <iostream>
#include <cstdlib>
#include "Stack.h"
int main()
{
	Stack<int> s;
	std::cout << s.size() << " " << s.capacity()<<"\n";
	for (int i = 0; i < 8; ++i) {
		s.push(i);
		std::cout <<"size: "<< s.size() << "  capacity: " << s.capacity()<<"  top: "<<s.Top()<<"\n";
	}
	while (!s.empty()) {
		s.pop();
		std::cout << "size: " << s.size() << "  capacity: " << s.capacity() << "  top: " << s.Top() << "\n";
	}
	system("pause");
	return 0;
}