#ifndef __MYSTRING_H_
#define __MYSTRING_H_
#include<iostream>
//#include<cstring>
#include<stdexcept>
using namespace std;
//su dung T de su dung dc curentItem;
template<typename T>
class myStringIterator
{
private:
	T* ms;
	int current;
public:
	int getCurrent() {
		return current;
	}
	myStringIterator(T* thamso,int batdau= 0) {
		current = batdau;
		ms = thamso;
	}
	 void First() {
		current = 0;
	}
	 void Next() {
		if(!IsDone())
		current++;
	}
	 bool IsDone() const {
		return current >= ms->length();
	}
	 char CurrentItem() const {
		return ms->get(current);
	}
	 void setCurrentItem(char a) {
		 if (!IsDone()) {
			 ms->set(a, current);
		 }
	 }
	 bool operator < (const myStringIterator<T> &a) {
		 return this->current < a.current;
	 }
	 bool operator > (const myStringIterator<T>& a) {
		 return this->current > a.current;
	 }
	 bool operator == (const myStringIterator<T>& a) {
		 return this->current == a.current;
	 }
	 bool operator <=(const myStringIterator<T>& a) {
		 return !*this > a;
	 }
	 bool operator >=(const myStringIterator<T>& a) {
		 return !*this < a;
	 }
	 myStringIterator<T>& operator +(int n) {
		 this->current += n;
		 return *this;
	 }
	 myStringIterator<T>& operator -(int n) {
		 this->current -= n;
		 return *this;
	 }
};
template<typename T>
class myStringConstIterator
{
protected:
	T* ms;
	int current;
public:
	int getCurrent() {
		return current;
	}
	myStringConstIterator(T* thamso, int batdau = 0) {
		current = batdau;
		ms = thamso;
	}
	void First() {
		current = 0;
	}
	void Next() {
		if (!IsDone())
			current++;
	}
	bool IsDone() const {
		return current >= ms->length();
	}
	char CurrentItem() const {
		return ms->get(current);
	}
	void setCurrentItem(char a) {
		if (!IsDone()) {
			ms->set(a, current);
		}
	}
    	bool operator < (const myStringConstIterator<T> &a) {
		return this->current < a.current;
	}
	 bool operator > (const myStringConstIterator<T>& a) {
		return this->current > a.current;
	}
	 bool operator == (const myStringConstIterator<T>& a) {
		return this->current == a.current;
	}
	 bool operator <=(const myStringConstIterator<T>& a) {
		return ! (*this > a);
	}
	 bool operator >=(const myStringConstIterator<T>& a) {
		return ! (*this < a);
	}
	 myStringConstIterator<T>& operator +(int n) {
		 this->current += n;
	 }
	 myStringConstIterator<T>& operator -(int n) {
		 this->current -= n;
	 }
	
};
class myString {
	char * realString;
	int num;
	int capacity;
	static long long int maxSize;
	//static int npos;
public:
	static const int npos = -1;
	int length()const;
	char get(int index);
	myStringIterator<myString>* creatIterator();
	myStringConstIterator<myString>* creatConstIterator();
	myString();
	myString(char * u );
	myString(const myString& str);//copy
	myString(const myString& str, size_t pos, size_t len );	
	myString(const char* s, size_t n);
	myString(size_t n, char c);
	myString(myStringConstIterator<myString> first, myStringConstIterator<myString> last);
	myString(myStringIterator<myString> first, myStringIterator<myString> last);
	~myString();
	void set(char a,int index);
	friend ostream& operator<<(ostream& out, const myString &temp); 
	myStringIterator<myString> begin();
	myStringIterator<myString> end();
	myStringIterator<myString> rbegin();
	myStringIterator<myString> rend();
	myStringConstIterator<myString> cbegin();
	myStringConstIterator<myString> cend();
	myStringConstIterator<myString> crbegin();
	myStringConstIterator<myString> crend();
	int size() const;
	long long int max_size() const;
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t _capacity() const;
	void reserve(size_t n = 0);
	void clear();
	bool empty() const;
	void shrink_to_fit();
	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;
	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;
	myString& operator+= (const myString& str);
	myString& operator+= (const char* s);
	myString& operator+= (char c);
	myString& append(const myString& str);
	myString& append(const myString& str, size_t subpos, size_t sublen);
	myString& append(const char* s);
	myString& append(const char* s, size_t n);
	myString& append(size_t n, char c);
	template <class InputIterator>
	myString& append(InputIterator first, InputIterator last) {
		myString temp;
		for (; first < last; first.Next()) {
			temp += first.CurrentItem();
		}
		*this += temp;
		return *this;
	}
	void push_back(char c);
	myString& operator= (const myString& str);
	myString& operator= (const char* s);
	myString& operator= (char c);
	myString& assign(const myString& str);
	myString& assign(const myString& str, size_t subpos, size_t sublen);
	myString& assign(const char* s);
	myString& assign(const char* s, size_t n);
	myString& assign(size_t n, char c);
	template <class InputIterator>
	myString& assign(InputIterator first, InputIterator last) {
		myString temp;
		for (; first < last; first.Next()) {
			temp += first.CurrentItem();
		}
		*this = temp;
		return *this;
	}
	template<>
	myString& assign<int>(int first, int last) {
		return assign(first, (char)last);
	}
	myString& insert(size_t pos, const myString& str);
	myString& insert(size_t pos, const myString& str, size_t subpos, size_t sublen);
	myString& insert(size_t pos, const char* s);
	myString& insert(size_t pos, const char* s, size_t n);
	myString& insert(size_t pos, size_t n, char c);
	void insert(myStringIterator<myString> p, size_t n, char c);
	myStringIterator<myString> insert(myStringIterator<myString> p, char c);
	template <class InputIterator>
	void insert(myStringIterator<myString> p, InputIterator first, InputIterator last){
		myString temp;
		temp.assign(first, last);
		insert(p.getCurrent(), temp);
	}
	myString& replace(size_t pos, size_t len, const myString& str);
	myString& replace(myStringIterator<myString> i1, myStringIterator<myString> i2, const myString& str);
	myString& replace(size_t pos, size_t len, const myString& str,size_t subpos, size_t sublen);
	myString& replace(size_t pos, size_t len, const char* s);
	myString& replace(myStringIterator<myString> i1, myStringIterator<myString> i2, const char* s);
	myString& replace(size_t pos, size_t len, const char* s, size_t n);
	myString& replace(myStringIterator<myString> i1, myStringIterator<myString> i2, const char* s, size_t n);
	myString& replace(size_t pos, size_t len, size_t n, char c);
	myString& replace(myStringIterator<myString> i1, myStringIterator<myString> i2, size_t n, char c);
	template <class InputIterator>
	myString& replace(myStringIterator<myString> i1, myStringIterator<myString> i2,InputIterator first, InputIterator last){
		myString temp;
		for (; first < last; first.Next()) {
			temp += first.CurrentItem();
		}
		replace(i1.getCurrent(), i2.getCurrent() - i1.getCurrent(), temp);
		return *this;
	}
	myString& erase(size_t pos = 0, size_t len = npos );
	myStringIterator<myString> erase(myStringIterator<myString> p);
	myStringIterator<myString> erase(myStringIterator<myString> first, myStringIterator<myString> last);
	void swap(myString& str);
	void pop_back();
	const char* data() const;
	size_t copy(char* s, size_t len, size_t pos = 0) const;
	size_t find(const myString& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;

	size_t rfind(const myString& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;
	size_t find_first_of(const myString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;
	size_t find_first_not_of(const myString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;
	myString substr(size_t pos = 0, size_t len = npos) const;
	size_t find_last_of(const myString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;
	size_t find_last_not_of(const myString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;
	int compare(const myString& str) const;
	int compare(size_t pos, size_t len, const myString& str) const;
	int compare(size_t pos, size_t len, const myString& str,size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;
	friend myString operator+ (const myString& lhs, const myString& rhs);
	friend myString operator+ (const myString& lhs, const char*   rhs);
	friend myString operator+ (const char*   lhs, const myString& rhs);
	friend myString operator+ (const myString& lhs, char  rhs);
	friend myString operator+ (char lhs, const myString& rhs);
	friend bool operator== (const myString& lhs, const myString& rhs) {
		return lhs.compare(rhs) == 0;
	}
	friend bool operator== (const char*   lhs, const myString& rhs) {
		return rhs == lhs;
	}
	friend bool operator== (const myString& lhs, const char*   rhs) {
		return lhs == rhs;
	}
	friend bool operator!= (const myString& lhs, const myString& rhs) {
		return !(lhs == rhs);
	}
	friend bool operator!= (const char*   lhs, const myString& rhs) {
		return !(lhs == rhs);
	}
	friend bool operator!= (const myString& lhs, const char*   rhs) {
		return !(lhs == rhs);
	}
	friend bool operator<  (const myString& lhs, const myString& rhs) {
		return lhs.compare(rhs) < 0;
	}
	friend bool operator<  (const char*   lhs, const myString& rhs) {
		return rhs.compare(lhs) > 0;
	}
	friend bool operator<  (const myString& lhs, const char*   rhs) {
		return lhs.compare(rhs) < 0;
	}
	friend bool operator<= (const myString& lhs, const myString& rhs) {
		return (lhs == rhs || lhs < rhs);
	}
	friend bool operator<= (const char*   lhs, const myString& rhs) {
		return (lhs == rhs || lhs < rhs);
	}
	friend bool operator<= (const myString& lhs, const char*   rhs) {
		return (lhs == rhs || lhs < rhs);
	}
	friend bool operator>  (const myString& lhs, const myString& rhs) {
		return !(lhs <= rhs);
	}
	friend bool operator>  (const char*   lhs, const myString& rhs) {
		return !(lhs <= rhs);
	}
	friend bool operator>  (const myString& lhs, const char*   rhs) {
		return !(lhs <= rhs);
	}
	friend bool operator>= (const myString& lhs, const myString& rhs) {
		return !(lhs < rhs);
	}
	friend bool operator>= (const char*   lhs, const myString& rhs) {
		return !(lhs < rhs);
	}
	friend bool operator>= (const myString& lhs, const char*   rhs) {
		return !(lhs < rhs);
	}
	friend istream& operator >> (istream& is, myString& str);
	friend istream& getline(istream& is, myString& str, char delim);
	friend istream& getline(istream& is, myString& str);
};
#endif