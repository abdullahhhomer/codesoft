#pragma once
#include<iostream>
using namespace std;
class task {
private:
    char* task_name;

    char* task_detail;
   
public:
    int ns, nd,status;
    task(char*, char*,int);
    task();
    task(const task&);
    void update_status(int);
    void update_status();
    void set_name(char*);
    void set_details(char*);
    char* getdetails();
    char* getname();
    int getstatus();
    bool operator==(const task& obj) ;
    task& operator=(const task& obj);
    void display();
};