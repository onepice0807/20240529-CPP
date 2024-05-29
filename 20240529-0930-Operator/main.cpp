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
		: _name("커피"), Drink(COFFEE) {}

	string GetName() {
		return _name;
	}
};

class Latte : public Drink {
private:
	string _name;

public:
	Latte()
		: _name("라때"), Drink(LATTE) {}

	string GetName() {
		return _name;
	}
};

class MokaLatte : public Drink {
private:
	string _name;

public:
	MokaLatte()
		: _name("모카라때"), Drink(MOKALATTE) {}

	string GetName() {
		return _name;
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
};

class Barista {
public:
	void MakeADrink(Drink& drink) {
		switch (drink.GetType()) {
		case COFFEE:
			cout << ((Coffee&)drink).GetName() << " 를 만듭니다." << endl; // 다운 캐스팅 (down casting)
			break;
		case LATTE:
			cout << ((Latte&)drink).GetName() << " 를 만듭니다." << endl; // 다운 캐스팅 (down casting)
			break;
		case MOKALATTE:
			cout << ((MokaLatte&)drink).GetName() << " 를 만듭니다." << endl; // 다운 캐스팅 (down casting)
			break;
		case COLA:
			cout << ((Cola&)drink).GetName() << " 를 만듭니다." << endl; // 다운 캐스팅 (down casting)
			break;
		default:
			break;
		}
	}
};

class Cashier {
private:
	Barista& _refBari; // 참조(agreggation)
public:
	Cashier(Barista& refBari)
		: _refBari(refBari) {}

	void OrderedDrink(Drink& drink) {
		switch (drink.GetType()) {
		case COFFEE:
			cout << ((Coffee&)drink).GetName() << "주문을 받습니다." << endl; // 다운 캐스팅 (down casting)
			break;
		case LATTE:
			cout << ((Latte&)drink).GetName() << "주문을 받습니다." << endl; // 다운 캐스팅 (down casting)
			break;
		case MOKALATTE:
			cout << ((MokaLatte&)drink).GetName() << "주문을 받습니다." << endl; // 다운 캐스팅 (down casting)
			break;
		case COLA:
			cout << ((Cola&)drink).GetName() << "주문을 받습니다." << endl; // 다운 캐스팅 (down casting)
			break;
		default:
			break;
		}
		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& ref, Drink& drink) { // 의존적 관계(dependency)
		switch (drink.GetType()) {
		case COFFEE:
			cout << ((Coffee&)drink).GetName() <<"음료 주문을 합니다." << endl; // 다운 캐스팅 (down casting)
			break;
		case LATTE:
			cout << ((Latte&)drink).GetName() << " 주문을 합니다." << endl; // 다운 캐스팅 (down casting)
			break;
		case MOKALATTE:
			cout << ((MokaLatte&)drink).GetName() << "주문을 합니다." << endl; // 다운 캐스팅 (down casting)
			break;
		case COLA:
			cout << ((Cola&)drink).GetName() << "주문을 합니다." << endl; // 다운 캐스팅 (down casting)
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