#include <iostream>
#include <vector>

//int Fibonacci_Sequence(int n) {
//	if (n <= 0) return 0;
//	if (n == 1) return 1;
//	return Fibonacci_Sequence(n - 1) + Fibonacci_Sequence(n - 2);
//}

std::vector<int> FbSequence_Add(std::vector<int> SequenceNum1, std::vector<int> SequenceNum2) {
	std::vector<int> Temp;
	
	std::vector<int> Result;
	for (int i = Temp.size() - 1; i >= 0; --i) {
		if (Temp[i] >= 10 && i > 0) {
			Temp[i - 1] += Temp[i] / 10;
			Temp[i] = Temp[i] % 10;
		}
	}
	if (Temp[0] >= 10) {
		Result.push_back(Temp[0] / 10);
		Temp[0] = Temp[0] % 10;
	}
	for (int num : Temp) {
		Result.push_back(num);
	}
	return Result;
}

std::vector<int> FbSequence_AddForEach(std::vector<int> SequenceNum1, std::vector<int> SequenceNum2) {
	std::vector<int> Temp;
	int NumSize = SequenceNum2.size();
	int ResultSize = SequenceNum1.size();
	Temp.resize(ResultSize);
	for (int i = 0; i < ResultSize - NumSize; ++i) {
		Temp.push_back(0);
	}
	for (int num : SequenceNum1) {
		Temp.push_back(num);
	}
	std::vector<int> Result;
	int i = 0;
	for (int num : SequenceNum2) {
		Result.push_back(num + Temp[i]);
		++i;
	}
}

void Squence_Traverse(std::vector<int> SquenceNum) {
	for (int num : SquenceNum) {
		std::cout << num;
	}
	std::cout << " ";
}

int main() {
	int Length_Fibonacci = -1;

	std::cout << "Enter the length of the Fibonacci sequence: ";
	std::cin >> Length_Fibonacci;

	while (Length_Fibonacci < 0)
	{
		if (Length_Fibonacci <= 0) {
			std::cout << "Invalid Input." << std::endl;
		}
	}

	//for (int i = 1; i <= Length_Fibonacci; i++) {
	//	std::cout << Fibonacci_Sequence(i) << " ";
	//}	
//--------------------------------------------------------------
	//std::vector<int> Fibonacci_Sequence;
	//Fibonacci_Sequence.push_back(0);
	//Fibonacci_Sequence.push_back(1);
	//if (Length_Fibonacci > 1) {
	//	for (int i = 2; i < Length_Fibonacci; i++) {
	//		Fibonacci_Sequence.push_back(Fibonacci_Sequence[i - 1] + Fibonacci_Sequence[i - 2]);
	//	}
	//}

	//for (int num : Fibonacci_Sequence) {
	//	std::cout << num << " ";
	//}
//--------------------------------------------------------------
	std::vector<std::vector<int>> Fibonacci_Sequence;
	Fibonacci_Sequence.push_back({ 0 });
	Fibonacci_Sequence.push_back({ 1 });
	for (int i = 2; i <= Length_Fibonacci; i++) {
		Fibonacci_Sequence.push_back(FbSequence_Add(Fibonacci_Sequence[i - 1], Fibonacci_Sequence[i - 2]));
	}
	for (const auto& SequenceNum : Fibonacci_Sequence) {
		if (SequenceNum[0] == 0) {
			continue;
		}
		Squence_Traverse(SequenceNum);
	}
}