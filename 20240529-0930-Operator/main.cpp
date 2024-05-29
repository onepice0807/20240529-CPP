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

	string GetName() {
		return _name;
	}
	DrinkType GetType() {
		return _type;
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
};

class Barista {
public:
	void MakeADrink(Drink& drink) {
		switch (drink.GetType()) {
		case COFFEE:
			cout << ((Coffee&)drink).GetName() << " �� ����ϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		case LATTE:
			cout << ((Latte&)drink).GetName() << " �� ����ϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		case MOKALATTE:
			cout << ((MokaLatte&)drink).GetName() << " �� ����ϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		case COLA:
			cout << ((Cola&)drink).GetName() << " �� ����ϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		default:
			break;
		}
	}
};

class Cashier {
private:
	Barista& _refBari; // ����(agreggation)
public:
	Cashier(Barista& refBari)
		: _refBari(refBari) {}

	void OrderedDrink(Drink& drink) {
		switch (drink.GetType()) {
		case COFFEE:
			cout << ((Coffee&)drink).GetName() << "�ֹ��� �޽��ϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		case LATTE:
			cout << ((Latte&)drink).GetName() << "�ֹ��� �޽��ϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		case MOKALATTE:
			cout << ((MokaLatte&)drink).GetName() << "�ֹ��� �޽��ϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		case COLA:
			cout << ((Cola&)drink).GetName() << "�ֹ��� �޽��ϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		default:
			break;
		}
		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& ref, Drink& drink) { // ������ ����(dependency)
		switch (drink.GetType()) {
		case COFFEE:
			cout << ((Coffee&)drink).GetName() <<"���� �ֹ��� �մϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		case LATTE:
			cout << ((Latte&)drink).GetName() << " �ֹ��� �մϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		case MOKALATTE:
			cout << ((MokaLatte&)drink).GetName() << "�ֹ��� �մϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		case COLA:
			cout << ((Cola&)drink).GetName() << "�ֹ��� �մϴ�." << endl; // �ٿ� ĳ���� (down casting)
			break;
		default:
			break;
		}

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