#include<scanner.h>
#include<iostream>

using namespace std;

bool Scanner::getChar(CHAR_INFO& charInfo){
	bool isEnd = false;
	
	if(charPos == readLen-1){
		readLen = fread(buffer, 1, MAX_LINE_LEN, file);
		if(readLen == 0) {
			isEnd = true;
			goto end;
		}
		charPos = -1;
	}

	charPos++;
	charInfo.ch = buffer[charPos];
	
	if(newLine){
		colNumber = 0;
		newLine = false;
	} else
		colNumber++;

	if(charInfo.ch == '\n'){
		lineNumber++;
		newLine = true;
	}
	
	charInfo.lineNumber = lineNumber;
	charInfo.colNumber = colNumber;
end:
	return isEnd;
}

Scanner::Scanner(FILE* _file){
	file = _file;
	fseek(file, 0, SEEK_SET);
	lineNumber = 0;
	colNumber = 0;
	newLine = false;
	charPos = -1;
	readLen = 0;
}

Scanner::~Scanner(){
	file = nullptr;
}
