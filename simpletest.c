#include <stdio.h>
#include "string.h"

int main()
{
	string* str1; string* str2; string* str3; string* str4; string* str5;
	char* ch1; char* ch2; char* ch3; char* ch4; char* ch5;
	int s1, s2, tmp;

	//Constructor test
	printf("Constructor test:\n");
	str1 = createString("Hello", 5);
	str2 = createString(" world", 6);
	if(str1 != NULL && str2!=NULL)
		printf("Worked!\n\n");
	
	//Size test
	printf("Size test:\n");
	s1 = stringSize(str1);
	s2 = stringSize(str2);
	printf("Size1 \t Size2\n");
	printf("%d \t %d\n\n",s1,s2);

	//Get char test
	printf("Get char test:\n");
	int i;
	for(i=0;i<s2;i++){
		if(i<s1){
			char c1 = getCharAt(str1,i);
			printf("Char at s1 index %d: %c\n",i,c1);
		}
		char c2 = getCharAt(str2,i);
		printf("Char at s2 index %d: %c\n",i,c2);
	}
	printf("\n");
	
	//Get full string test
	printf("Get full string test:\n");
	ch1 = getFullString(str1);
	ch2 = getFullString(str2);
	printf("Char pointer of s1: %s\n", ch1);
	printf("Char pointer of s2: %s\n\n", ch2);

	//String copy test
	printf("String copy test:\n");
	str3 = stringCopy(str1,1,4);
	ch1 = getFullString(str1);
	ch3 = getFullString(str3);
	printf("After copy s1 is: %s\n",ch1);
	printf("After copy s3 is: %s\n\n",ch3);

	//Set char test
	printf("Set char test:\n");
	tmp = setCharAt(str3,0,'q');
	ch3 = getFullString(str3);
	printf("After setting s3 is: %s\n\n", ch3);

	//Add char test
	printf("Add char test:\n");
	str4 = addChar(str1,'!');
	ch1 = getFullString(str1);
	ch4 = getFullString(str4);
	printf("After adding the char s1 is: %s\n",ch1);
	printf("After adding the char s4 is: %s\n\n",ch4);

	//Remove char test
	printf("Remove char test:\n");
	str5 = removeCharAt(str4, s1);
	ch4 = getFullString(str4);
	ch5 = getFullString(str5);
	printf("After removing the char s4 is: %s\n", ch4);
	printf("After removing the char s5 is: %s\n", ch5);
	str5 = removeChar(str4, '!');
	ch4 = getFullString(str4);
	ch5 = getFullString(str5);
	printf("After removing the char s4 is: %s\n", ch4);
	printf("After removing the char s5 is: %s\n\n", ch5);

	//Concatenate test
	printf("Concatenate test:\n");
	str4 = concatenateStrings_s(str1,str2);
	ch4 = getFullString(str4);
	printf("After concatanation s4 is: %s\n", ch4);
	str4 = concatenateStrings_c(str4," arround");
	ch4 = getFullString(str4);
	printf("After concatanation s4 is: %s\n\n", ch4);

	//Comparison test
	printf("Comparison tests:\n");
	tmp = stringEquals(str1,str5);
	if(tmp){
		printf("str1 and str5 are equal\n");
	}
	else{
		printf("str1 and str5 are not equal\n");
	}
	tmp = stringCompare(str1,str2);
	if(tmp){
		printf("str1 comes alphabetically before str2\n");
	}
	else{
		printf("str2 comes alphabetically before str1\n");
	}
	str5 = stringMin(str1,str2);
	ch5 = getFullString(str5);
	printf("The first string is: %s\n", ch5);
	str5 = stringMax(str1,str2);
	ch5 = getFullString(str5);
	printf("The last string is: %s\n", ch5);
	printf("\n");
	
	//Print test
	printf("Print test:\n");
	tmp = printString(str1);
	printf("\n\n");
	
	//Destructor test
	printf("Destructor test:\n");
	if(tmp = destroyString(str1)){
		if(tmp = destroyString(str2)){
			if(tmp = destroyString(str3)){
				if(tmp = destroyString(str4)){
					tmp = destroyString(str5);
				}
			}
		}
	}
	if(tmp){
		printf("Worked!\n");
	}
	
	return !tmp;
}