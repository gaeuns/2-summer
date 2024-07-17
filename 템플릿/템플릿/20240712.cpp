#include <iostream>
using namespace std;
#define a;

//함수 템플릿
#ifdef a
// 함수 형식 : template<typename T> void Print(T a, T b);
// T : 템플릿 매개변수, 클라이언트에서 결정
template<typename T>
void Print(T x, T y) {
	cout << x << ", " << y << endl;
}
int main() {
	Print(10, 20);
	Print(0.123, 1.123);
	Print("ABC", "abcde");

	//함수 템플릿의 타입을 명시적으로 지정하여 호출
	cout << endl;
	Print<int>(10, 20);
	Print<double>(0.123, 1.123);
	Print<const char*>("ABC", "abcde");

	return 0;
}
#endif

//두 개의 매개변수를 갖는 함수 템플릿
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

//Swap() 템플릿 함수
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

//배열 출력 함수 템플릿
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
	//함수 인자가 arr1이라는 정보만 제공하므로 5라는 템플릿 매개변수 인자를 컴파일러가 추론 불가
	//	-> 명시적 호출 해야함!
	PrintArray<int, 5>(arr1);		//명시적 호출

	double arr2[3] = { 1.1, 2.2, 3.3 };
	PrintArray<double, 3>(arr2);	//명시적 호출

	return 0;
}
#endif

//Point 객체를 출력하지 못하는 함수 템플릿 예제
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
	//Point 타입의 객체 pt는 cout<<pt 연산이 불가능하므로 컴파일러가 함수 템플릿 인스턴스를 생성하지 못함
	// 해결방법 1 : Point 클래스에 << 연산자 오버로딩 함수 추가
	//				-> 소스코드로 지원되지 않는 라이브러리 상태 등 Point 클래스를 수정하지 못하는 상태라면 해결X
	//			2 : Point 객체만의 특수화된 함수 템플릿 지원
	//Print(pt);
	
	return 0;
}
#endif

//Point 객체만의 함수 템플릿 특수화 지원
#ifdef f
class Point {
	int x, y;
public:
	explicit Point(int _x = 0, int _y = 0) :x(_x), y(_y) { }
	void Print() const { cout << x << ", " << y << endl; }
};

//일반화 함수 템플릿
template<typename T>
void Print(T a) {
	cout << a << endl;
}

//특수화 함수 템플릿
template< >
void Print(Point a) {
	cout << "Print 특수화 버전 : ";
	a.Print();
}

int main() {
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);		//Print<int>(n)		일반화 버전 호출
	Print(d);		//Print<double>(d)	일반화 버전 호출
	Print(pt);		//Print<Point>(pt)	특수화 버전 호출

	return 0;
}
#endif