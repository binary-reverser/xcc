#include<iostream>
#include<stdio.h>

#include<global.h>
#include<lexial.h>

using namespace std;
int main(){
	const char* sourceFileName = "/home/liping/study/CParser/xcc/tests/base64.x";
	cout<<"start to compile..."<<endl;
	fin = fopen(sourceFileName, "r");
	if(fin==NULL){
		cout<<"error! source file open failed:"<< sourceFileName <<endl;
		exit(0);
	}
	cout<<"File opened successfully: " << sourceFileName <<endl;
	Lexial::getSymbol();

	fclose(fin);
}
