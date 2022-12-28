#pragma once
#include <iostream>
#include "List.h"

template <typename T> class List;
template <typename T>
class Node {
	T data;
	Node* next;
public:
	Node();
	Node(T dat);
	Node(Node& nod);
	void prnt();
	friend class List<T>;
};

template <typename T>
Node<T>::Node() {
	data = NULL;
	next = nullptr;
}

template <typename T> 
Node<T>::Node(T dat) {
	data = dat;
	next = nullptr;
}

template <typename T>
Node<T>::Node(Node& nod) {
	data = nod.data;
	next = nod.next;
}

template <typename T>
void Node<T>::prnt() {
	std::cout << data << " -> ";
}