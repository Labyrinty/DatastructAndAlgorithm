#include <iostream>
#include <vector>
#include <cstring>

template<class T>
class SingleLinkListNode {
public:
	T val;
	SingleLinkListNode* next;

	SingleLinkListNode(T a) : val(a), next(NULL) {};
	SingleLinkListNode(SingleLinkListNode* temp) : val(NULL), next(temp) {};
	SingleLinkListNode(T a, SingleLinkListNode* temp) : val(a), next(temp) {};
};

template <class T>
class SingleLinkList {
public:
	void InsertToHead(T val);
	void InsertToTail(T val);
	void Insert(T val, int index);
	void traverse();
	void DeleteNode(int index);
	void ClearList();
	void Reverse();
	int GetLength();
	T GetNodeValue(int index);
private:
	SingleLinkListNode<T>* head = nullptr;
};

template<class T>
void SingleLinkList<T>::InsertToHead(T val) {
	SingleLinkListNode<T>* temp = new SingleLinkListNode<T>(val);
	temp->next = head;
	head = temp;
}

template<class T>
void SingleLinkList<T>::InsertToTail(T val) {
	SingleLinkListNode<T>* temp1 = new SingleLinkListNode<T>(val);
	SingleLinkListNode<T>* temp2 = head;
	if (head == nullptr) {
		head = temp1;
		return;
	}
	while (temp2->next) {
		temp2 = temp2->next;
	}
	temp2->next = temp1;
}

template<class T>
void SingleLinkList<T>::Insert(T val, int index) {
	if (index == 1) {
		InsertToHead(val);
		return;
	}
	else if (index == 0) {
		std::cout << "It'ld start for 1";
		return;
	}

	if (index > GetLength()) {
		std::cout << "Index out of bounds\n";
		return;
	}

	SingleLinkListNode<T>* temp1 = new SingleLinkListNode<T>(val);
	SingleLinkListNode<T>* temp2 = head;
	for (int i = 0; i < index - 1; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

template<class T>
void SingleLinkList<T>::traverse() {
	SingleLinkListNode<T>* current = head;
	std::cout << "List is:";
	while (current) {
		std::cout << ' ' << current->val;
		current = current->next;
	}
	std::cout << '\n';
}

template<class T>
int SingleLinkList<T>::GetLength() {
	SingleLinkListNode<T>* current = head;
	int length = 0;
	while (current) {
		length++;
		current = current->next;
	}
	return length;
}

template<class T>
void SingleLinkList<T>::DeleteNode(int index) {
	if (head == nullptr) {
		std::cout << "List is empty\n";
		return;
	}
	if (index > GetLength()) {
		std::cout << "Index out of bounds\n";
		return;
	}
	else if (index == 0) {
		std::cout << "Index starts from 1\n";
		return;
	}

	if (index == 1) {
		SingleLinkListNode<T>* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	SingleLinkListNode<T>* current = head;
	for (int i = 0; i < index - 2; i++) {
		current = current->next;
	}
	SingleLinkListNode<T>* temp = current->next;
	current->next = temp->next;
	delete temp;
}

template<class T>
void SingleLinkList<T>::Reverse() {
	SingleLinkListNode<T> *current, *prev, *next;
	current = head;
	prev = nullptr;
	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

template<class T>
T SingleLinkList<T>::GetNodeValue(int index) {
	if (index >= GetLength()) {
		std::cout << "Index out of bounds\n";
		return T();
	}
	SingleLinkListNode<T>* current = head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->val;
}

template<class T>
void SingleLinkList<T>::ClearList() {
	SingleLinkListNode<T>* current = head;
	while (current) {
		SingleLinkListNode<T>* temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
}

int main() {
	SingleLinkList <const char*> List;
	List.InsertToTail("!");
	List.InsertToHead("world");
	List.InsertToHead("Hello");
	List.InsertToTail("My name is Yangcy");
	List.Insert("Wooh~", 4);
	List.traverse();
	List.ClearList();
	List.traverse();
	SingleLinkList<int> numList;
	numList.InsertToHead(2);
	numList.InsertToHead(1);
	numList.InsertToHead(0);
	numList.InsertToHead(-1);
	numList.traverse();
	numList.Reverse();
	numList.traverse();
}