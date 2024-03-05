#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

double sum(vector<double>number){
	double sum = 0;
	for (double n : number) {
		sum += n;
	}
	return sum;
}

double diff(vector<double>number) {
	double diff = 0;
	for (double n : number) {
		diff = n-diff ;
	}
	return -diff;
}

double prod(vector<double>number) {
	double prod = 1;
	for (double n : number) {
		prod*= n;
	}
	return prod;
}

double ratio(vector<double> number) {
	double rat = 1;
	for (double n : number) {
		if (rat == 1) {
			rat = n;
		}
		else {
			rat = rat / n;
		}
	}
	return rat;
}
