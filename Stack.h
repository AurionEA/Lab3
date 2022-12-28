 #pragma once
 #include <iostream>
 #include "List.h"
 
template <typename T>
 class StList : protected List<T> {
 	List<T> stck;
 public:
 	StList();
 	StList(StList& stc);
 
 	bool isEmpty();
 
 	void push(T dat);
 	T pop();
 
 	int size();
 
 	void clr();
 	~StList();
 
 	void prnt();
 };
 
 template <typename T>
 StList<T>::StList() {
 }
 
 template <typename T>
 StList<T>::StList(StList& stc) {
 	List stck(stc);
 }
 
 template <typename T>
 bool StList<T>::isEmpty() {
 	return stck.isEmpty();
 }
 
 template <typename T>
 void StList<T>::push(T dat) {
 	stck.push_frnt(dat);
 }
 
 template <typename T>
 T StList<T>::pop() {
 	return stck.pop_frnt();
 }
 
 template <typename T>
 int StList<T>::size() {
 	return stck.size();
 }
 
 template <typename T>
 void StList<T>::clr() {
 	stck.clr();
 }
 
 template <typename T>
 StList<T>::~StList() {
 	clr();
 }
 
 template <typename T>
 void StList<T>::prnt() {
 	StList<T> temp;
 	for (int i = size(); i > 1; i--) {
 		std::cout << "|\t" << temp.pop() << "\t|" << std::endl;
 	}
 	std::cout << "-----------------" << std::endl << std::endl;
 }