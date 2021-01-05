#include<iostream>
#include<stdio.h>
#include<lexial.h>

using namespace std;

Lexial::Lexial(FILE* _file){
	scanner = new Scanner(_file);
	ch = ' ';
	token = nullptr;
}

Lexial::~Lexial() {
	delete scanner;
}

bool Lexial::scan(char need) {
	ch = scanner->getChar();

	if(scanner->isEnd())
		return false;

	if(need) {
		if(ch != need)
			return false;

		//ch = scanner->getChar();;
		//return true;
	}

	return true;
}

Keywords keywords;

void Lexial::getIdOrKeyword(){
	string name = ""; 
    do  
    {   
        name.push_back(ch);
        scan();
    } while(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch=='_'||ch>='0'&&ch<='9');
            
    TAG tag = keywords.getTag(name);
    if(tag == ID) {
        token = new Id(name);
    }   
    else
        token = new Token(tag);
}

bool Lexial::getSymbol(){
	cout<<"getSymbol called"<<endl;
	while(ch==' '||ch==10||ch==9)
	{
    	scan();
  	}

	if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch=='_')
  	{
		getIdOrKeyword();
    	return true;
  	}


	//todo:
	return false;
	}
