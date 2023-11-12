#include "C++.h"
using namespace std;
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
void Init(Stack<T>& st);
// Kiem tra stack rong
template <class T>
bool Empty(Stack<T> st);
// Tao mot node mõi 
template <class T>
node1<T> MakeNode(T x);
// Them phan tu vao dau stack
template <class T>
void Push(Stack<T>& st, T x);
// Lay gia tri cua phan tu dau stack
template <class T>
T Top(Stack<T> st);
// Lay phan tu dau ra khoi stack
template <class T>
void Pop(Stack<T>& st);