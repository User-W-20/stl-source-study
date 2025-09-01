#pragma once
#include"mylist.h"

//Item�����ǵ�������ڵ��˫������ڵ�
//�˴�����������ض�ֻΪ���������Ϊ����ص�operator++��Ե��
template<class Item>
struct ListIter
{
	Item* ptr;//����������֮���һ����ϵ

	ListIter(Item* p = 0) :ptr(p){}//Ĭ�Ϲ���

	Item& operator*() const { return *ptr; }
	Item* operator->()const { return ptr; }

	//���µ�operator++���ر�׼����
	//1��ǰ��++
	ListIter& operator++() {
		ptr = ptr->next();
		return *this;
	}

	//2������++
	ListIter operator++(int) {
		ListIter tmp = *this; 
		++(*this); 
		return tmp;
	}

	bool operator==(const ListIter& i)const {
		return ptr == i.ptr;
	}

	bool operator!=(const ListIter& i)const {
		return ptr != i.ptr;
	}

	
	
	
};

template<typename Iter, typename T>
Iter find(Iter first, Iter last, const T& value) {
	while (first != last) {
		if ((*first).value() == value)
			return first;
		++first;
	}
	return last;
}