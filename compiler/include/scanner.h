#ifndef SCANNER_H
#define SCANNER_H
#include<stdio.h>

#define MAX_LINE_LEN 100 // Maximum number of characters in a line of code

struct CHAR_INFO {
	char ch;	// the current char
	size_t lineNumber;
	size_t colNumber;
};

class Scanner{
private:
	FILE* file;
	size_t lineNumber;
	size_t colNumber;
	size_t charPos;
	bool newLine;
	char buffer[MAX_LINE_LEN];
	size_t readLen; // the number of charactors currently read into the buffer

public:
	Scanner(FILE* _file);
	~Scanner();
	bool getChar(CHAR_INFO&);
};


#endif
