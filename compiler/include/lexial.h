#ifndef LEXIAL_H
#define LEXIAL_H

#include<global.h>
#include<scanner.h>

class Lexial {
private:
	Scanner* scanner;
public:
	Lexial(FILE* _file);
	~Lexial();
	TAG getSymbol();
};

#endif
