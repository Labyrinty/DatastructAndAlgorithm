#ifndef MyStack
#define MyStack

#include <stdexcept>

template <typename T>
class LinkListBasedStack {
private:
	class Node {
	public:
		T val;
		Node* next;
		Node(const T& data = T(), Node* nxt = nullptr) : val(data), next(nxt) {};
	};

	Node* top;
	int capacity = 256, size = 0;
public:
	LinkListBasedStack() : top(nullptr) {};
	~LinkListBasedStack() {
		Clear();
		delete top;
	}
	void Push(const T& data);
	void Pop();
	void Clear();
	T& Top();
	const T& Top() const;
	bool IsEmpty() const;
};

template <class T>
void LinkListBasedStack<T>::Push(const T& data) {
	if (size == capacity) {
		throw std::overflow_error("Stack overflow, cannot push more elements.");
	}
	Node* newNode = new Node(data, top);
	top = newNode;
	++size;
}

template <class T>
void LinkListBasedStack<T>::Pop() {
	if (IsEmpty()) {
		throw std::underflow_error("Stack is empty, cannot pop.");
	}
	Node* temp = top;
	top = top->next;
	delete temp;
	--size;
}

template <class T>
void LinkListBasedStack<T>::Clear() {
	while (!IsEmpty()) {
		Pop();
	}
}

template <class T>
T& LinkListBasedStack<T>::Top() {
	if (IsEmpty()) {
		throw std::underflow_error("Stack is empty, cannot retrieve top element.");
	}
	return top->val;
}

template <class T>
const T& LinkListBasedStack<T>::Top() const {
	if (IsEmpty()) {
		throw std::underflow_error("Stack is empty, cannot retrieve top element.");
	}
	return top->val;
}

template <class T>
bool LinkListBasedStack<T>::IsEmpty() const {
	return top == nullptr;
}

template <typename T>
class ArrayBasedStack {
private:
	T* array;
	int capacity;
	int topIndex;
	int size = 0;
public:
	ArrayBasedStack() {
		capacity = 256;
		array = new T[capacity];
		topIndex = -1;
	}
	~ArrayBasedStack() {
		delete[] array;
	}
	void Push(const T& data);
	void Pop();
	void Clear();
	T& Top();
	const T& Top() const;
	bool IsEmpty() const;
};

template <class T>
void ArrayBasedStack<T>::Push(const T& data) {
	if (size == capacity) {
		throw std::overflow_error("Stack overflow, cannot push more elements.");
	}
	array[++topIndex] = data;
	++size;
}

template <class T>
void ArrayBasedStack<T>::Pop() {
	if (IsEmpty()) {
		throw std::underflow_error("Stack is empty, cannot pop.");
	}
	--topIndex;
	--size;
}

template <class T>
void ArrayBasedStack<T>::Clear() {
	while (!IsEmpty()) {
		Pop();
	}
}

template <class T>
T& ArrayBasedStack<T>::Top() {
	if (IsEmpty()) {
		throw std::underflow_error("Stack is empty, cannot retrieve top element.");
	}
	return array[topIndex];
}

template <class T>
const T& ArrayBasedStack<T>::Top() const {
	if (IsEmpty()) {
		throw std::underflow_error("Stack is empty, cannot retrieve top element.");
	}
	return  array[topIndex];
}

template <class T>
bool ArrayBasedStack<T>::IsEmpty() const {
	return topIndex == -1;
}

#endif 
