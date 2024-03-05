#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include"calculator.h"
using namespace std;
int main() {
	char ch;
	
	while (true) {
		vector <double>num;
		int gett;
		string value;
		cout << "\n\n-------------------------------------CALCULATOR-------------------------------------\n\n";
		cout << "\nChoose the operation: ";
		cout << "\n1-Sum (+)";
		cout << "\n2-Difference (-)";
		cout << "\n3-Ratio (/) ";
		cout << "\n4-Product (*)";
		cout << "\nOption: ";
		cin >> ch;
		if (ch == '+') {
			cin.ignore();
			cout << "\nEnter the series of numbers seperated with spaces who's Sum is to be found: ";
			getline(cin, value);
			stringstream series(value);
			while (series >> gett) {
				num.push_back(gett);
			}
			cout << "\nSum of Numbers is: " << sum(num);
		}
		else if (ch == '-') {
			cin.ignore();
			cout << "\nEnter the series of numbers seperated with spaces who's Difference is to be found: ";
			getline(cin, value);
			stringstream series(value);
			while (series >> gett) {
				num.push_back(gett);
			}
			cout << "\nDifference of Numbers is: " << diff(num);
		}
		else if (ch == '*') {
			cin.ignore();
			cout << "\nEnter the series of numbers seperated with spaces who's Product is to be found: ";
			getline(cin, value);
			stringstream series(value);
			while (series >> gett) {
				num.push_back(gett);
			}
			cout << "\nProduct of Numbers is: " << prod(num);
		}
		else if (ch == '/') {
			cin.ignore();
			cout << "\nEnter the series of numbers seperated with spaces who's Ratio is to be found: ";
			getline(cin, value);
			stringstream series(value);
			while (series >> gett) {
				num.push_back(gett);
			}
			cout << "\nRatio of Numbers is: " << ratio(num);
		}
		else {
			continue;
		}
		cout << "\nIf you want to exit press 0: ";
		cin >> ch;
	
		if (ch == '0') {
			exit(0);
		}
		else {
			system("cls");
		}

	}
}