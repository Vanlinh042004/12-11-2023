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

struct SinhVien {
	int id;
	char ten[30];
	char gioiTinh[5];
	int tuoi;
	float diemToan;
	float diemLy;
	float diemHoa;
	float diemTB = 0;
	char hocluc[10] = "-";
};
using SV = SinhVien;
void Print(SV sv) {
	cout << sv.id << " " << sv.ten << " "; /*<< sv.gioiTinh << " " << sv.diemToan << "-" << sv.diemLy << "-" << sv.diemHoa << " " << sv.diemTB << " " << sv.hocluc;*/
	cout << endl;
}
struct Node {
	SV data;
	Node* next;
};
using node = Node*;

// Tao 1 node
node MakeNode() {
	SV sv;
	cout << "Nhap id: "; cin >> sv.id;
	cin.ignore();
	cout << "Nhap ten: "; cin.getline(sv.ten, 30);
	/*cout << "Nhap gioi tinh: "; cin.getline(sv.gioiTinh, 5);
	cout << "Nhap tuoi: "; cin >> sv.tuoi;
	cout << "Nhap diem Toan - Ly - Hoa: "; cin >> sv.diemToan >> sv.diemLy >> sv.diemHoa;
	cout << "Nhap diem trung binh: "; cin >> sv.diemTB;
	cin.ignore();
	cout << "Nhap hoc luc: "; cin.getline(sv.hocluc, 10);*/
	node p = new Node;
	p->data = sv;
	p->next = NULL;
	return p;
}
void Free(node& head) {
	if (head == NULL) return;
	node p = head;
	Free(head->next);
	delete p;
}
#pragma region Cau1
// 1. Them 1 sinh vien
int size(node head) {
	int n = 0;
	while (head != NULL) {
		n++;
		head = head->next;
	}
	return n;
}
void InsertFirst(node& head) {
	node temp = MakeNode();
	if (head == NULL) head = temp;
	else {
		temp->next = head;
		head = temp;
	}
}
void InsertLast(node& head) {
	SinhVien x;
	node temp = MakeNode();
	if (head == NULL) {
		head = temp;
		return;
	}
	node p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = temp;
}
void Insert(node& head, int& pos) {
	int n = size(head);
	do {
		cout << "Nhap pos: ";
		cin >> pos;
		if (pos<1 || pos>n + 1) cout << "Vi tri khong thoa! Moi nhap lai\n";
	} while (pos<1 || pos>n + 1);
	if (pos == 1) {
		InsertFirst(head);
		return;
	}
	if (pos == n + 1) {
		InsertLast(head);
		return;
	}
	SinhVien x;
	node temp = MakeNode();
	node p = head;
	for (int i = 1; i < pos - 1; i++) {
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;
}
#pragma endregion
#pragma region Cau2
// Cap nhat thong tin theo Id
int SearchID(node head, int& Id) {
	if (head == NULL) return 0;
	cout << "Nhap id can tim: "; cin >> Id;
	int count = 0;
	while (head != NULL) {
		count++;
		if (head->data.id == Id) break;
		head = head->next;
	}
	if (count > size(head)) return 0; // Khong co id nao thoa
	return count;
}
void Update(node& head, int Id) {
	int pos = SearchID(head, Id);
	if (pos == 0) {
		cout << "Khong tim thay ID nao!\n";
		return;
	}
	node p = head;
	for (int i = 1; i < pos - 1; i++) {
		p = p->next;
	}
	cout << "Cap nhat lai thong tin:\n";
	cout << "Nhap id: "; cin >> p->data.id;
	cin.ignore();
	cout << "Nhap ten: "; cin.getline(p->data.ten, 30);
	cout << "Nhap gioi tinh: "; cin.getline(p->data.gioiTinh, 5);
	cout << "Nhap tuoi: "; cin >> p->data.tuoi;
	cout << "Nhap diem Toan - Ly - Hoa: "; cin >> p->data.diemToan >> p->data.diemLy >> p->data.diemHoa;
	cout << "Nhap diem trung binh: "; cin >> p->data.diemTB;
	cin.ignore();
	cout << "Nhap hoc luc: "; cin.getline(p->data.hocluc, 10);
}
#pragma endregion
#pragma region Cau3
void DeleteFirst(node& head) {
	if (head == NULL) return;
	node p = head;
	head = head->next;
	delete p;
}void DeleteLast(node& head) {
	if (head == NULL) return;
	node p = head;
	if (p->next == NULL) { // chi co 1 node
		delete head;
		return;
	}
	while (p->next->next != NULL) {
		p = p->next;
	}
	delete p->next;
}

void DeleteId(node& head, int Id) {
	int n = size(head);
	int pos = SearchID(head, Id);
	if (pos == 0) {
		cout << "Khong tim thay Id nao!\n";
		return;
	}
	if (pos == 1) {
		DeleteFirst(head);
		return;
	}
	if (pos == n) {
		DeleteLast(head);
		return;
	}
	node pre = NULL, curr = head;
	if (head->next == NULL) delete head; // nau danh sach chi co 1 node
	for (int i = 1; i < pos; i++) {
		pre = curr;
		curr = curr->next;
	}
	pre->next = curr->next;
	delete curr;
}
#pragma endregion
#pragma region Cau4
// Tim kiem sinh vien theo ten (Phan biet hoa thuong)
void SearchName(node head, char name[30]) {
	if (head == NULL) {
		cout << "Khong co sinh vien nao!\n";
		return;
	}
	node p = head;
	int count = 1;
	while (p != NULL && strcmp(p->data.ten, name) != 0) {
		count++;
		p = p->next;
	}
	if (count < size(head)) {
		cout << "Sinh vien can tim: ";
		Print(p->data);
	}
	else if (count > size(head)) cout << "Khong co sinh vien nao!\n";
}
#pragma endregion
#pragma region Cau5
// Sap xep theo diem trung binh
void Swap(SV& a, SinhVien& b) {
	SV c = a;
	a = b;
	b = c;
}
void SortDiemTB(node& head) {
	if (head == NULL) return;
	for (node i = head; i != NULL; i = i->next) {
		node min = i;
		for (node j = i->next; j != NULL; j = j->next) {
			if (j->data.diemTB < min->data.diemTB) min = j;
		}
		Swap(i->data, min->data);
	}
}
#pragma endregion
#pragma region Cau6
// Sap xep sinh vien theo ten
int Asc(const char* s1, const char* s2)
{
	stringstream ss1(s1), ss2(s2);
	Stack<string> v1, v2;
	string tmp;
	while (ss1 >> tmp) Push(v1,tmp);
	while (ss2 >> tmp) Push(v2, tmp);

	while (!Empty(v1) && !Empty(v2))
	{
		if (strcmp(Top(v1).c_str(), Top(v2).c_str()) == 0)
		{
			Pop(v1);
			Pop(v2);
		}
		else return strcmp(Top(v1).c_str(), Top(v2).c_str());
	}
	if (Empty(v1) && Empty(v2)) return 0;
	else if (Empty(v1)) return 1;
	else return -1;
}
void SortName(node& head) {
	if (head == NULL) return;
	for (node i = head; i != NULL; i = i->next) {
		node min = i;
		for (node j = i->next; j != NULL; j = j->next) {
			if (Asc(i->data.ten, j->data.ten)>0) min = j;
		}
		Swap(i->data, min->data);
	}
}
#pragma endregion
#pragma region Cau7
// 7. Hien thi danh sach sinh vien
void PrintList(node head) {
	cout << "------\n";
	if (head == NULL) {
		cout << "Khong co sinh vien nao!\n";
		return;
	}
	while (head != NULL) {
		Print(head->data);
		head = head->next;
	}
	cout << "------\n";
}
#pragma endregion
void main() {
	cout << "----------MENU----------\n";
	cout << "0. Thoat\n";
	cout << "1. Them sinh viem\n";
	cout << "2.Cap nhap thong tin sinh vien boi id\n";
	cout << "3.Xoa sinh vien boi id\n";
	cout << "4.Tim kiem sinh vien theo ten\n";
	cout << "5.Sap xep sinh vien theo diem TB\n";
	cout << "6.Sap xep sinh vien theo ten\n";
	cout << "7.Hien thi danh sach sinh vien\n";
	cout << "----------END----------\n";
	node head = NULL;
	int choice = 0;
	int pos = 0;
	int Id = 0;
	while (1) {
		do {
			cout << "Nhap lua chon cua ban:";
			cin >> choice;
			if (choice < 0 || choice>7) cout << "Loi!Nhap lai!\n";
		} while (choice < 0 || choice>7);
		if (choice == 0) {
			Free(head);
			break;
		}
		if (choice == 1) {
			Insert(head, pos);
		}
		if (choice == 2) {
			Update(head, Id);
		}
		if (choice == 3) {
			DeleteId(head, Id);
		}
		if (choice == 4) {
			char name[30];
			cout << "Nhap ten can tim: "; cin.getline(name, 30);
			SearchName(head, name);
		}
		else if (choice == 5) {
			SortDiemTB(head);
		}
		if (choice == 6) {
			SortName(head);
		}
		else if (choice == 7) {
			PrintList(head);
		}
	}
}