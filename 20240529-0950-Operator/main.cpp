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

enum DrinkType {
	COFFEE,
	LATTE,
	MOKALATTE,
	COLA
};

class Drink {
private:
	string _name;
	DrinkType _type;

public:
	Drink(DrinkType type)
		: _name("����"), _type(type) {}

	virtual string GetName() {
		return _name;
	}
	DrinkType GetType() {
		return _type;
	}

	virtual void MakeADrink() {   // �����Լ�
		cout << _name << "�� ����ϴ�." << endl;
	}

};

class Coffee : public Drink {
private:
	string _name;

public:
	Coffee()
		: _name("Ŀ��"), Drink(COFFEE) {}

	string GetName() {
		return _name;
	}

	void MakeADrink() {
		cout << _name << " �� ����ϴ�." << endl;
	}
};

class Latte : public Drink {
private:
	string _name;

public:
	Latte()
		: _name("��"), Drink(LATTE) {}

	string GetName() {
		return _name;
	}

	void MakeADrink() {
		cout << _name << " �� ����ϴ�." << endl;
	}
};

class MokaLatte : public Drink {
private:
	string _name;

public:
	MokaLatte()
		: _name("��ī��"), Drink(MOKALATTE) {}

	string GetName() {
		return _name;
	}

	void MakeADrink() {
		cout << _name << " �� ����ϴ�." << endl;
	}
};

class Cola : public Drink {
private:
	string _name;

public:
	Cola()
		: _name("�ݶ�"), Drink(COLA) {}

	string GetName() {
		return _name;
	}

	void MakeADrink() {
		cout << _name << " �� ����ϴ�." << endl;
	}
};

class Barista {
public:
	void MakeADrink(Drink& drink) {
		drink.MakeADrink();
	}
};

class Cashier {
private:
	Barista& _refBari; // ����(agreggation)
public:
	Cashier(Barista& refBari)
		: _refBari(refBari) {}

	void OrderedDrink(Drink& drink) {
		cout << drink.GetName() << "�� �ֹ��޽��ϴ�." << endl;

		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& ref, Drink& drink) { // ������ ����(dependency)
		cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;

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