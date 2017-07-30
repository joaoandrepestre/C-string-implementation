//Type definition
typedef struct str string;
//defines the type 'string' as the struct 'str' in the source file 'string.c'


//Constructor and Destructor
string* createString(char* initialString, int initialStringSize);
//creates a new string based on the 'initialString' char pointer and on its size and returns a pointer to it

int destroyString(string* str);
//destructor of the structure, frees the memory


//Get functions
int stringSize(string* str);
//returns the size of the string

char getCharAt(string* str, int index);
//returns char at given index in the string

char* getFullString(string* str);
//returns the string in its char pointer format

string* stringCopy(string* str, int startPoint, int endPoint);
//returns a copy of 'str' from the index startPoint to the index endPoint


//Set functions
int setCharAt(string* str, int index, char newChar);
//sets the char at the given index to newChar


//Add functions
string* addChar(string* str, char newChar);
//adds the 'newChar' to the end of the string

string* concatenateStrings_s(string* str, string* newString);
//concatenates the 'newString' at the end of the string

string* concatenateStrings_c(string* str, char* newString);
//concatenates the 'newString' at the end of the string


//Remove functions
string* removeCharAt(string* str, int index);
//removes char at given index in the string

string* removeChar(string* str, char c);
//removes the first char c that appears in the string, if c not in the string, returns the original string


//Compare functions
int stringEquals(string* str1, string* str2);
//returns 1 if the all the chars in the strings are equal, 0 otherwise

int stringCompare(string* str1, string* str2);
//returns 1 if str1 is alphabetically before str2, 0 otherwise

string* stringMin(string* str1, string* str2);
//returns the string that comes alphabetically earlier

string* stringMax(string* str1, string* str2);
//returns the string tha comes alphabetically later


//Print functions
int printString(string* str);
//prints the string on the screen, does not create a new line