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

	void traverse(){
		SingleLinkListNode<T>* current = head;
		std::cout << "List is:";
		while (current) {
			std::cout << ' ' << current->val;
			current = current->next;
		}
		std::cout << '\n';
	}
private:
	SingleLinkListNode<T>* head;
};

int main() {
	SingleLinkList <std::string> List;
	List.InsertToTail("!");
	List.InsertToHead("world");
	List.InsertToHead("Hello");
	List.InsertToTail("My name is Yangcy");
	List.traverse();
}