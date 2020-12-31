#include<iostream>
#include<stdio.h>
#include<lexial.h>

using namespace std;

Lexial::Lexial(FILE* _file){
	scanner = new Scanner(_file);
}

Lexial::~Lexial() {
	delete scanner;
}

SYMBOL Lexial::getSymbol(){
	cout<<"getSymbol() called"<<endl;

	//todo:
	return null;
}
