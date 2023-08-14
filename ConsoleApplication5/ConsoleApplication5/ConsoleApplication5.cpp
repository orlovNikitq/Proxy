#include<iostream>
#include<string>
using namespace std;

class Subject {
public:
	virtual void Request() = 0;
};

class RealSubject : public Subject {	
public:
	void Request() override{
		cout << "RealSubject: обработка запроса." << endl;
	} 
};

class ProxySubject : public Subject {
	RealSubject* realSub;
public:
	ProxySubject() {
		realSub = new RealSubject();
	}

	void Request() override {
		cout << "ProxySubject: Подготовка перед передачей запроса."<<endl;
		realSub->Request();
		cout << "ProxySubject: Завершение после передачи запроса."<<endl;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	ProxySubject proxy;
	proxy.Request();
}