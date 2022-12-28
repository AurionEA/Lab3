#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class List {
	Node<T>* first;
	Node<T>* last;
public:
	List();
	List(List& lst);
	List(T frst);

	bool isEmpty();

	void push_frnt(T dat);
	void push_back(T dat);
	void ins(Node<T>* place, T dat);

	T pop_frnt();
	T pop_back();
	T del(Node<T>* place);

	int size();

	void clr();
	~List();

	void prnt();
};

template <typename T>
List<T>::List() {
	first = nullptr;
	last = nullptr;
}

template <typename T>
List<T>::List(List& lst) {
	Node<T>* cur1 = first;
	Node<T>* cur2 = lst.first;
	while (cur2 != nullptr) {
		cur1 = cur2;
		cur2 = cur2->next;
	}
	first = lst.first;
	last = lst.last;
}

template <typename T>
List<T>::List(T frst) {
	Node<T>* nod = new Node<T>(frst);
	nod->next = first;
	last = nod;
	first = nod;
}

template <typename T>
bool List<T>::isEmpty() {
	if (first == nullptr) {
		return true;
	}
	return false;
}

template <typename T>
void List<T>::push_frnt(T dat) {
	Node<T>* nod = new Node<T>(dat);
	if (isEmpty()) {
		last = nod;
	}
	nod->next = first;
	first = nod;
}

template <typename T>
void List<T>::push_back(T dat) {
	Node<T>* nod = new Node<T>(dat);
	if (isEmpty()) {
		first = nod;
	}
	else {
		last->next = nod;
	}
	last = nod;
}

template <typename T>
void List<T>::ins(Node<T>* place, T dat) {
	if (place == nullptr) {
		throw std::logic_error("Uncalled position");
	}
	Node<T>* nod = new Node<T>(dat);
	nod->next = place->next;
	place->next = nod;
	if (last == place) {
		last = nod;
	}
}

template <typename T>
T List<T>::pop_frnt() {
	if (isEmpty()) {
		throw std::logic_error("List is empty!");
	}
	T dat = first->data;
	if (first == last) {
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else {
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		temp = nullptr;
	}
	return dat;
}

template <typename T>
T List<T>::pop_back() {
	if (isEmpty()) {
		throw std::logic_error("List is empty!");
	}
	T dat = last->data;
	if (first == last) {
		delete last;
		first = nullptr;
		last = nullptr;
	}
	else {
		Node<T>* cur = first;
		while (cur->next != last) {
			cur = cur->next;
		}
		cur->next = last->next;
		delete last;
		last = nullptr;
		last = cur;
	}
	return dat;
}

template <typename T>
T List<T>::del(Node<T>* place) {
	if (place == nullptr) {
		throw std::logic_error("Error! Wrong position!");
	}
	T dat = place->data;
	if (place == last) {
		pop_back();
	}
	else if (place == first) {
		pop_frnt();
	}
	else {
		Node<T>* cur = first;
		while (cur->next != place) {
			cur = cur->next;
		}
		cur->next = place->next;
		delete place;
		place = nullptr;
	}
	return dat;
}

template <typename T>
int List<T>::size() {
	int sz = 0;
	Node<T>* cur = first;
	while (cur != nullptr) {
		cur = cur->next;
		sz = sz + 1;
	}
	return sz;
}

template <typename T>
void List<T>::clr() {
	if (isEmpty()) {
		return;
	}
	for (int i = size(); i > 0; i--) {
		pop_frnt();
	}
}

template <typename T>
List<T>::~List() {
	clr();
}

template <typename T>
void List<T>::prnt() {
	Node<T>* cur = first;
	while (cur != nullptr) {
		cur->prnt();
		cur = cur->next;
	}
}