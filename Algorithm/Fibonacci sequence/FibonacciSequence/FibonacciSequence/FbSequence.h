#ifndef FbSequence_H
#define FbSequence_H

#include <vector>

class FbSequence {
private:
	int FbSequence_Length = 0;
	std::vector<std::vector<int>> FbSequence_Container;
	void Clear();
	std::vector<int> ADD (std::vector<int> SequenceNum1, std::vector<int> SequenceNum2); 
	void Initialize();
	void Copy(std::vector<int>& Target, const std::vector<int>& Source);
public:
	FbSequence() { Initialize(); }
	~FbSequence() { Clear(); }
	void FbSequence_Get(const int& num = 1);
	void FbSequence_Traverse();
};

#endif 
