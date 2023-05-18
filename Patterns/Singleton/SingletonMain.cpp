
#include "Singleton.h"
#include <iostream>
#include <thread>

void ThreadFoo();
void ThreadBar();

//int main() {
//	std::thread t1(ThreadFoo);
//	std::thread t2(ThreadBar);
//	t1.join();
//	t2.join();
//}

void ThreadFoo() {
	const Singleton* singleton = Singleton::GetInstance("Foo");
	std::cout << singleton->value() << std::endl;
}

void ThreadBar() {
	const Singleton* singleton = Singleton::GetInstance("Bar");
	std::cout << singleton->value() << std::endl;
}