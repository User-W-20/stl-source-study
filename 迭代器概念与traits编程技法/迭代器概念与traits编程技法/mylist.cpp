#include"mylist.h"
#include<iostream>
#include<string>

template<typename T>
void List<T>::insert_front(T value) {
	ListItem<T>* node = new ListItem<T>();
	node->value() = value;
	node->set_next(_front);
	_front = node;
	if (_end == nullptr) {
		_end = node;
	}
	++_size;
}

template<typename T>
void List<T>::insert_end(T value) {
	ListItem<T>* node = new ListItem<T>();
	node->value() = value;
	node->set_next(nullptr) ;
	if (_end == nullptr) {
		_front = _end = node;
	}
	else {
		_end->set_next(node);
		_end = node;
	}
	++_size;
}

template<typename T>
void List<T>::display(std::ostream& os)const {
	ListItem<T>* curr = _front;
	while (curr) {
		os << curr->value() << " ";
		curr = curr->next();
	}
	os << std::endl;
}




template class List<int>;
template class List<double>;
template class List<std::string>;