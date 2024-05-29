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
// Guest 책임: 을료주문, 돈 지불.

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
		: _name("음료"), _type(type) {}

	virtual string GetName() {
		return _name;
	}
	DrinkType GetType() {
		return _type;
	}

	virtual void MakeADrink() {   // 가상함수
		cout << _name << "을 만듭니다." << endl;
	}

};

class Coffee : public Drink {
private:
	string _name;

public:
	Coffee()
		: _name("커피"), Drink(COFFEE) {}

	string GetName() {
		return _name;
	}

	void MakeADrink() {
		cout << _name << " 를 만듭니다." << endl;
	}
};

class Latte : public Drink {
private:
	string _name;

public:
	Latte()
		: _name("라떼"), Drink(LATTE) {}

	string GetName() {
		return _name;
	}

	void MakeADrink() {
		cout << _name << " 를 만듭니다." << endl;
	}
};

class MokaLatte : public Drink {
private:
	string _name;

public:
	MokaLatte()
		: _name("모카라떼"), Drink(MOKALATTE) {}

	string GetName() {
		return _name;
	}

	void MakeADrink() {
		cout << _name << " 를 만듭니다." << endl;
	}
};

class Cola : public Drink {
private:
	string _name;

public:
	Cola()
		: _name("콜라"), Drink(COLA) {}

	string GetName() {
		return _name;
	}

	void MakeADrink() {
		cout << _name << " 를 만듭니다." << endl;
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
	Barista& _refBari; // 참조(agreggation)
public:
	Cashier(Barista& refBari)
		: _refBari(refBari) {}

	void OrderedDrink(Drink& drink) {
		cout << drink.GetName() << "를 주문받습니다." << endl;

		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& ref, Drink& drink) { // 의존적 관계(dependency)
		cout << drink.GetName() << "를 주문합니다." << endl;

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