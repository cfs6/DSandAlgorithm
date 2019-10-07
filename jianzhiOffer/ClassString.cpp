//实现string类的构造、拷贝构造、析构函数
//#include<stdio.h>
#include<iostream>
using namespace std;
class String {
public:
	String(const char* str);
	String(const String& other);
	~String();
	String& operator=(const String& other);
private:
	char* m_string;
};

String::String(const char* str) {
	if (str == nullptr) {
		m_string = new char[1];
		m_string = '\0';
	}
	else {
		m_string = new char[strlen(str)+1];
		strcpy(m_string, str);
	}
}
String::String(const String& other) {
	m_string = new char[strlen(other.m_string) + 1];
	strcpy(m_string, other.m_string);
}

String::~String() {
	delete[] m_string;
	m_string = nullptr;
}

String& String::operator=(const String& other) {
	if (this == &other) {
		return *this;
	}
	delete[] m_string;
	m_string = new char[strlen(other.m_string) + 1];
	strcpy(m_string, other.m_string);
	return *this;
}
