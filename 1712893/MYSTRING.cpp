#include"MYSTRING.h"
long long int myString::maxSize = 429496729;
int myString::length() const{
	return num;
}
char myString::get(int index) {
	if (index < num &&index >= 0) {
		return realString[index];
	}
	else {
		throw out_of_range("Mystring out of range");
	}
}
myStringIterator<myString>* myString::creatIterator(){
	return new myStringIterator<myString>(this);
}
myStringConstIterator<myString>* myString:: creatConstIterator(){
	return new myStringConstIterator<myString>(this);
}
myString::myString(char * u) {
	int n = strlen(u);
	num = n;
	capacity = 15;
	if (n >= 15)capacity = capacity + n;
	realString = new char[capacity];
	for (int i = 0; i < n; i++) {
		realString[i] = u[i];
	}
	realString[n] = '\0';
}
myString::~myString() {
	if (realString != NULL) {
		delete[] realString;
	}
}
void myString::set(char a, int index){
	realString[index] = a;
}
myString::myString() {
	capacity = 15;
	num = 0;
	realString = new char[15];
	strcpy(realString, "");
};
myString::myString(const myString& str) {
	this->capacity = str.capacity;
	this->num = str.num;
	//if(realString != NULL)delete[]this->realString;
	this->realString = new char[capacity];
	strcpy(this->realString, str.realString);
}
myString::myString(const myString& str, size_t pos, size_t len) {
	if (pos < 0|| pos > str.num) {
		myString(str);
	}
	else {
		int oldcap = capacity;
		this->capacity = str.capacity;
		this->realString = new char[capacity];
		if (realString == NULL) {
			capacity = oldcap;
			throw bad_alloc();
		}
		if (pos + len > str.num) {
			num = str.num - pos;
			strcpy(realString, str.realString + pos);
		}
		else {
			num = len;
			for (int i = pos; i < pos + len; i++) {
				realString[i - pos] = str.realString[i];
			}
			realString[len] = '\0';
		}
	}
}
myString::myString(const char* s, size_t n){
	if (strlen(s) >= maxSize)throw length_error("longer than maxSize");
	if (n > strlen(s)) {
		myString(s);
	}
	else {
		if (strlen(s)+15<maxSize)
		this->capacity = strlen(s) + 15;
		else this->capacity = maxSize;
		realString = new char[capacity];
		this->num = n;
		for (int i = 0; i < n; i++) {
			realString[i] = s[i];
		}
		realString[n] = '\0';
	}
}
myString::myString(size_t n, char c) {
	if (n >= maxSize)throw length_error("longer than max size");
	if(this->capacity + n <maxSize)
	this->capacity = n + 15;
	else this->capacity = maxSize;
	realString = new char[capacity];
	for (int i = 0; i < n; i++) {
		realString[i] = c;
	}
	this->num = n;
	realString[n] = '\0';
}
myString::myString(myStringConstIterator<myString> first, myStringConstIterator<myString> last){
int n = last.getCurrent() - first.getCurrent();
if (n <= 0) {
	capacity = 15;
	num = 0;
	realString = new char[15];
	strcpy(realString, "");
}
	else {
	this->capacity = n + 15;
	this->realString = new char[capacity];
	int i = 0;
	for (; first < last; first.Next()) {
		realString[i] = first.CurrentItem();
		i++;
	}
	realString[n] = '\0';
	}
}
myString::myString(myStringIterator<myString> first, myStringIterator<myString> last){
	int n = last.getCurrent() - first.getCurrent();
	if (n <= 0) {
		capacity = 15;
		num = 0;
		realString = new char[15];
		strcpy(realString, "");
	}
	else {
		this->capacity = n + 15;
		this->realString = new char[capacity];
		int i = 0;
		for (; first < last; first.Next()) {
			realString[i] = first.CurrentItem();
			i++;
		}
		realString[n] = '\0';
	}
}
ostream& operator << (ostream& out, const myString & temp) {
	//if (temp.num == 0)cout << "";
	//else 
	cout << temp.realString;
	return out;
}
myStringIterator<myString> myString::begin() {
	myStringIterator<myString> temp(this, 0);
	return temp;
}
myStringIterator<myString> myString:: end(){
	myStringIterator<myString> temp(this, num);
	return temp;
}
myStringIterator<myString> myString:: rbegin(){
	myStringIterator<myString> temp(this, num);
	return temp;
}
myStringIterator<myString> myString:: rend(){
	myStringIterator<myString> temp(this, 0);
	return temp;
}
myStringConstIterator<myString> myString:: cbegin(){

	myStringConstIterator<myString> temp(this, 0);
	return temp;
}
myStringConstIterator<myString> myString:: cend(){
	myStringConstIterator<myString> temp(this, num);
	return temp;
}
myStringConstIterator<myString> myString:: crbegin(){
	myStringConstIterator<myString> temp(this, num);
	return temp;
}
myStringConstIterator<myString> myString:: crend(){
	myStringConstIterator<myString> temp(this,0);
	return temp;
}
int myString::size()const
{
	return num;
}
long long int myString::max_size() const {
	return maxSize;
}
void myString:: resize(size_t n){
	if (n < 0) throw bad_alloc();
	else if (n > maxSize)throw length_error("greater than maxsize");
	else if (n <= num) {
		this->realString[n] = '\0';
		num = n;
	}
	else {
		if (n < capacity) {
			this->realString[n] = '\0';
			num = n;
		}
		else {
			capacity = capacity + n;
			char *temp = new char[capacity];
			if (temp == NULL)throw bad_alloc();
			for (int i = 0; i <= num; i++) {
				temp[i] = realString[i];
			}
			char * temp1 = realString;
			realString = temp;
			delete[]temp1;
			num = n;
		}

	}
}
void myString::resize(size_t n, char c){
	if (n < 0) throw bad_alloc();
	else if (n > maxSize)throw length_error("greater than maxsize");
	else if (n <= num) {
		this->realString[n] = '\0';
		num = n;
	}
	else {
		if (n < capacity) {
			for (int i = num; i < n; i++)realString[i] = c;
			this->realString[n] = '\0';
			num = n;
		}
		else {
			capacity = capacity + n;
			char *temp = new char[capacity];
			if (temp == NULL)throw bad_alloc();
			for (int i = 0; i <= num; i++) {
				temp[i] = realString[i];
			}
			for (int i = num; i < n; i++) {
				temp[i] = c;
			}
			temp[n] = '\0';
			char * temp1 = realString;
			realString = temp;
			delete[]temp1;
			num = n;
		}

	}
}
size_t myString::_capacity() const{
	return capacity;
}
void myString::reserve(size_t n ){
	if (n < 0) throw bad_alloc();
	else if (n > maxSize)throw length_error("greater than maxsize");
	else if (n <= num) {
		this->realString[n] = '\0';
		num = n;
	}
	else {
		if (n < capacity) {
			this->realString[n] = '\0';
			num = n;
		}
		else {
			capacity = capacity + n;
			char *temp = new char[capacity];
			if (temp == NULL)throw bad_alloc();
			for (int i = 0; i <= num; i++) {
				temp[i] = realString[i];
			}
			char * temp1 = realString;
			realString = temp;
			delete[]temp1;
			num = n;
		}

	}
}
void myString::clear(){
	num = 0;
	realString[num] = '\0';
}
bool myString::empty() const {
	return num == 0;
}
void myString::shrink_to_fit(){
	capacity = num+1;
	char *temp = new char[capacity];
	if (temp == NULL)throw bad_alloc();
	else {
		for (int i = 0; i < num; i++) { temp[i] = realString[i]; }
		temp[num] = '\0';
		char * temp1;
		temp1 = realString;
		realString = temp;
		delete[]temp1;
	}
}
char& myString::operator[](size_t pos){
	if (pos < 0 || pos > num)throw out_of_range("out of range");
	else return realString[pos];
}
const char& myString::operator[] (size_t pos) const {
	if (pos < 0 || pos > num)throw out_of_range("out of range");
	else return realString[pos];
}
char& myString::at(size_t pos){
	if (pos < 0 || pos > num)throw out_of_range("out of range");
	else return realString[pos];
}
const char& myString:: at(size_t pos) const {
	if (pos < 0 || pos > num)throw out_of_range("out of range");
	else return realString[pos];
}
char& myString::back(){
	if (empty())throw out_of_range("string is empty");
	else {
		return realString[num - 1];
	}
}
const char& myString::back() const {
	if (empty())throw out_of_range("string is empty");
	else {
		return realString[num - 1];
	}
}
char& myString::front(){
	if (empty())throw out_of_range("string is empty");
	else {
		return realString[0];
	}
}
const char& myString::front() const {
	if (empty())throw out_of_range("string is empty");
	else {
		return realString[0];
	}
}
myString& myString:: operator+= (const myString& str){
	if (this->num + str.num < this->capacity) {
		strcpy(this->realString, strcat(this->realString, str.realString));
		num += str.num;
	}
	else {
		if (this->num + str.num >= maxSize)throw length_error("longer than max length");
		else {
			int old_capacity = capacity;
			capacity = this->num + str.num + 15;
			if (capacity > maxSize) capacity = maxSize;
			char * temp = new char[capacity];
			if (temp == NULL) {
				capacity = old_capacity;
				throw bad_alloc();
			}
			temp[0] = '\0';
			strcat(temp, realString);
			strcat(temp, str.realString);
			char* temp1 = realString;
			realString = temp;
			num = this->num + str.num;
			delete[] temp1;
		}
	}
	return *this;
}
myString& myString::operator+= (const char* s){
	if (this->num + strlen(s) < this->capacity) {
		strcpy(this->realString, strcat(this->realString, s));
		num += strlen(s);
	}
	else {
		if (this->num + strlen(s) >= maxSize)throw length_error("longer than max length");
		else {
			int old_capacity = capacity;
			capacity = this->num + strlen(s) + 15;
			if (capacity > maxSize) capacity = maxSize;
			char * temp = new char[capacity];
			if (temp == NULL) {
				capacity = old_capacity;
				throw bad_alloc();
			}
			temp[0] = '\0';
			strcat(temp, realString);
			strcat(temp, s);
			char* temp1 = realString;
			realString = temp;
			num = this->num + strlen(s);
			delete[] temp1;
		}
	}
	return *this;
}
myString& myString:: operator+= (char c){
	if (this->num + 1 < this->capacity) {
		realString[num] = c;
		realString[num + 1] = '\0';
		num += 1;
	}
	else {
		if (this->num + 1 >= maxSize)throw length_error("longer than max length");
		else {
			int old_capacity = capacity;
			capacity = this->num + 1 + 15;
			if (capacity > maxSize) capacity = maxSize;
			char * temp = new char[capacity];
			if (temp == NULL) {
				capacity = old_capacity;
				throw bad_alloc();
			}
			temp[0] = '\0';
			strcat(temp, realString);
			temp[num] = c;
			temp[num + 1] = '\0';
			char* temp1 = realString;
			num = num + 1;
			realString = temp;
			delete[] temp1;
		}
	}
	return *this;
}
myString& myString:: append(const myString& str){
	if (this->num + str.num < this->capacity) {
		strcpy(this->realString, strcat(this->realString, str.realString));
		num += str.num;
	}
	else {
		if (this->num + str.num >= maxSize)throw length_error("longer than max length");
		else {
			int old_capacity = capacity;
			capacity = this->num + str.num + 15;
			if (capacity > maxSize) capacity = maxSize;
			char * temp = new char[capacity];
			if (temp == NULL) {
				capacity = old_capacity;
				throw bad_alloc();
			}
			temp[0] = '\0';
			strcat(temp, realString);
			strcat(temp, str.realString);
			char* temp1 = realString;
			realString = temp;
			num = this->num + str.num;
			delete[] temp1;
		}
	}
	return *this;
}
myString& myString:: append(const char* s){
	if (this->num + strlen(s) < this->capacity) {
		strcpy(this->realString, strcat(this->realString, s));
		num += strlen(s);
	}
	else {
		if (this->num + strlen(s) >= maxSize)throw length_error("longer than max length");
		else {
			int old_capacity = capacity;
			capacity = this->num + strlen(s) + 15;
			if (capacity > maxSize) capacity = maxSize;
			char * temp = new char[capacity];
			if (temp == NULL) {
				capacity = old_capacity;
				throw bad_alloc();
			}
			temp[0] = '\0';
			strcat(temp, realString);
			strcat(temp, s);
			char* temp1 = realString;
			realString = temp;
			num = this->num + strlen(s);
			delete[] temp1;
		}
	}
	return *this;
}
myString& myString:: append(const myString& str, size_t subpos, size_t sublen){
	if (subpos < 0 || subpos >= str.num)throw out_of_range("out of string range");
	else {
		myString temp;
		if (subpos + sublen <= str.num) {
			for (int i = subpos; i < subpos + sublen; i++) {
				temp += str[i];
			}
			*this += temp;
		}
		else {
			for (int i = subpos; i < str.length(); i++) {
				temp += str[i];
			}
			*this += temp;
		}
	}
	return *this;
}
myString& myString:: append(const char* s, size_t n){
	if (n < 0 || n >= strlen(s))throw out_of_range("out of array length");
	else {
		myString temp;
		for (int i = 0; i < n; i++) {
			temp += s[i];
		}
		*this += temp;
	}
	return *this;
}
myString& myString:: append(size_t n, char c){
	myString temp;
	for (int i = 0; i < n; i++)temp += c;
	*this += temp;
	return *this;
}
void myString:: push_back(char c){
	*this += c;
}
myString& myString:: operator= (const myString& str){
	if (str.num >= maxSize)throw length_error("longer than max size");
	else {
		char * tem = new char[str.capacity];
		if (tem == NULL)throw bad_alloc();
		for (int i = 0; i < str.num; i++)tem[i] = str.realString[i];
		tem[str.num] = '\0';
		char *tem1 = realString;
		if (tem1 != NULL)delete[]tem1;
		realString = tem;
		this->num = str.num;
		this->capacity = str.capacity;
	}
	return *this;
}
myString& myString::operator= (const char* s){
	if(strlen(s)>=maxSize)throw length_error("longer than max size");
	else {
		this->resize(0);
		*this += s;
	}
	return *this;
}
myString& myString::operator = (char c){
	this->resize(0);
	*this += c;
	return *this;
}
myString& myString::assign(const myString& str){
	*this = str;
	return *this;
}
myString& myString::assign(const myString& str, size_t subpos, size_t sublen){
	if (subpos < 0 || subpos >= str.length())throw out_of_range("longer than str length");
	else {
		if (sublen >= maxSize || str.num >= maxSize)throw length_error("longer than max size");
		else {
			myString temp;
			if (subpos + sublen > str.num) {
				for (int i = subpos; i < str.length(); i++) {
					temp += str[i];
				}
				*this = temp;
			}
			else {
				for (int i = subpos; i < subpos + sublen; i++) {
					temp += str[i];
				}
				*this = temp;
			}
		}
	}
	return *this;

}
myString& myString::assign(const char* s){
	*this = s;
	return *this;
}
myString& myString::assign(const char* s, size_t n){
	if (s == NULL || n < 0)throw out_of_range("s is NULL or n< 0");
	else if (strlen(s) > maxSize)throw length_error("longer than maxSize"); 
	else {
		myString temp;
		if (n > strlen(s))n = strlen(s);
		for (int i = 0; i < n; i++)temp += s[i];
		*this = temp;
	}
	return *this;
	
}
myString& myString::assign(size_t n, char c){
	if (n < 0) throw out_of_range("n < 0");
	if (n> maxSize) throw length_error("longer than maxSize");
	else {
		myString temp;
		for (int i = 0; i < n; i++)temp += c;
		*this = temp;
	}
	return *this;
}
myString& myString::insert(size_t pos, const myString& str){
	if (pos<0 || pos > this->num)throw out_of_range("out of range");
	myString temp(*this, pos, this->num);
	int oldnum = num;
	*this += str;//mo rong o nho
	strcpy(realString + pos, realString + oldnum);
	strcat(realString, temp.realString);
	return *this;
}
myString& myString::insert(size_t pos, const myString& str, size_t subpos, size_t sublen){

	myString temp1(str, subpos, sublen);
	return insert(pos, temp1);
}
myString& myString::insert(size_t pos, const char* s){
	myString temp(s, strlen(s));
	return insert(pos, temp);
	
}
myString& myString::insert(size_t pos, const char* s, size_t n){
	myString temp1(s, n);
	return insert(pos, temp1);
}
myString& myString::insert(size_t pos, size_t n, char c){
	myString temp1(n,c);
	return insert(pos, temp1);
}
void myString::insert(myStringIterator<myString> p, size_t n, char c){
	insert(p.getCurrent(), n, c);
}
myStringIterator<myString> myString::insert(myStringIterator<myString> p, char c) {
	insert(p.getCurrent(), 1, c);
	p.Next();
	return p;
}
myString& myString::replace(size_t pos, size_t len, const myString& str){
	if (num + str.num - len > maxSize)throw length_error("more than max size");
	else if (pos<0 || pos > this->num)throw out_of_range("out of range");
	else {
		if (pos + len > this->num) len = num - pos;
		strcpy(realString + pos, realString +pos+ len);
		num -= len;
		insert(pos, str);
	}
	return *this;
}
myString& myString::replace(myStringIterator<myString> i1, myStringIterator<myString> i2, const myString& str){
	return replace(i1.getCurrent(), i2.getCurrent() - i1.getCurrent() , str);
}
myString& myString::replace(size_t pos, size_t len, const myString& str, size_t subpos, size_t sublen){
	myString temp;
	temp.assign(str, subpos, sublen);
	return replace(pos, len, temp);
}
myString& myString::replace(size_t pos, size_t len, const char* s){
	myString temp;
	temp.assign(s);
	return replace(pos, len, temp);
}
myString& myString::replace(myStringIterator<myString> i1, myStringIterator<myString> i2, const char* s){
	myString temp;
	temp.assign(s);
	return replace(i1.getCurrent(), i2.getCurrent() - i1.getCurrent(), temp);
}
myString& myString::replace(size_t pos, size_t len, const char* s, size_t n){
	myString temp;
	temp.assign(s, n);
	return replace(pos, len, temp);
}
myString& myString::replace(myStringIterator<myString> i1, myStringIterator<myString> i2, const char* s, size_t n){
	myString temp;
	temp.assign(s, n);
	return replace(i1.getCurrent(), i2.getCurrent() - i1.getCurrent() , temp);
}
myString& myString::replace(size_t pos, size_t len, size_t n, char c){
	myString temp;
	temp.assign(n,c);
	return replace(pos, len, temp);
}
myString& myString::replace(myStringIterator<myString> i1, myStringIterator<myString> i2, size_t n, char c){
	myString temp;
	temp.assign(n, c);
	return replace(i1.getCurrent(), i2.getCurrent() - i1.getCurrent(), temp);
}
myString& myString::erase(size_t pos, size_t len){
	if (pos<0 || pos>num || (len<0 && len!=npos))throw out_of_range("out of myString range");
	else {
		if (pos + len > this->num||len == npos) {
			len = num - pos;
		}
		strcpy(realString + pos, realString + pos + len);
		num -= len;
	}
	return *this;
}
myStringIterator<myString>myString:: erase(myStringIterator<myString> p){
	if (p.IsDone())throw length_error("iterator points at Last");
	else {
		erase(p.getCurrent(), 1);
	}
	return p;
}
myStringIterator<myString>myString:: erase(myStringIterator<myString> first, myStringIterator<myString> last){
	if (first > last)throw length_error("first > last ");
	else {
		size_t pos = first.getCurrent();
		size_t len = last.getCurrent() - first.getCurrent();
		erase(pos, len);
	}
}
void myString::swap(myString& str){
	myString temp;
	temp = *this;
	*this = str;
	str = temp;
}
void myString::pop_back(){
	if (empty())throw logic_error("undefined behavior");
	else {
		num = num - 1;
		realString[num] = '\0';
	}
}
const char* myString:: data() const {
	return this->realString;
}
size_t myString::copy(char* s, size_t len, size_t pos ) const {
	if (pos > num)throw out_of_range("longer than myString length");
	else {
		if (pos + len > num)len = num - pos;
		for (int i = pos; i < pos + len; i++) {
			s[i - pos] = realString[i];
		}
		return len;
	}
}
size_t myString::find(const myString& str, size_t pos ) const {
	if (pos <0 || pos >=num)return npos;
	else {
		char * u = strstr(realString + pos, str.realString);
		if (u == NULL)return npos;
		else return u - realString;

	}
}
size_t myString::find(const char* s, size_t pos ) const {
	if (pos <0 || pos >= num||s==NULL)return npos;
	else {
		char * u = strstr(realString + pos, s);
		if (u == NULL)return npos;
		else return u - realString;
	}
}
size_t myString::find(const char* s, size_t pos, size_t n) const {
	if (pos <0 || pos >= num||s==NULL)return npos;
	else {
		char * u = new char[n+1];
		if (u == NULL)throw bad_alloc();
		else {
			for (int i = 0; i < n; i++) {
				u[i] = s[i];
			}
			u[n] = '\0';
			int ret = find(u, pos);
			delete u;
			return ret;
		}
	}

}
size_t myString::find(char c, size_t pos ) const {
	if (pos < 0 && pos >= num)return npos;
	else {
		myString temp;
		temp = c;
		return find(temp, pos);
	}
}
size_t myString::rfind(const myString& str, size_t pos ) const {
	if ((pos != npos && pos < 0 )|| (pos >= this->num&& pos != npos))return npos;
	else {
		if (pos == npos)pos = 0;
		int olddum = 0; int newdum = pos;
		while (newdum != -1) {
			newdum = find(str, newdum);
			if (newdum == -1)break;
			olddum = newdum;
			newdum++;
		}
		return olddum;
	}
}
size_t myString::rfind(const char* s, size_t pos) const {
	if ((pos != npos && pos < 0) || (pos >= this->num&& pos != npos) || s == NULL)return npos;
	else {
		if (pos == npos)pos = 0;
		int olddum = 0; int newdum = pos;
		while (newdum != -1) {
			newdum = find(s, newdum);
			if (newdum == -1)break;
			olddum = newdum;
			newdum++;
		}
		return olddum;
	}
}
size_t myString::rfind(const char* s, size_t pos, size_t n) const {
	if ((pos != npos && pos < 0) || (pos >= this->num&& pos!=npos)||s==NULL)return npos;
	else {
		if (pos == npos)pos = 0;
		int olddum = 0; int newdum = pos;
		myString str;
		str.assign(s, n);
		while (newdum != -1) {
			newdum = find(str, newdum);
			if (newdum == -1)break;
			olddum = newdum;
			newdum++;
		}
		return olddum;
	}
}
size_t myString::rfind(char c, size_t pos ) const {
	if ((pos != npos && pos < 0) || (pos >= this->num&& pos != npos))return npos;
	else {
		if (pos == npos)pos = 0;
		int olddum = 0; int newdum = pos;
		myString str ;
		str = c;
		while (newdum != -1) {
			newdum = find(str, newdum);
			if (newdum == -1)break;
			olddum = newdum;
			newdum++;
		}
		return olddum;
	}
}
size_t myString ::find_first_of(const myString& str, size_t pos ) const {
	if (pos >= num)return npos;
	for (int i = pos; i < num; i++) {
		int flag = 0;
		for (int j = 0; j < str.num; j++)
		{
			if (realString[i] == str[j]) { flag = 1; break; }
		}
		if (flag == 1)return i;
	}
	return -1;
}
size_t myString::find_first_of(const char* s, size_t pos) const {
	if (pos >= num)return npos;
	if (s == NULL)return num;
	for (int i = pos; i < num; i++) {
		int flag = 0;
		for (int j = 0; j < strlen(s); j++)
		{
			if (realString[i] == s[j]) { flag = 1; break; }
		}
		if (flag == 1)return i;
	}
	return -1;
}
size_t myString::find_first_of(const char* s, size_t pos, size_t n) const {
	if (pos >= num)return npos;
	if (s == NULL)return num;
	myString u;
	u.assign(s, n);
	return find_first_of(u, pos);
}
size_t myString::find_first_of(char c, size_t pos ) const {
	return find(c, pos);
}
size_t myString::find_first_not_of(const myString& str, size_t pos ) const {
	if (pos >= num)return npos;
	for (int i = pos; i < num; i++) {
		int flag = 0;
		for (int j = 0; j < str.num; j++)
		{
			if (realString[i] == str[j]) { flag = 1; break; }
		}
		if (flag == 1) {
			flag = 0; continue;
		}
		else return i;
	}
	return -1;
}
size_t myString:: find_first_not_of(const char* s, size_t pos ) const{
	if (pos >= num)return npos;
	for (int i = pos; i < num; i++) {
		int flag = 0;
		for (int j = 0; j < strlen(s); j++)
		{
			if (realString[i] == s[j]) { flag = 1; break; }
		}
		if (flag == 1) {
			flag = 0; continue;
		}
		else return i;
	}
	return -1;
}
size_t myString::find_first_not_of(const char* s, size_t pos, size_t n) const {
	if (pos >= num)return npos;
	if (s == NULL)return num;
	myString u;
	u.assign(s, n);
	return find_first_not_of(u, pos);
}
size_t myString:: find_first_not_of(char c, size_t pos ) const {
	myString r;
	r = c;
	return find_first_not_of(r, pos);
}
myString myString::substr(size_t pos, size_t len ) const {
	if (pos < 0 || pos >= num) throw out_of_range("out of string range");
	if (len == npos || len > num)len = num - pos;
	myString temp; 
	temp.assign(*this, pos, len);
	return temp;
}
size_t myString::find_last_of(const myString& str, size_t pos ) const {
	if (pos >= num&& pos!=npos)return npos;
	if (pos == npos)pos = num-1;
	for (int i = pos; i >= 0; i--) {
		int flag = 0;
		for (int j = 0; j < str.num; j++)
		{
			if (realString[i] == str[j]) { flag = 1; break; }
		}
		if (flag == 1)return i;
	}
	return -1;
}
size_t myString::find_last_of(const char* s, size_t pos ) const {
	if (pos >= num&& pos != npos|| s ==NULL)return npos;
	if (pos == npos)pos = num - 1;
	for (int i = pos; i >= 0; i--) {
		int flag = 0;
		for (int j = 0; j < strlen(s); j++)
		{
			if (realString[i] == s[j]) { flag = 1; break; }
		}
		if (flag == 1)return i;
	}
	return -1;
}
size_t myString::find_last_of(const char* s, size_t pos, size_t n) const {
	myString temp;
	temp.assign(s, n);
	return find_last_of(temp, pos);
}
size_t myString::find_last_of(char c, size_t pos ) const {
	myString temp;
	temp = "c";
	return find_last_of(temp, pos);
}
size_t myString::find_last_not_of(const myString& str, size_t pos ) const {
	if (pos >= num&& pos!=npos)return npos;
	if (pos == npos)pos = num - 1;
	for (int i = pos; i >= 0; i--) {
		int flag = 0;
		for (int j = 0; j < str.num; j++)
		{
			if (realString[i] == str[j]) { flag = 1; break; }
		}
		if (flag == 1) {
			flag = 0; continue;
		}
		else return i;
	}
	return -1;
}
size_t myString::find_last_not_of(const char* s, size_t pos ) const {
	if (pos >= num&& pos != npos||s==NULL)return npos;
	if (pos == npos)pos = num - 1;
	for (int i = pos; i >= 0; i--) {
		int flag = 0;
		for (int j = 0; j < strlen(s); j++)
		{
			if (realString[i] == strlen(s)) { flag = 1; break; }
		}
		if (flag == 1) {
			flag = 0; continue;
		}
		else return i;
	}
	return -1;
}
size_t myString::find_last_not_of(const char* s, size_t pos, size_t n) const {
	if (pos >= num)return npos;
	if (s == NULL)return num;
	myString u;
	u.assign(s, n);
	return find_last_not_of(u, pos);
}
size_t myString::find_last_not_of(char c, size_t pos ) const {
	myString r;
	r = c;
	return find_last_not_of(r, pos);
}
int myString:: compare(const myString& str) const {
	return strcmp(this->realString, str.realString);
}
int myString::compare(size_t pos, size_t len, const myString& str) const {
	if (pos >= str.num)throw out_of_range("out of myString range");
	else {
		return this->substr(pos, len).compare(str);
	}
}
int myString::compare(size_t pos, size_t len, const myString& str, size_t subpos, size_t sublen) const {
	return this->substr(pos, len).compare(str.substr(subpos, sublen));
}
int myString::compare(const char* s) const {
	if (s == NULL)throw logic_error("undefined behavior");
	else {
		return strcmp(this->realString, s);
	}
}
int myString::compare(size_t pos, size_t len, const char* s) const {
	return this->substr(pos, len).compare(s);
}
int myString::compare(size_t pos, size_t len, const char* s, size_t n) const {
	if (s == NULL)throw logic_error("undefined behavior");
	myString l;
	l.assign(s, n);
	return this->substr(pos, len).compare(l);
}
myString operator+ (const myString& lhs, const myString& rhs){
	if (lhs.length() + rhs.length() >= myString::maxSize) throw length_error("longer than string len");
	myString temp = lhs;
	return temp.append(rhs);
}
myString operator+ (const myString& lhs, const char*   rhs){
	if (lhs.length() + strlen(rhs) >= myString::maxSize) throw length_error("longer than string len");
	myString temp = lhs;
	return temp.append(rhs);
}
myString operator+ (const char*   lhs, const myString& rhs){
	if (strlen(lhs) + rhs.length() >= myString::maxSize) throw length_error("longer than string len");
	myString temp =(char*)lhs;
	return temp.append(rhs);
}
myString operator+ (const myString& lhs, char  rhs){
	if (lhs.length() + 1 >= myString::maxSize) throw length_error("longer than string len");
	myString temp = lhs;
	 temp.push_back(rhs);
	 return temp;
}
myString operator+ (char lhs, const myString& rhs){
	if (1 + rhs.length() >= myString::maxSize) throw length_error("longer than string len");
	myString temp;
	temp = lhs;
	return temp.append(rhs);
}
void swap(myString& x, myString& y){
	x.swap(y);
}
istream& operator >> (istream& is, myString& str){
	int temp = str.num;
	char n;
	while (1) {
		is.get(n);
		if (n == ' ' || n == '\t')break;
		if (n == '\n') break;
		str += n;
	}
	return is;
}
istream& getline(istream& is, myString& str, char delim){
	int temp = str.num;
	char n;
	while (1) {
		is.get(n);
		if (n == delim) break;
		str += n;
	}
	return is;
}
istream& getline(istream& is, myString& str){
	int temp = str.num;
	char n;
	while (1) {
		is.get(n);
		if (n == '\n') break;
		str += n;
	}
	return is;
}
