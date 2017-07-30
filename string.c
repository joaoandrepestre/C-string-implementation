#include <stdlib.h>
#include <stdio.h>
#include "string.h"

//Struct definition
struct str{

	char stringElement;
	struct str* nextElement;
};


//Constructor and Destructor
string* createString(char* initialString, int initialStringSize)
{

	if(initialStringSize == 0)
		return NULL;
	
	string* str = (string*) malloc(sizeof(struct str));
	str->stringElement = initialString[initialStringSize-1];
	str->nextElement = createString(initialString,initialStringSize-1);
	
	return str;
}

int destroyString(string* str)
{
	if(str == NULL)
		return 0;

	if(str->nextElement == NULL){
		free(str);
		return 1;
	}

	destroyString(str->nextElement);
	free(str);
	return 1;
}


//Get functions
int stringSize(string* str)
{
	if(str == NULL)
		return 0;

	int ret;

	ret = 1 + stringSize(str->nextElement);

	return ret;
}

char getCharAt(string* str, int index)
{
	if(index<0 || index>=stringSize(str)){
		printf("String index out of bounds.\n");
		return '\0';
	}

	if(index == stringSize(str)-1)
		return str->stringElement;

	char ret;

	ret = getCharAt(str->nextElement, index);

	return ret;
}

char* getFullString(string* str)
{
	int size = stringSize(str);
	char* ret = (char*) malloc(sizeof(char)*(size+1));
	string* tmp = str;

	ret[size] = '\0';
	size--;
	while(size >= 0){
		ret[size] = tmp->stringElement;
		tmp = tmp->nextElement;
		size--;
	}
	
	return ret;
}

string* stringCopy(string* str, int startPoint, int endPoint)
{
	string* retStr = createString(NULL,0);
	char tmp;

	int i = startPoint;
	while(i<endPoint){
		tmp = getCharAt(str,i);
		retStr = addChar(retStr,tmp);
		i++;
	}

	return retStr;
}


//Set functions
int setCharAt(string* str, int index, char newChar)
{
	int size = stringSize(str);
	if(index<0 || index>=size)
		return 0;
	
	int tmp = size - index - 1;

	int i = 0;
	while(i<tmp){
		str = str->nextElement;
		i++;
	}
	str->stringElement = newChar;

	return 1;
}

//Add functions
string* addChar(string* str, char newChar)
{
	string* newStr = (string*) malloc(sizeof(struct str));
	
	if(newStr == NULL || newChar == '\0')
		return NULL;
	
	newStr->stringElement = newChar;
	newStr->nextElement = str;

	return newStr;
}

string* concatenateStrings_s(string* str, string* newString)
{
	int size = stringSize(newString);
	char tmp;
	string* ret = str;
	
	int i = 0;
	while(i<size){
		tmp = getCharAt(newString,i);
		ret = addChar(ret,tmp);
		i++;
	}

	return ret;
}

string* concatenateStrings_c(string* str, char* newString)
{
	char tmp = newString[0];
	string* ret = str;

	int i = 1;
	while(tmp != '\0'){
		ret = addChar(ret,tmp);
		tmp = newString[i];
		i++;
	}

	return ret;
}


//Remove functions
string* removeCharAt(string* str, int index)
{
	if(index<0 || index>=stringSize(str)){
		printf("String index out of bounds\n");
		return NULL;
	}

	int size = stringSize(str);
	char tmp;
	string* retStr = createString(NULL,0);

	int i = 0;
	while(i<size){
		if(i != index){
			tmp = getCharAt(str,i);
			retStr = addChar(retStr,tmp);
		}
		i++;
	}

	return retStr;
}

string* removeChar(string* str, char c)
{
	int size = stringSize(str);
	int removed = 0;
	char tmp;
	string* retStr = createString(NULL,0);

	int i = 0;
	while(i<size){
		if(tmp == c && !removed){
			removed = 1;
		}
		tmp = getCharAt(str,i);
		if(tmp != c || removed){
			retStr = addChar(retStr,tmp);
		}
		i++;
	}

	return retStr;
}


//Compare functions
int stringEquals(string* str1, string* str2)
{
	if(str1 == NULL && str2 == NULL)
		return 1;

	if(str1->stringElement != str2->stringElement)
		return 0;

	return stringEquals(str1->nextElement, str2->nextElement);
}

int stringCompare(string* str1, string* str2)
{
	char c1, c2;
	c1 = getCharAt(str1,stringSize(str1)-1);
	c2 = getCharAt(str2,stringSize(str2)-1);

	if(c1 < c2)
		return 1;

	return stringCompare(str1->nextElement,str2->nextElement);
}

string* stringMin(string* str1, string* str2)
{
	if(stringCompare(str1,str2))
		return str1;

	return str2;
}

string* stringMax(string* str1, string* str2)
{
	if(stringCompare(str1,str2))
		return str2;

	return str1;
}


//Print functions
int printString(string* str)
{
	if(str == NULL)
		return 0;

	if(str->nextElement == NULL){
		printf("%c",str->stringElement);
		return 1;
	}

	printString(str->nextElement);
	printf("%c",str->stringElement);
	return 1;
}