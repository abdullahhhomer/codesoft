#pragma once
#include"task.h"
task::task() {
	this->task_name = new char[30];
	this->task_detail = new char[1000];
	status = 0;
	ns = 0;
	nd = 0;
}
task::task(char* name, char* detail,int status) {
	this->task_name = new char[30];
	this->task_detail = new char[1000];
	this->set_details(detail);
	this->set_name(name);
	this->update_status(status);
}

task::task(const task& t) {
	this->task_name = new char[30];
	this->task_detail = new char[1000];
	this->set_details(t.task_detail);
	this->set_name(t.task_name);
	this->update_status(t.status);
}

void task::update_status(int update) {
	this->status = update;
}

void task::update_status() {
	if (this->status == 0) {
		this->status = 1;
	}
	else {
		this->status = 0;
	}
}

void task::set_name(char* name) {
	int i = 0;
	while (name[i] != '\0') {
		task_name[i] = name[i];
		i++;
	}
	task_name[i] = '\0';
	ns = i;
}

void task::set_details(char* detail) {
	int i = 0;
	while (detail[i] != '\0') {
		task_detail[i] = detail[i];
		i++;
	}
	task_detail[i] = '\0';
	nd = i;
}

char* task::getdetails() {
	return task_detail;
}

char* task::getname() {
	return task_name;
}

int task::getstatus() {
	return status;
}


bool task::operator==(const task& obj) {
	if (strcmp(obj.task_name, this->task_name) == 0) {
		return true;
	}
	return false;
}

task& task::operator=(const task& obj) {
	this->task_name = new char[obj.ns];
	this->task_detail = new char[obj.nd];
	this->set_details(obj.task_detail);
	this->set_name(obj.task_name);
	this->update_status(obj.status);
	return *this;
}

void task::display() {
	cout << "\nName of Task is: " << (const char*)task_name;
	cout << "\nDetails of Task are: " << (const char*)task_detail;
	cout << "\nStatus: ";
	if (status==1) {
		cout << "Completed";
	}
	else {
		cout << "Incomplete";
	}
	cout << endl;

}