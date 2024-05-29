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

// ���� ���� �Լ��� �ϳ��� ������ �ִ� Ŭ������ �߻�Ŭ������� �Ѵ�.
// �߻�Ŭ������ �ڽ��� ��ü�� ���� �� ����.
// �߻�Ŭ������ �ڽ��� ��ü�� ���� �� ������
// �ڽſ��Լ� ��ӹ��� �ڽ�Ŭ�������� �ڽ��� ���� ���� �Լ��� �����ϰ�
// �����ϴ� �ɷ��� ����

class Drink {
private:
	string _name;

public:
	Drink()
		: _name("����") {}

	virtual string GetName() {
		return _name;
	}

	virtual void MakeADrink() = 0; // ���� ���� �Լ�

};

class Coffee : public Drink {
private:
	string _name;

public:
	Coffee()
		: _name("Ŀ��") {}

	string GetName() {
		return _name;
	}

	void MakeADrink() override {
		cout << _name << " �� ����ϴ�." << endl;
	}
};

class Latte : public Drink {
private:
	string _name;

public:
	Latte()
		: _name("��") {}

	string GetName() {
		return _name;
	}

	void MakeADrink() override {
		cout << _name << " �� ����ϴ�." << endl;
	}
};

class MokaLatte : public Drink {
private:
	string _name;

public:
	MokaLatte()
		: _name("��ī��") {}

	string GetName() {
		return _name;
	}

	void MakeADrink() override {
		cout << _name << " �� ����ϴ�." << endl;
	}
};

class Cola : public Drink {
private:
	string _name;

public:
	Cola()
		: _name("�ݶ�") {}

	string GetName() {
		return _name;
	}

	void MakeADrink() override {
		cout << _name << " �� ����ϴ�." << endl;
	}
};

class BanillaLatte : public Drink {
private:
	string _name;

public:
	BanillaLatte()
		: _name("�ٴҶ��") {}

	string GetName() {
		return _name;
	}

	void MakeADrink() override {
		cout << _name << " �� ����ϴ�." << endl;
	}

};

class ChokoLatte : public Drink {
private:
	string _name;

public:
	ChokoLatte()
		: _name("���ڶ�") {}

	string GetName() {
		return _name;
	}

	void MakeADrink() override {
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
	BanillaLatte banillaLatte;
	ChokoLatte chokoLatte;
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
	cout << endl;
	guest.OrderingDrink(cashier, banillaLatte);
	cout << endl;
	guest.OrderingDrink(cashier, chokoLatte);

	return 0;
}