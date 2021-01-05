#ifndef LEXIAL_H
#define LEXIAL_H

#include<global.h>
#include<scanner.h>
#include<token.h>

enum LexError {
	STR_NO_R_QUTION, // String without closing quote
	NUM_BIN_TYPE, // Binary numbers have no physical data
	NUM_HEX_TYPE, // Hex numbers have no physical data
	CHAR_NO_R_QUTION, // Char without closing quote
	CHAR_NO_DATA, // Char have no physical data
	COMMENT_NO_END, // Multi-line comments did not end normally
	TOKEN_NO_EXIST // token does not exists
};

static const char *lexErrorTable[]={
	"String without closing quote",
	"Binary numbers have no physical data",
	"Hex numbers have no physical data",
	"Char without closing quote",
	"Char have no physical data",
	"Multi-line comments did not end normally",
	"token does not exists"
};

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
	void lexError(int code);
};

#define LEXERROR(code) Lexial::lexError(code)

#endif
