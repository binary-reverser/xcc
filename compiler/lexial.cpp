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

void Lexial::getNumber() {
	int val = 0;
	if(ch != '0'){ // Decimal
		do {
			val = val*10 + (ch-'0');
			scan();
		} while(ch>='0'&&ch<='9');
	} else {
		scan(); // get the char after '0'
		if(ch == 'x'){ // Hexadecimal
			scan();
			if(ch>='0'&&ch<='9'||ch>='A'&&ch<='F'||ch>='a'&&ch<='f'){
				do{
					val = val*16+ch;
					if(ch>='0'&&ch<='9') val -= '0';
					else if(ch>='A'&&ch<='F') val += (10-'A');
					else if(ch>='a'&&ch<='f') val += (10-'a');
					scan();
				} while(ch>='0'&&ch<='9'||ch>='A'&&ch<='F'||ch>='a'&&ch<='f');
			} else {
				cout<<"error, no number after 0x"<<endl;
				//todo:
				token = new Token(ERR);
				return;
			}
		} else if(ch == 'b') { // Binary
			scan();
			if(ch>='0'&&ch<='1'){
				do {
					val = val*2 + (ch-'0');
					scan();
				} while(ch>='0'&&ch<='1');
			} else {
				cout<<"error, no number after 0b"<<endl;
				//todo:
				token = new Token(ERR);
				return;
			}
		} else if(ch>='0'&&ch<='7') { // Octal
			do {
				val = val*8 + (ch-'0');
				scan();
			} while(ch>='0'&&ch<='7');
		}
	}

	token = new Num(val);
}

bool Lexial::getSymbol(){
	delete token;
	token = nullptr;

	cout<<"getSymbol called"<<endl;
	while(ch==' '||ch==10||ch==9)
	{
		scan();
  	}

	if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch=='_')
  	{
		getIdOrKeyword();
		return true;
  	} else if(ch>='0'&&ch<='9'){
		getNumber();
		return true;
	}


	//todo:
	return false;
	}
