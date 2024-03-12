#include<iostream>
#include<vector>
using namespace std;
void printvector(vector<int> v) {
	for (int i : v) {
		cout << i<<" ";
	}
}

int main() {
	int num1,opt,num2;
	vector<int> low, high;
	
	srand(time(NULL));
	num1 = rand() % 50;

	while (true) {
		cout << "\n-----------------------------------Number Guessing Game-----------------------------------\n\n\n";
		cout << "\n1-Guess the number ";
		cout << "\n2-View list of the numbers guessed already";
		cout << "\n3-Give up!";
		cout << "\nOption: ";
		cin >> num2;
		if (num2 == 1) {
			cout << "\nEnter the number: ";
			cin >> opt;

			if (opt == num1) {
				cout << "\nYAYYYYYYYYYY YOU WON!";
				break;
			}
			else if (opt < num1) {
				cout << "\n Go Higher";
				high.push_back(opt);
				cout << "\n";
				system("pause");
				system("cls");
			}
			else {
				cout << "\nGo Low";
				low.push_back(opt);
				cout << "\n";
				system("pause");
				system("cls");
			}
		}
		else if (num2 == 2) {
			cout << "\nHigh guesses: ";
			printvector(low);
			cout << "\nLow guesses: ";
			printvector(high);
			cout << "\n";
			system("pause");
			system("cls");
		}
		else if (num2 == 3) {
			cout << "\nNumber was: " << num1;
			break;
		}
	}
}