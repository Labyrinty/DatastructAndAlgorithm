#include <iostream>
#include "Queues.h"
#include <string>
#include <cassert>
#include <vector>

int main() {
	LinkedListBasedQueue<std::string> llbq;
	llbq.Push("Hello");
	llbq.Push("World");
	llbq.Push("!");
	llbq.isEmpty();
	std::string first = llbq.Front();
	std::cout << first << std::endl; // Êä³ö "Hello"
	std::cout << "¿ªÊ¼Queues\n" ;
}