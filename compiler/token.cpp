#include<token.h>

using namespace std;

Token::Token(TAG t) {
	tag = t;
}

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
	to_string(val);
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

}

TAG Keywords::getTag(string name) {
	return keywords[name];
}
