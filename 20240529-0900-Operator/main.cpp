#include <iostream>

using namespace std;

// 카페 관리 프로그램을 만들어 달라는 요청을 받음
// 카페에 가야한다. 커피를 한잔 주문하고
/// 앉아서 카페의 업무흐름을 파악해야 한다.
// 카페의 업무흐름 속에는 역할(role)과 역할에 따른 책임(responseibility)을 파악해야 한다.

// 카페안에는 어떤 역할이 있는가?
// Cashier, Barista, Guest
// Cashier 책임: 주문을 받고 계산하고 음료 제작 요청
// Barista 책임: 음료제작
// Guest 책임: 을료주문, 계산

class Coffee {
private:
	string _name;

public:
	Coffee()
		: _name("커피") {}

	string GetName() {
		return _name;
	}
};

class Latte {
private:
	string _name;

public:
	Latte()
		: _name("라때") {}

	string GetName() {
		return _name;
	}
};

class MokaLatte {
private:
	string _name;

public:
	MokaLatte()
		: _name("모카라때") {}

	string GetName() {
		return _name;
	}
};


class Barista {
public:
	void MakeADrink(Coffee& drink) {
		cout << drink.GetName() << "을료를 만듭니다." << endl;
	}

	void MakeADrink(Latte& drink) {
		cout << drink.GetName() << "을료를 만듭니다." << endl;
	}

	void MakeADrink(MokaLatte& drink) {
		cout << drink.GetName() << "을료를 만듭니다." << endl;
	}
};

class Cashier {
private:
	Barista& _refBari; // 참조(agreggation)
public:
	Cashier(Barista& refBari)
		: _refBari(refBari) {}

	void OrderedDrink(Coffee& drink) {
		cout << drink.GetName() << "주문을 받습니다." << endl;

		_refBari.MakeADrink(drink);
	}

	void OrderedDrink(Latte& drink) {
		cout << drink.GetName() << "주문을 받습니다." << endl;

		_refBari.MakeADrink(drink);
	}

	void OrderedDrink(MokaLatte& drink) {
		cout << drink.GetName() << "주문을 받습니다." << endl;

		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& ref, Coffee& drink) { // 의존적 관계(dependency)
		cout << drink.GetName() << "음료 주문을 합니다." << endl;

		ref.OrderedDrink(drink);
	}

	void OrderingDrink(Cashier& ref, Latte& drink) { // 의존적 관계(dependency)
		cout << drink.GetName() << "음료 주문을 합니다." << endl;

		ref.OrderedDrink(drink);
	}

	void OrderingDrink(Cashier& ref, MokaLatte& drink) { // 의존적 관계(dependency)
		cout << drink.GetName() << "음료 주문을 합니다." << endl;

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