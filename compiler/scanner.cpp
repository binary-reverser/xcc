#include<scanner.h>

char Scanner::getChar(){
	
	//todo:
	return ' ';
}

Scanner::Scanner(FILE* _file){
	file = _file;
	linenumber = 0;
}

Scanner::~Scanner(){
	file = nullptr;
}
