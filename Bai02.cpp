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

void BaLanN(string s) {
	Stack<string> st;
	double ketqua = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') continue;
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			char* temp = new char;
			temp[0] = s[i];
			temp[1] = '\0';
			string a = temp;
			Push(st, a);
		}
		string temp;
		int start = 0, end = 0;
		if (s[i] >= '0' && s[i] <= '9') {
			start = i;
			for (int j = i + 1; j < s.size(); j++) {
				if (s[j] < '0' || s[j] > '9') {
					end = j; i = j - 1;
					break;
				}
			}
			end - 1;
			temp = s.substr(start, end - start);
			Push(st, temp);
		}
		if (s[i] == ')') {
			float Num1 = atof(Top(st).c_str()); Pop(st);
			string p2 = Top(st); Pop(st);
			float Num3 = atof(Top(st).c_str()); Pop(st);
			if (p2 == "+") ketqua = Num3 + Num1;
			else if (p2 == "-") ketqua = Num3 - Num1;
			else if (p2 == "*") ketqua = Num3 * Num1;
			else if (p2 == "/") ketqua = Num3 / Num1;
			// Dua lai vao stack
			string s1 = to_string(ketqua);
			Push(st, s1);
		}
		
	}
	cout << ketqua;
}
void main() {
	string s = "(22-88)*30 - 5/10 - ((100+3)/3)";
	BaLanN(s);
}
