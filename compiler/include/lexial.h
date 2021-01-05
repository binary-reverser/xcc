#ifndef LEXIAL_H
#define LEXIAL_H

#include<global.h>
#include<scanner.h>
#include<token.h>


class Lexial {
private:
	Scanner* scanner;
public:
	char ch;
	Token* token;
	Lexial(FILE* _file);
	~Lexial();
	bool scan(char need=0);
	bool getSymbol();
	void getIdOrKeyword();
};

#endif
