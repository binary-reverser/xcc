#ifndef SCANNER_H
#define SCANNER_H
#include<stdio.h>

class Scanner{
private:
	FILE* file;
	int linenumber;
	int charPos;
public:
	Scanner(FILE* _file);
	~Scanner();
	static char getChar();
};


#endif
