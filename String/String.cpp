// 2013.10.30
// 12330443 zhuozhaojin 

#include "String.h"
#include <vector> 
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

String::String(char *string2) {
    
    length = strlen(string2);
    entries = new char[length + 1];
    strcpy(entries, string2);
}

String::String() {
    length = 0;
    entries = NULL;
}
String::~String() {
    if (entries != NULL)
	delete []entries;
}
String::String(const String &origin) {
  
    length = strlen(origin.entries);
    entries = new char[length + 1];
    strcpy(entries, origin.entries);
}
char String::charAt(int index) {

   if (index < 0)
       index = length + index;

   if (index <= length)
       return entries[index];
}

String String::slice(int start, int end) {
    char *temp;
    int k = 0;

    if (end < 0)
	end = length + end;

    temp = new char[end - start + 2] ;

    if (start <= end) {
	for (int i = start; i < end; i++)
	    temp[k++] = this->entries[i];
    }
    String string(temp);

    return string;
}

String String::substr(int start, int length1) {

    char *temp;
    int k = 0;

    if (length1 < 0) 
	length1 = length - start;

    temp = new char[length1 + 1];
    for (int i = start; i < length1; i++)
	temp[k] = this->entries[i];

    String string(temp);
    delete []temp;

    return string;
}

int String::lastIndexOf(const char *str, int startindex) {
    int flag = -1;
    char *ptr;

    ptr = strstr((char *)entries, str);
    if (ptr != NULL) {
	flag = ptr - entries;
    }
    
    return flag;
}
int String::lastIndexOf(String str, int startindex) {
    int flag = -1;
    char *ptr;

    ptr = strstr((char *)entries, str.c_str());
    if (ptr != NULL) {
	flag = ptr - entries;
    }
    
    return flag;
}
String String::concat(String string2) {
 
    char * copy = new char[length + string2.length + 1];
    strcpy(copy, entries);
    strcat(copy, string2.c_str());
    
    String string(copy);

    return string;
}

String String::concat(const char *string2) {

    char *copy;
    int len;
    len = strlen(string2);
    copy = new char[length + len + 1];
    strcpy(copy, entries);
    strcat(copy, string2);

    String string(copy);

    return string;
}

vector<String> String::split(char separator) {

    vector<String> temp;
    char *ptr;
    char *copy;
    char *separ;

    char a[] = " ";
    separ = a;
    ptr = strtok((char *)entries, separ);
    while (ptr != NULL) {
	strcpy(copy, ptr);
	String string(copy);
	temp.push_back(string);
	ptr = strtok(NULL, separ);
    } 
    return temp;
}

char* String::c_str() {

    return (char *)entries;
}
