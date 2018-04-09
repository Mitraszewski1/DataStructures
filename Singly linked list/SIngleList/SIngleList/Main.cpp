#include <iostream>
#include <cstdlib>
#include "List.h"
int main()
{
	int n;
	std::cin >> n;
	List<int> L;
	for (size_t i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		Node<int>* t = new Node<int>(x);
		L.Push_back(t);
		L.Print();
	}
	L.Delete_first();
	L.Print();
	L.Delete_last();
	L.Print();
	system("pause");
	return 0;
}