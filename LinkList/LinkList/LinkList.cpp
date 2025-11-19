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
	SingleLinkList() : head(nullptr) {};

	void InsertToHead(T val) {
		SingleLinkListNode<T>* temp = new SingleLinkListNode<T>(val);
		temp->next = head;
		head = temp;
	}

	void InsertToTail(T val) {
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

	void Insert(T val, int index) {
		if (index == 0) {
			InsertToHead(val);
			return;
		}
		SingleLinkListNode<T>* temp1 = new SingleLinkListNode<T>(val);
		SingleLinkListNode<T>* temp2 = head;
		for (int i = 0; i < index - 1; i++) {
			if (temp2 == nullptr) {
				std::cout << "Index out of bounds\n";
				delete temp1;
				return;
			}
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
	}

	void traverse(){
		SingleLinkListNode<T>* current = head;
		std::cout << "List is:";
		while (current) {
			std::cout << ' ' << current->val;
			current = current->next;
		}
		std::cout << '\n';
	}

	int GetLength() {
		SingleLinkListNode<T>* current = head;
		int length = 0;
		while (current) {
			length++;
			current = current->next;
		}
		return length;
	}

	void DeleteNode(int index) {
		if (head == nullptr) {
			std::cout << "List is empty\n";
			return;
		}
		if (index > GetLength() - 1) {
			std::cout << "Index out of bounds\n";
			return;
		}else if (index == 0) {
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

	T GetNodeValue(int index) {
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
	void ClearList() {
		SingleLinkListNode<T>* current = head;
		while (current) {
			SingleLinkListNode<T>* temp = current;
			current = current->next;
			delete temp;
		}
		head = nullptr;
	}
private:
	SingleLinkListNode<T>* head;
};

int main() {
	SingleLinkList <const char*> List;
	List.InsertToTail("!");
	List.InsertToHead("world");
	List.InsertToHead("Hello");
	List.InsertToTail("My name is Yangcy");
	List.Insert("Woooh~", 0);
	List.traverse();
	List.ClearList();
	List.traverse();
}