#ifndef Queues
#define Queues		

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

#endif
