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

	if(scanner->isEnd()) return false;

	if(need) {
		if(ch != need) return false;

		ch = scanner->getChar();
		if(scanner->isEnd()) return false;
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
    if(tag == ID) token = new Id(name);   
    else token = new Token(tag);
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

void Lexial::getStr() {
	string str = "";
	while(!scan('\"')) {
		if(ch == '\\') {
			scan();
			if(ch == 'n') str.push_back('\n');
			else if(ch == '\\') str.push_back('\\');
			else if(ch == 't') str.push_back('\t');
			else if(ch == '"') str.push_back('"');
			else if(ch == '0') str.push_back('\0');
			else if(ch == '\n') ;
			else if(ch == -1){
				cout<<"string no right qution"<<endl;
				token = new Token(ERR);
				break;
			} else str.push_back(ch);
		} else if(ch=='\n'||ch==-1) { // end of file
			cout<<"string no right qution"<<endl;
			token = new Token(ERR);
			break;
		} else str.push_back(ch);
	}

	if(!token) token = new Str(str);
}

void Lexial::getChar() {
	char c;

	scan();
	if(ch == '\\') {
		scan();
		if(ch == 'n') c = '\n';
		else if(ch == '\\') c = '\\';
		else if(ch == 't') c = '\t';
		else if(ch == '0') c = '\0';
		else if(ch == '\'') c = '\'';
		else if(ch==-1 || ch=='\n') { //end of file or newline
			cout<<"error, end of file or newline"<<endl;
			token = new Token(ERR);
			return;
		}
		else c = ch;
	} else if(ch=='\n'||ch==-1) {
		cout<<"error, end of file or newline"<<endl;
		token = new Token(ERR);
		return;
	} else if(ch=='\'') { // no data
		cout<<"no data"<<endl;
		token = new Token(ERR);
		return;
	} else c = ch;
	
	if(!token) {
		if(scan('\'')) {
			token = new Char(c);
		} else {
			cout<<"no right qution"<<endl;
			token = new Token(ERR);
		}
	}
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
	} else if(ch == '\'') {
		getChar();
		return true;
	} else if(ch == '\"') {
		getStr();
		return true;
	}

	//todo:
	return false;
	}
