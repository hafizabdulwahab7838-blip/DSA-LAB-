#include<iostream>
using namespace std;
class employee {
	virtual void calculatesalary() = 0;
};
class fulltimeemployee :public employee {
	int fixedsalary;
public:
	fulltimeemployee(int fix) {
		fixedsalary = fix;
	}
	void calculatesalary()override {
		cout << "Full time employee:" << endl;
		cout << "Fixed salary:" << fixedsalary << endl;
	 }
};
class parttimeemployee :public employee {

	int hours;
	int hourrate;
public:
	parttimeemployee(int h, int hrate) {
		hours = h;
		hourrate = hrate;
	}
	void calculatesalary()override {
		cout << "Parttime employee:" << endl;
		cout << "Hours:" << hours << endl;
		cout << "Hours rate:" << hourrate << endl;
		cout << "Fixed salary:" << hours * hourrate << endl;

	}
};
int main() {
	fulltimeemployee c1(100000);
	c1.calculatesalary();
	parttimeemployee c2(96, 200);
	c2.calculatesalary();

}