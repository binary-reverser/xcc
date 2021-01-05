#include<scanner.h>
#include<iostream>

using namespace std;

char Scanner::getChar(){
	char ch = ' ';

	if(_isEnd) {
		ch = -1;
		goto end;
	}

	if(charPos == readLen-1){
		readLen = fread(buffer, 1, MAX_LINE_LEN, file);
		if(readLen == 0) {
			_isEnd = true;
			ch = -1;
			goto end;
		}
		charPos = -1;
	}

	charPos++;
	ch = buffer[charPos];
	
	if(newLine){
		colNumber = 0;
		newLine = false;
	} else
		colNumber++;

	if(ch == '\n'){
		lineNumber++;
		newLine = true;
	}
	
end:
	return ch;
}

void Scanner::showCurrent(){
	cout<<lineNumber<<"-"<<colNumber<<":\""<<buffer<<"\":at " <<charPos<<endl;
}

Scanner::Scanner(FILE* _file){
	file = _file;
	fseek(file, 0, SEEK_SET);
	lineNumber = 1;
	colNumber = 0;
	newLine = false;
	_isEnd = false;
	charPos = -1;
	readLen = 0;
}

Scanner::~Scanner(){
	file = nullptr;
}

