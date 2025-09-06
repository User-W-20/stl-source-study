#pragma once
#include<iostream>
#include<cstring>

class String {
	char* data_;
public:
	String() :data_(nullptr){}

	 String(const char* s) {
		if (s) {
			data_ = new char[strlen(s) + 1];
			strcpy_s(data_, strlen(s) + 1, s);
		}
		else {
			data_ = nullptr;
		}
	}

	//拷贝构造
	String(const String& other) {
		if (other.data_) {
			data_ = new char[strlen(other.data_) + 1];
			strcpy_s(data_, strlen(other.data_) + 1, other.data_);
		}
		else {
			data_ = nullptr;
		}
		std::cout << "[copy ctor]\n";
	}

	// 非平凡拷贝赋值
	String& operator=(const String& other) {
		if (this != &other) {
			delete[]data_;
			if (other.data_) {
				data_ = new char[strlen(other.data_) + 1];
				strcpy_s(data_, strlen(other.data_) + 1, other.data_); 
			}
			else {
				data_ = nullptr;
			}
			std::cout << "[copy assign]\n";
		}
		return *this;
	}

	~String(){ delete[] data_; }

	const char* c_str()const { return data_ ? data_ : ""; }
};