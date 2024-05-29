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
// Guest å��: �����ֹ�, �� ����.

class Drink {
private:
	string _name;

public:
	Drink(string name)
		: _name(name) {}

	string GetName() {
		return _name;
	}
};

class Coffee : public Drink {
public:
	Coffee()
		: Drink("Ŀ��") {}

};

class Latte : public Drink {
public:
	Latte()
		: Drink("��") {}
};

class MokaLatte : public Drink {
public:
	MokaLatte()
		: Drink("��ī��") {}
};

class Cola : public Drink {
public:
	Cola()
		: Drink("�ݶ�") {}
};

class Barista {
public:
	void MakeADrink(Drink& drink) {
		cout << drink.GetName() << " �� ����ϴ�." << endl;
	}
};

class Cashier {
private:
	Barista& _refBari; // ����(agreggation)
public:
	Cashier(Barista& refBari)
		: _refBari(refBari) {}

	void OrderedDrink(Drink& drink) {
		cout << drink.GetName() << "�ֹ��� �޽��ϴ�." << endl;

		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& ref, Drink& drink) { // ������ ����(dependency)
		cout << drink.GetName() << "���� �ֹ��� �մϴ�." << endl;

		ref.OrderedDrink(drink);
	}
};

int main() {
	Coffee coffee;
	Latte latte;
	MokaLatte mokaLatte;
	Cola cola;
	Barista barista;
	Cashier cashier(barista);
	Guest guest;

	guest.OrderingDrink(cashier, coffee);
	cout << endl;
	guest.OrderingDrink(cashier, latte);
	cout << endl;
	guest.OrderingDrink(cashier, mokaLatte);
	cout << endl;
	guest.OrderingDrink(cashier, cola);

	return 0;
}