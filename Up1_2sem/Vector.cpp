#include  <iostream>
#include  <assert.h>
#include  <algorithm>

using namespace std;
template <class T> class vector
{
public:
	typedef T* iterator;
	explicit vector(int n = 100); //create a size n array
	vector(const vector<T>& v); //copy vector
	vector(const T* a, int n); //copy an array
	~vector() { delete[]p; }
	iterator begin() { return p; }
	iterator end() { return p + size; }
	//T& operator[](int i);      //range checked element
	vector<T>& operator=(const vector<T>& v);
	void resize(int n);
protected:
	T* p;                      //base pointer
	int size;                  //number of elements
	int compacity;
};

template <class T>
void vector<T>::resize(int n) {
	assert(n > size);
	cout << "In resize\n";
	compacity = n;
	//size = n;
	T* temp = new T[n];
	cout << "In resize copy\n";
	for (int i = 0; i < size; ++i) {
		temp[i] = p[i];
	}
	cout << "In resize add zero\n";
	for (int i = size; i < n; ++i) {
		temp[i] = 0;
	}
	cout << "In resize end\n";
	p = temp;
	//delete[] temp;
}

template <class T>
vector<T>::vector(int n) : size(n) {
	assert(n > 0);     p = new T[n];  for (int i = 0; i < n; ++i) { p[i] = 0; }   compacity = n; size = n;  assert(p != 0);
}
template <class T>
vector<T>::vector(const T a[], int n) {
	assert(n > 0);     size = n;       p = new T[size];
	assert(p != 0);
	compacity = n;
	for (int i = 0; i < size; ++i)
		p[i] = a[i];
}
template <class T>
vector<T>::vector(const vector<T>& v)
{
	size = v.size;   p = new T[size];   assert(p != 0);
	for (int i = 0; i < size; ++i)
		p[i] = v.p[i];
}
template <class T>
vector<T>& vector<T>::operator=(const vector<T>& v)
{
	assert(v.size == size);
	for (int i = 0; i < size; ++i)
		p[i] = v.p[i];
	return *this;
}

template <class T> class vectorex :public vector<T>
{
public:
	vectorex(int n) :vector<T>::vector(n) {}
	T& operator[](int i)
	{
		assert(i >= 0 && i < vector<T>::size); return (vector<T>::p[i]);
	}

	void push_front(T x) {
		if (vector<T>::compacity < vector<T>::size + 2) {
			vector<T>::resize(vector<T>::size + 10);
		}
		T temp = vector<T>::p[0];
		for (int i = 1; i < vector<T>::size + 1; ++i) {
			swap(vector<T>::p[i], temp);
		}
		vector<T>::size++;
		vector<T>::p[0] = x;
	}

	void push_back(T x) {
		if (vector<T>::compacity < vector<T>::size + 2) {
			vector<T>::resize(vector<T>::size + 10);
		}
		cout << "Add in push_back\n";
		vector<T>::p[vector<T>::size] = x;
		vector<T>::size++;
	}

	T& pop_front() {
		T p = vector<T>::p[0];
		for (int i = 0; i < vector<T>::size; ++i) {
			swap(vector<T>::p[i], vector<T>::p[i + 1]);
		}
		vector<T>::size--;
		return p;
	}

	T& pop_back() {
		T p = vector<T>::p[vector<T>::size];
		vector<T>::size--;
		return p;
	}

	int GetSize()
	{
		return this->size;
	}

};




int main()
{
	vector<double> v(5);
	vector<double >::iterator p;
	int i = 0;
	for (p = v.begin(); p != v.end(); ++p)
		*p = 1.5 + i++;
	/*
	do {
		--p; cout << *p << " , ";
	} while (p != v.begin());
	cout << endl;
	*/

	cout << "=============================================\n";
	vectorex<int>ve(3);
	ve[0] = ve[1] = ve[2] = 123;
	cout << ve[1] << endl;
	ve.push_back(1111);
	cout << ve[3];
	ve.push_front(321);
	cout << ve[0] << endl;
	ve.pop_front();
	cout << ve[0] << endl;
	system("pause");
	return 0;
}