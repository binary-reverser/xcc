#ifndef TOKEN_H
#define TOKEN_H

#include<global.h>
#include<string>
#include<hash_map>
#include<cstdlib>

class Token {
public:
    TAG tag;
    Token(TAG t); 
	virtual ~Token() {};
    virtual std::string toString() {};
};

class Id:public Token {
public:
    std::string name;
    Id(std::string n); 
    std::string toString();
};

class Num:public Token {
public:
	int val;
	Num(int v);
	std::string toString();
};

class Char:public Token {
public:
	char ch;
	Char(char c);
	std::string toString();
};

class Str:public Token {
public:
	std::string str;
	Str(std::string s);
	std::string toString();
};

struct string_hash {
public:
	size_t operator()(const std::string& str) const {
		return __gnu_cxx::__stl_hash_string(str.c_str());
	}
};

class Keywords {
	__gnu_cxx::hash_map<std::string, TAG, string_hash> keywords;
public:
	Keywords();
	TAG getTag(std::string name);
};
#endif
