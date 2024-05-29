#include <iostream>

using namespace std;

// ī�� ���� ���α׷��� ����� �޶�� ��û�� ����
// ī�信 �����Ѵ�. Ŀ�Ǹ� ���� �ֹ��ϰ�
/// �ɾƼ� ī���� �����帧�� �ľ��ؾ� �Ѵ�.
// ī���� �����帧 �ӿ��� ����(role)�� ���ҿ� ���� å��(responseibility)�� �ľ��ؾ� �Ѵ�.

// ī��ȿ��� � ������ �ִ°�?
// Cashier, Barista, Guest
// Cashier å��: �ֹ��� �ް� ����ϰ� ���� ���� ��û
// Barista å��: ��������
// Guest å��: �����ֹ�, ���

class Coffee {
private:
	string _name;

public:
	Coffee()
		: _name("Ŀ��") {}

	string GetName() {
		return _name;
	}
};

class Latte {
private:
	string _name;

public:
	Latte()
		: _name("��") {}

	string GetName() {
		return _name;
	}
};

class MokaLatte {
private:
	string _name;

public:
	MokaLatte()
		: _name("��ī��") {}

	string GetName() {
		return _name;
	}
};


class Barista {
public:
	void MakeADrink(Coffee& drink) {
		cout << drink.GetName() << "���Ḧ ����ϴ�." << endl;
	}

	void MakeADrink(Latte& drink) {
		cout << drink.GetName() << "���Ḧ ����ϴ�." << endl;
	}

	void MakeADrink(MokaLatte& drink) {
		cout << drink.GetName() << "���Ḧ ����ϴ�." << endl;
	}
};

class Cashier {
private:
	Barista& _refBari; // ����(agreggation)
public:
	Cashier(Barista& refBari)
		: _refBari(refBari) {}

	void OrderedDrink(Coffee& drink) {
		cout << drink.GetName() << "�ֹ��� �޽��ϴ�." << endl;

		_refBari.MakeADrink(drink);
	}

	void OrderedDrink(Latte& drink) {
		cout << drink.GetName() << "�ֹ��� �޽��ϴ�." << endl;

		_refBari.MakeADrink(drink);
	}

	void OrderedDrink(MokaLatte& drink) {
		cout << drink.GetName() << "�ֹ��� �޽��ϴ�." << endl;

		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& ref, Coffee& drink) { // ������ ����(dependency)
		cout << drink.GetName() << "���� �ֹ��� �մϴ�." << endl;

		ref.OrderedDrink(drink);
	}

	void OrderingDrink(Cashier& ref, Latte& drink) { // ������ ����(dependency)
		cout << drink.GetName() << "���� �ֹ��� �մϴ�." << endl;

		ref.OrderedDrink(drink);
	}

	void OrderingDrink(Cashier& ref, MokaLatte& drink) { // ������ ����(dependency)
		cout << drink.GetName() << "���� �ֹ��� �մϴ�." << endl;

		ref.OrderedDrink(drink);
	}
};

int main() {
	Coffee coffee;
	Latte latte;
	MokaLatte mokaLatte;
	Barista barista;
	Cashier cashier(barista);
	Guest guest;

	guest.OrderingDrink(cashier, coffee);
	cout << endl;
	guest.OrderingDrink(cashier, latte);
	cout << endl;
	guest.OrderingDrink(cashier, mokaLatte);

	return 0;
}