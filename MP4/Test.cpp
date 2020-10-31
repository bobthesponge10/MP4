using namespace std;
#include <iostream>;


class Base{
public:
	Base(){}
	virtual void identify(){
		cout << "Base";
	}
};

class Der : public Base{
public:
	Der(){}
	void identify(){
		cout << "New";
	}
};

int main_(){
	Base* c = &Der();
	c->identify();
}