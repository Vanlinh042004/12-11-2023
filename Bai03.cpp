#include "C++.h"
using namespace std;
#pragma region Stack
template <class T>
struct Node1 {
	T data;
	Node1<T>* next;
};
template <class T>
using node1 = Node1<T>*;
template <class T>
struct Stack {
	node1<T> top;
};
// Khoi tao stack rong
template <class T>
void Init(Stack<T>& st) {
	st.top = NULL;
}
// Kiem tra stack rong
template <class T>
bool Empty(Stack<T> st) {
	return st.top == NULL;
}
// Tao mot node mõi 
template <class T>
node1<T> MakeNode(T x) {
	node1<T> tmp = new Node1<T>();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;
}
// Them phan tu vao dau stack
template <class T>
void Push(Stack<T>& st, T x) {
	node1<T> p = MakeNode(x);
	if (Empty(st)) {
		st.top = p;
		return;
	}
	else {
		p->next = st.top;
		st.top = p;
	}
}
// Lay gia tri cua phan tu dau stack
template <class T>
T Top(Stack<T> st) {
	if (Empty(st)) return NULL;
	else return st.top->data;
}
// Lay phan tu dau ra khoi stack
template <class T>
void Pop(Stack<T>& st) {
	if (Empty(st)) return;
	else {
		node1<T> p = st.top;
		st.top = p->next;
		delete p;
	}
}
#pragma endregion
string Balan(string s) {
	stringstream ss(s);
	string tmp;
	while (getline(ss, tmp, '&'));
	string des;
	for (int i = 0; i < tmp.length(); i++) {
		if (isalpha(tmp[i])) {
			des += "( a & ";
			des += tmp[i];
			des += " ) | ";
		}
	}
	des.pop_back();
	des.pop_back();
	return des;
}
int main()
{
	string s = "a & (b|c)";
	cout << Balan(s) << endl;
	return 0;
}