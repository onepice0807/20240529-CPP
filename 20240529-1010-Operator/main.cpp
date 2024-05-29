#include <iostream>

using namespace std;

class Parent {
public:
	void Print() { // �Ϲݸ���Լ�
		cout << "Parent::Print()" << endl;
	}

	virtual void VPrint1() { // �����Լ�
		cout << "Parent::VPrint1()" << endl;
	}

	virtual void VPrint2() { // �����Լ�
		cout << "Parent::VPrint2()" << endl;
	}

	virtual void VPrint3() { // �����Լ�
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

// �Ϲݸ���Լ� ȣ��
void FuncPrint(Parent& ref) {
	ref.Print();
	ref.Parent::Print(); // �������ε� (�̸� ���ε�) : ���������� ��������� � ����Լ��� ȣ�����
						 // �����Ǿ����� ���� �������ε��̶�� �Ѵ�.

}

void FuncPrint(Child1& ref) {
	ref.Print();
	ref.Child1::Print(); // �������ε�
}

void FuncPrint(Child3& ref) {
	ref.Print();
	ref.Parent::Print(); // �������ε�
}

// �����Լ� ȣ��
void FuncVPrint1(Parent& ref) {
	ref.VPrint1(); // �������ε� : �����߿� � ����Լ��� ȣ��� �� �����Ǵ� ���� �������ε��̶�� �Ѵ�.
}			       // ���ε��ؼ� ȣ��� ����Լ��� ���ε��ϴ� ���� �����Ѵ�.

// �����Լ� ȣ��
void FuncVPrint2(Parent& ref) {
	ref.VPrint2();
}

int main() {
	Parent parent;
	Child1 child1;
	Child2 child2;
	Child3 child3;

	// �Ϲݸ���Լ� ȣ��
	cout << "�Ϲݸ���Լ� Call FuncPrint" << endl;
	FuncPrint(parent);
	FuncPrint(child1);
	FuncPrint(child2);
	FuncPrint(child3);
	cout << endl;
	cout << endl;

	// �������Լ� ȣ��
	cout << "�������Լ� Call FuncVPrint1" << endl;
	FuncVPrint1(parent);
	FuncVPrint1(child1);
	FuncVPrint1(child2);
	FuncVPrint1(child3);
	cout << endl;
	cout << endl;

	// �������Լ� ȣ��
	cout << "�������Լ� Call FuncVPrint2" << endl;
	FuncVPrint2(parent);
	FuncVPrint2(child1);
	FuncVPrint2(child2);
	FuncVPrint2(child3);
	cout << endl;
	cout << endl;

	return 0;
}


