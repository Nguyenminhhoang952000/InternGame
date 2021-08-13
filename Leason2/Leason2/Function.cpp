//Leason2: Calculate n!(n<20) and re enter if invalid
#include<iostream>
using namespace std;
unsigned long long int function(int n) {
	if (n == 1)
		return 1;
	else
		return n * function(n - 1);
}
void Input() {
	int n = 0;
	do {
		cout << "Nhap so nguyen duong n <= 20 : ";
		cin >> n;
		if (n <= 0 || n > 20) {
			cout << "\nError -> Input: ";
			cin >> n;
		}
		else
			cout << n << "! = "<<function(n);
	} 	while (n <= 0 || n > 20);
}
int main() {
	Input();
	return 0;
}