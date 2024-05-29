#include <iostream>

using namespace std;

class Parent {
public:
	void Print() { // 일반멤버함수
		cout << "Parent::Print()" << endl;
	}

	virtual void VPrint1() { // 가상함수
		cout << "Parent::VPrint1()" << endl;
	}

	virtual void VPrint2() { // 가상함수
		cout << "Parent::VPrint2()" << endl;
	}

	virtual void VPrint3() { // 가상함수
		cout << "Parent::VPrint3()" << endl;
	}
 };

class Child1 : public Parent {
public:
	void Print() {
		cout << "child1::Print()" << endl;
	}

	void VPrint1() override {
		cout << "child1::VPrint1()" << endl;
	}
};

class Child2 : public Parent {
public:
	void Print() {
		cout << "child2::Print()" << endl;
	}

	void VPrint2() override {
		cout << "child1::VPrint2()" << endl;
	}
};

class Child3 : public Parent {
public:
	void VPrint3() override {
		cout << "child3::VPrint3()" << endl;
	}
};

// 일반멤버함수 호출
void FuncPrint(Parent& ref) {
	ref.Print();
	ref.Parent::Print(); // 정적바인딩 (이른 바인딩) : 실행파일이 만들어질때 어떤 멤버함수가 호출될지
						 // 결정되어지는 것을 정적바인딩이라고 한다.

}

void FuncPrint(Child1& ref) {
	ref.Print();
	ref.Child1::Print(); // 정적바인딩
}

void FuncPrint(Child3& ref) {
	ref.Print();
	ref.Parent::Print(); // 정적바인딩
}

// 가상함수 호출
void FuncVPrint1(Parent& ref) {
	ref.VPrint1(); // 동적바인딩 : 실행중에 어떤 멤버함수가 호출될 지 결정되는 것을 동적바인딩이라고 한다.
}			       // 바인딩해서 호출될 멤버함수를 바인딩하는 것을 유보한다.

// 가상함수 호출
void FuncVPrint2(Parent& ref) {
	ref.VPrint2();
}

int main() {
	Parent parent;
	Child1 child1;
	Child2 child2;
	Child3 child3;

	// 일반멤버함수 호출
	cout << "일반멤버함수 Call FuncPrint" << endl;
	FuncPrint(parent);
	FuncPrint(child1);
	FuncPrint(child2);
	FuncPrint(child3);
	cout << endl;
	cout << endl;

	// 가상멤버함수 호출
	cout << "가상멤버함수 Call FuncVPrint1" << endl;
	FuncVPrint1(parent);
	FuncVPrint1(child1);
	FuncVPrint1(child2);
	FuncVPrint1(child3);
	cout << endl;
	cout << endl;

	// 가상멤버함수 호출
	cout << "가상멤버함수 Call FuncVPrint2" << endl;
	FuncVPrint2(parent);
	FuncVPrint2(child1);
	FuncVPrint2(child2);
	FuncVPrint2(child3);
	cout << endl;
	cout << endl;

	return 0;
}


