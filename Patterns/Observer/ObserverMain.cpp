#pragma once
#include "Subject.h"
#include "Observer.h"

#define _newline std::cout << std::endl;

void ClientCode() {
	Subject* subject = new Subject;
	Observer* observer1 = new Observer(*subject);
	Observer* observer2 = new Observer(*subject);
	Observer* observer3 = new Observer(*subject);
	Observer* observer4;

	subject->SetMessage("All Observers added."); _newline

	observer3->RemoveFromList();
	subject->SetMessage("Observer removed."); _newline

	observer4 = new Observer(*subject);
	subject->SetMessage("New Observer added."); _newline


	delete observer1;
	delete observer2;
	delete observer3;
	delete observer4;
	delete subject;
}

int main() {
	ClientCode();

	return 0;
}