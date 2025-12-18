#include "FbSequence.h"
#include <iostream>

void FbSequence::Initialize() {
	int Input_Length;
	std::cout << "Fibonacci Sequence Initialized." << std::endl;
	while (true) {
		std::cout << "Set Fibonacci Sequence Lenght:";
		std::cin >> Input_Length;
		if (Input_Length < 1) {
			std::cout << "Invalid Length Input." << std::endl;
		}
		else {
			FbSequence_Length = Input_Length;
			break;
		}
	}
	FbSequence_Container.clear();
	FbSequence_Container.push_back({ 0 });
	FbSequence_Container.push_back({ 1 });
	for (int i = 2; i <= FbSequence_Length; ++i) {
		FbSequence_Container.push_back(ADD(FbSequence_Container[i-1], FbSequence_Container[i-2]));
	}
}

std::vector<int> FbSequence::ADD(std::vector<int> SequenceNum1, std::vector<int> SequenceNum2) {
	std::vector<int> Result;
	std::vector<int> Temp;
	int carry = 0;
	int scale = SequenceNum1.size() - SequenceNum2.size();
	for (int i = 0; i < SequenceNum1.size(); ++i) {
		int Number = scale > i ? 0 : SequenceNum2[i - scale];
		Temp.push_back(SequenceNum1[i] + Number);
	}
	for (int i = Temp.size() - 1; i >= 0; --i) {
		Temp[i] += carry;
		carry = Temp[i] / 10;
		Temp[i] %= 10;
	}
	if (carry != 0) {
		Result.push_back(carry);
	}
	for (int i = 0; i < Temp.size(); ++i) {
		Result.push_back(Temp[i]);
	}
	return Result;
}

void FbSequence::Clear() {
	FbSequence_Container.clear();
}

void FbSequence::FbSequence_Get(const int& num) {
	std::vector<int> Temp;
	Copy(Temp, FbSequence_Container[num - 1]);
	for (int i = 0; i < Temp.size(); ++i) {
		std::cout << Temp[i];
	}
}
void FbSequence::FbSequence_Traverse() {
	for (int i = 1; i <= FbSequence_Length; ++i) {
		std::cout << "Num " << i << ": ";
		FbSequence_Get(i + 1);
		std::cout << std::endl;
	}
}

void FbSequence::Copy(std::vector<int>& Target, const std::vector<int>& Source) {
	Target.clear();
	for (int i = 0; i < Source.size(); ++i) {
		Target.push_back(Source[i]);
	}
}
