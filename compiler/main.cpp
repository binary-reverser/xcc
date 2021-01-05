#include<iostream>
#include<stdio.h>

#include<global.h>
#include<lexial.h>

FILE* fin;
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
	Lexial* lexial = new Lexial(fin);
	bool flag = lexial->getToken();
	while(flag && lexial->token->getTag() != ERR && lexial->token->getTag() != END){
		cout<<lexial->token->toString()<<endl;
		flag = lexial->getToken();
	}

	if(lexial->token->getTag() == ERR)
		lexial->showCurrent();
	
	delete lexial;
	fclose(fin);
}
