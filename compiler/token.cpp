#include<token.h>

using namespace std;

Id::Id(string n):Token(ID) {
	name = n;
}

string Id::toString() {
	return name;
}

Num::Num(int v):Token(NUM) {
	val = v;
}

string Num::toString() {
	return to_string(val);
}

Char::Char(char c):Token(CH) {
	ch = c;
}

string Char::toString() {
	string s("");
	s.push_back(ch);
	return s;
}

Str::Str(string s):Token(STR) {
	str = s;
}

string Str::toString() {
	return str;
}

Keywords::Keywords() {
	keywords["int"] = KW_INT;
	keywords["char"] = KW_CHAR;
	keywords["void"] = KW_VOID;
	keywords["extern"] = KW_EXTERN;
	keywords["if"] = KW_IF;
	keywords["else"] = KW_ELSE;
	keywords["switch"] = KW_SWITCH;
	keywords["case"] = KW_CASE;
	keywords["default"] = KW_DEFAULT;
	keywords["while"] = KW_WHILE;
	keywords["do"] = KW_DO;
	keywords["for"] = KW_FOR;
	keywords["break"] = KW_BREAK;
	keywords["continue"] = KW_CONTINUE;
	keywords["return"] = KW_RETURN;
}

TAG Keywords::getTag(string name) {
	return keywords.find(name)!=keywords.end()?keywords[name]:ID;
}
