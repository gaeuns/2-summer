#include <iostream>
using namespace std;
#define a;

//�Լ� ���ø�
#ifdef a
// �Լ� ���� : template<typename T> void Print(T a, T b);
// T : ���ø� �Ű�����, Ŭ���̾�Ʈ���� ����
template<typename T>
void Print(T x, T y) {
	cout << x << ", " << y << endl;
}
int main() {
	Print(10, 20);
	Print(0.123, 1.123);
	Print("ABC", "abcde");

	//�Լ� ���ø��� Ÿ���� ��������� �����Ͽ� ȣ��
	cout << endl;
	Print<int>(10, 20);
	Print<double>(0.123, 1.123);
	Print<const char*>("ABC", "abcde");

	return 0;
}
#endif

//�� ���� �Ű������� ���� �Լ� ���ø�
#ifdef b
template<typename T1, typename T2>
void Print(T1 x, T2 y) {
	cout << x << ", " << y << endl;
}

int main() {
	Print(10, 1.5);
	Print("Hello!", 100);
	Print(1.5, "Hello!");

	return 0;
}
#endif

//Swap() ���ø� �Լ�
#ifdef c
template<typename T>
void Swap(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

int main() {
	int n1 = 10, n2 = 20;
	double d1 = 1.1, d2 = 2.2;
	const char* c1 = "abv", *c2 = "acd";

	cout << n1 << " " << n2 << endl;
	Swap(n1, n2);
	cout << n1 << " " << n2 << endl;
	cout << endl;

	cout << d1 << " " << d2 << endl;
	Swap(d1, d2);
	cout << d1 << " " << d2 << endl;
	cout << endl;

	cout << c1 << " " << c2 << endl;
	Swap(c1, c2);
	cout << c1 << " " << c2 << endl;
	cout << endl;

	return 0;
}
#endif

//�迭 ��� �Լ� ���ø�
#ifdef d
template<typename T, int size>
void PrintArray(T* arr) {
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "]" << arr[i] << endl;
	}
	cout << endl;
}

int main() {
	int arr1[5] = { 10,20,30,40,50 };
	//�Լ� ���ڰ� arr1�̶�� ������ �����ϹǷ� 5��� ���ø� �Ű����� ���ڸ� �����Ϸ��� �߷� �Ұ�
	//	-> ����� ȣ�� �ؾ���!
	PrintArray<int, 5>(arr1);		//����� ȣ��

	double arr2[3] = { 1.1, 2.2, 3.3 };
	PrintArray<double, 3>(arr2);	//����� ȣ��

	return 0;
}
#endif

//Point ��ü�� ������� ���ϴ� �Լ� ���ø� ����
#ifdef e
class Point {
	int x, y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
	void Print() const { cout << x << ',' << y << endl; }
};

template<typename T>
void Print(T a) {
	cout << a << endl;
}

int main() {
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);
	Print(d);
	//Point Ÿ���� ��ü pt�� cout<<pt ������ �Ұ����ϹǷ� �����Ϸ��� �Լ� ���ø� �ν��Ͻ��� �������� ����
	// �ذ��� 1 : Point Ŭ������ << ������ �����ε� �Լ� �߰�
	//				-> �ҽ��ڵ�� �������� �ʴ� ���̺귯�� ���� �� Point Ŭ������ �������� ���ϴ� ���¶�� �ذ�X
	//			2 : Point ��ü���� Ư��ȭ�� �Լ� ���ø� ����
	//Print(pt);
	
	return 0;
}
#endif

//Point ��ü���� �Լ� ���ø� Ư��ȭ ����
#ifdef f
class Point {
	int x, y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
	void Print() const { cout << x << ", " << y << endl; }
};

//�Ϲ�ȭ �Լ� ���ø�
template<typename T>
void Print(T a) {
	cout << a << endl;
}

//Ư��ȭ �Լ� ���ø�
template< >
void Print(Point a) {
	cout << "Print Ư��ȭ ���� : ";
	a.Print();
}

int main() {
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);		//Print<int>(n)		�Ϲ�ȭ ���� ȣ��
	Print(d);		//Print<double>(d)	�Ϲ�ȭ ���� ȣ��
	Print(pt);		//Print<Point>(pt)	Ư��ȭ ���� ȣ��

	return 0;
}
#endif