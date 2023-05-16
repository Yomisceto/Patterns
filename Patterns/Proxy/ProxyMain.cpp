#include "GumballMonitor.h"
#include "../State/GumballMachine.h"

void ProxyTest() {
	GumballMachine gm(10,"Berezhany");
	ProxyMonitor pm(&gm);
	pm.report();
}

//int main(void)
//{
//	ProxyTest();
//	return 0;
//}