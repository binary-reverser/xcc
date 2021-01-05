#ifndef LEXIAL_H
#define LEXIAL_H

#include<global.h>
#include<scanner.h>
#include<token.h>


class Lexial {
private:
	Scanner* scanner;
	void getIdOrKeyword();
	void getNumber();
	void getChar();
	void getStr();
	void getDelimiter();
	bool scan(char need=0);
public:
	char ch;
	Token* token;
	Lexial(FILE* _file);
	~Lexial();
	bool getToken();
	void showCurrent();
};

#endif
