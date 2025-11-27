#ifndef Queue
#define Queue

#include <stdexcept>

template <typename T>
class Node {
public:
	T val;
	Node* next;
	Node(const T& data = T(), Node* nxt = nullptr) : val(data), next(nxt) {};
};

template <typename T>
class LinkedListBasedQueue {
private:
	Node<T>* front = nullptr;
	Node<T>* cur = nullptr;
	int size = 0;
public:
	LinkedListBasedQueue();
	~LinkedListBasedQueue();

	LinkedListBasedQueue(const LinkedListBasedQueue& q);

	bool operator ==(const LinkedListBasedQueue& q);
	bool isEmpty() const {return front == nullptr;}
	void Push(const T& data);
	void Pop();
	T& Front();
	const T& Front() const;
	int& GetQueueLength() { return size; }
	const int& GetQueueLength() const { return size; }
};

template <typename T>
LinkedListBasedQueue<T>::LinkedListBasedQueue() : front(nullptr), cur(nullptr) {}

template <typename T>
LinkedListBasedQueue<T>::~LinkedListBasedQueue() {
	while (!isEmpty()) {
		Pop();
	}
}

template <typename T>
LinkedListBasedQueue<T>::LinkedListBasedQueue(const LinkedListBasedQueue& q) {
	size = q.size;
	Node<T>* temp = q.front;
	while (temp != nullptr) {
		Push(temp->val);
		temp = temp->next;
	}
}

template <class T>
bool LinkedListBasedQueue<T>::operator ==(const LinkedListBasedQueue<T>& q) {
	if (size != q.size) return false;
	Node<T>* temp1 = front;
	Node<T>* temp2 = q.front;
	while (temp1 != nullptr) {
		if (temp1->val != temp2->val) return false;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return true;
}

template <class T>
void LinkedListBasedQueue<T>::Push(const T& data) {
	Node<T>* newNode = new Node<T>(data, nullptr);
	if (isEmpty()) {
		front = newNode;
		cur = newNode;
	}
	else {
		cur->next = newNode;
		cur = newNode;
	}
	size++;
}

template <class T>
void LinkedListBasedQueue<T>::Pop() {
	if (isEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	Node<T>* temp = front;
	front = front->next;
	delete temp;
	size--;
	if (isEmpty()) {
		cur = nullptr;
	}
}
template <class T>
T& LinkedListBasedQueue<T>::Front() {
	if (isEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	return front->val;
}

template <class T>
const T& LinkedListBasedQueue<T>::Front() const {
	if (isEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	return front->val;
}

template <typename T>
class ArrayBasedQueue {
private:
	T* data;
	int front, rear;
	int capacity = 0, size = 0;
	void resize(int newCapacity);
public:
	ArrayBasedQueue();
	~ArrayBasedQueue();
	ArrayBasedQueue(const ArrayBasedQueue& q);

	bool operator ==(const ArrayBasedQueue& q);
	void Push(const T& item);
	void Pop();
	T& Front();
	const T& Front() const;
	int& GetQueueLength() { return size; }
	const int& GetQueueLength() const { return size; }
	int& GetCapacity() { return capacity; }
	const int& GetCapacity() const { return capacity; }
	bool isEmpty() const { return size == 0; }
};

template <typename T>
ArrayBasedQueue<T>::ArrayBasedQueue() : front(0), rear(0), capacity(2048), size(0) {
	data = new T[capacity];
}

template <typename T>
ArrayBasedQueue<T>::~ArrayBasedQueue() {
	delete[] data;
}

template <typename T>
ArrayBasedQueue<T>::ArrayBasedQueue(const ArrayBasedQueue& q) {
	capacity = q.capacity;
	size = q.size;
	front = q.front;
	rear = q.rear;
	data = new T[capacity];
	for (int i = 0; i < capacity; i++) {
		data[i] = q.data[i];
	}
}
template <class T>
bool ArrayBasedQueue<T>::operator ==(const ArrayBasedQueue<T>& q) {
	if (size != q.size) return false;
	for (int i = 0; i < size; i++) {
		if (data[(front + i) % capacity] != q.data[(q.front + i) % q.capacity]) return false;
	}
	return true;
}

template <class T>
void ArrayBasedQueue<T>::Push(const T& item) {
	if (size == capacity) {
		resize(capacity * 2);
	}
	data[rear] = item;
	rear = (rear + 1) % capacity;
	size++;
}

template <class T>
void ArrayBasedQueue<T>::Pop() {
	if (isEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	front = (front + 1) % capacity;
	size--;
}

template <class T>
T& ArrayBasedQueue<T>::Front() {
	if (isEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	return data[front];
}

template <class T>
const T& ArrayBasedQueue<T>::Front() const {
	if (isEmpty()) {
		throw std::out_of_range("Queue is empty");
	}
	return data[front];
}


template <class T>
void ArrayBasedQueue<T>::resize(int newCapacity) {
	T* newData = new T[newCapacity];
	for (int i = 0; i < size; i++) {
		newData[i] = data[(front + i) % capacity];
	}
	delete[] data;
	data = newData;
	capacity = newCapacity;
	front = 0;
	rear = size;
}

#endif