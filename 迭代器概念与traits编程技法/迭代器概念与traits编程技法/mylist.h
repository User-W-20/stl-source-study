#pragma once
#include<ostream>

template<typename T>
class ListItem {
public:
	ListItem(const T& val = T(), ListItem<T>* next = nullptr)
		: _value(val), _next(next) {
	}
	T& value() { return _value; }
	const T& value() const { return _value; }
	ListItem<T>* next() { return _next; }
	const ListItem<T>* next() const { return _next; }

	void set_next(ListItem<T>* n) { _next = n; }
private:
	T _value;
	ListItem<T>* _next=nullptr;//µ•œÚ¡¥±Ì£®single linked list£©
};

template<typename T>
class List {
public:
	List() : _end(nullptr), _front(nullptr), _size(0) {}
	void insert_front(T value);
	void insert_end(T value);
	void display(std::ostream& os = std::cout)const;
	ListItem<T>* front()const { return _front; }
private:
	ListItem<T>* _end;
	ListItem<T>* _front;
	long _size;
};

