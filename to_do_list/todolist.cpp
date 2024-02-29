#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include"../internship/taskdef.h"
using namespace std;
static  vector<task> tasks;


void filereading() {
	ifstream read("tasks.bin", ios::beg);
	int na = 0, nd = 0;
	char* name, * detail;
	int status = 0;
	if (!read.is_open()) {
		cout << "\nFile does not exist";
		return;
	}
	while (read.read((char*)&na, sizeof(na))) {
		name = new char[na];
		read.read(name, na);
		name[na] = '\0';
		read.read((char*)&nd, sizeof(nd));
		detail = new char[nd];
		read.read(detail, nd);
		detail[nd] = '\0';
		read.read((char*)&status, sizeof(status));
		task t(name, detail, status);
		tasks.push_back(t);
		name = nullptr, detail = nullptr;
	}
	read.close();
}

void filewriting() {
	ofstream read("tasks.bin",ios::beg);

	if (!read.is_open()) {
		cout << "\nFile does not exist";
		return;
	}
	int i = 0;
	while (i<tasks.size()) {
		read.write((const char*)&tasks.at(i).ns, sizeof(tasks.at(i).ns));
		read.write(tasks.at(i).getname(), tasks.at(i).ns);
		read.write((const char*)&tasks.at(i).nd, sizeof(tasks.at(i).nd));
		read.write(tasks.at(i).getdetails(), tasks.at(i).nd);
		read.write(reinterpret_cast<const char*>( & tasks.at(i).status), sizeof(tasks.at(i).status));
		i++;
	}
	read.flush();
	read.close();
}

void view() {
	system("cls");
	int i = 0;
	while (i<tasks.size()) {
		cout << "\nX-------------------------Task Number ( " << i + 1 << " ) -------------------------X";
		tasks.at(i).display();
		i++;
	}
	cout << "\nX-------------------------------------------------------------------X";
}

void delete_() {
	system("cls");
	char arr[30];
	cin.ignore();
	cout << "\nEnter task Name to delete: ";
	cin.get(arr, 30);
	const task t(arr,arr,false);
	int i = 0;
	while (i < tasks.size()) {
		if (strcmp(tasks.at(i).getname(), arr) == 0) {
			
			break;
		}
		i++;
	}

//	remove(tasks.begin(), tasks.end(), t);
	//tasks.erase(tasks.begin()+i,tasks.begin() + (i));
	tasks.erase(tasks.begin() + i);
}

void addtask() {
	system("cls");
	char name[30], details[1000];
	int status=0;
	cin.ignore();
	cout << "\nEnter task Name to Add: ";
	cin.get(name, 30);
	cin.ignore();
	cout << "\nEnter details: ";
	cin.get(details, 1000);
	task t(name, details, status);
	tasks.push_back(t);
}

void updatestatus(){
	system("cls");
	char name[30];
	cin.ignore();
	cout << "\nEnter Name of Task: ";
	cin.get(name, 30);
	int i = 0;
	while (i < tasks.size()) {
		if (strcmp(tasks.at(i).getname(), name) == 0) {
			tasks.at(i).update_status();
			return;
		}
		i++;
	}
}


int main(){
	filereading();
	
	int opt;
	while (true) {
		system("cls");
		cout << "\n---------------------------- TO DO LIST ------------------------------- \n\n\n\n\n";
		cout << "\nChoose you're desired option: ";
		cout << "\n1-View your Tasks";
		cout << "\n2-Add a new Task";
		cout << "\n3-Delete a Task";
		cout << "\n4-Update a Task";
		cout << "\nOption: ";
		cin >> opt;
		switch (opt) {
		case 1:
			view();
			break;
		case 2:
			addtask();
			break;
		case 3:
			delete_();
			break;
		case 4:
			updatestatus();
			break;
		default:
			break;
		}
		cout << "\nDo you want to Perform these Operations again? (0/1): ";
		cin >> opt;
		if (opt == 1) {
			continue;
		}
		else {
			break;
		}
	}
	filewriting();
}