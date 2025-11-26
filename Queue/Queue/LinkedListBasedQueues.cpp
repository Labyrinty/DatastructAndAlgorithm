#include "Queues.h"

template <typename T>
LinkedListBasedQueue<T>::LinkedListBasedQueue() : front(nullptr), cur(nullptr) {}

template <typename T>
LinkedListBasedQueue<T>::~LinkedListBasedQueue() {
	while (!isEmpty()) {
		Pop();
	}
}

template <typename T>
LinkedListBasedQueue<T>::LinkedListBasedQueue(const LinkedListBasedQueue& q){
	size = q.size;
	Node* temp = q.front;
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