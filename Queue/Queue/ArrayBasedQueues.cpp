#include "Queues.h"

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
const T& ArrayBasedQueue<T>::Front() const{
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