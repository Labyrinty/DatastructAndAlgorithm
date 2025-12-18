#include <iostream>
#include "FbSequence.h"

void Run() {
	FbSequence Fibonacci_Sequence;
	int num = 0;
	std::cout << "Input Fibonacci Sequence Index to Get:";
	std::cin >> num;
	Fibonacci_Sequence.FbSequence_Get(num);
	Fibonacci_Sequence.FbSequence_Traverse();
}

int main() {
	Run();
	return 0;
}