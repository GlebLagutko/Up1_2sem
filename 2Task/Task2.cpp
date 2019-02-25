#include <iostream>
#include  <assert.h>

using namespace std;

template<class T>
class List {
private:
	struct Node {
		T value;
		Node *right;
	};
public:
	int size = 0;
	Node *head;
	List() {
		head = nullptr;
		size = 0;
	}
	//iterator begin() { return head; }
	//iterator end() { return nullptr; 
	void push_back(T x) {
		size++;
		if (size == 1) {
			Node *insert = new Node;
			insert->right = nullptr;
			insert->value = x;
			head = insert;
			return;
		}
		Node *p = new Node;
		Node *insert = new Node;
		p = head;
		insert->right = nullptr;
		insert->value = x;
		while (p->right != nullptr) {
			p = p->right;
		}

		p->right = insert;
	}

	void push_front(T x) {
		size++;
		if (size == 1) {
			Node *insert = new Node;
			insert->right = nullptr;
			insert->value = x;
			head = insert;
			return;
		}
		Node *insert = new Node;
		insert->right = nullptr;
		insert->value = x;
		insert->right = head;
		head = insert;
	}

	T operator[](const int i)
	{
		//cout << i <<" "<<size<<"\n";
		assert(i < size);
		Node *p = new Node;
		p = head;
		for (int j = 0; j < i; ++j) {
			p = p->right;
		}
		return p->value;
	}
};

int main()
{
	List<int> l;
	l.push_back(10);
	l.push_back(10);
	l.push_back(10);
	cout << l[2] << "\n";
	system("pause");
	//std::cout << "Hello World!\n";
}