#include<iostream>
#include<stdio.h>
#include<lexial.h>

using namespace std;

Lexial::Lexial(FILE* _file){
	CHAR_INFO charInfo;
	scanner = new Scanner(_file);

	while(!scanner->getChar(charInfo)){
		cout<<charInfo.ch;
	}
}

Lexial::~Lexial() {
	delete scanner;
}

TAG Lexial::getSymbol(){
	cout<<"getSymbol() called"<<endl;


	//todo:
	return ERR;
}
