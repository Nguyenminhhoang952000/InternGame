#include<iostream>
#include"StateContext.h"
#include"LockedState.h"
#include"ClosedState.h"
#include"StateBase.h"
#include"OpennedState.h"
using namespace std;

int main() {
	//Default door open
	StateContext* context = new StateContext;
	int input = 1;
	do{
		//Status selection menu

		cout << "=========Menu=========" << endl;
		cout << "1.Open door" << endl;
		cout << "2.Close door" << endl;
		cout << "3.Lock door" << endl;
		cout << "4.Unlock door" << endl;
		cout << "0. Exit" << endl;
		cin >> input;
		switch (input)
		{
		case 1:context->open(); break;		
		case 2:context->close(); break;
		case 3:context->lock(); break;
		case 4:context->unlock(); break;
			
			
		default:
			break;
		}

	} 	while (input != 0);
}
