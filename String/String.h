// 2013.10.30
// 12330443 zhuozhaojin 

#ifndef STRING_H
#define STRING_H

#include <vector>
#include <cstring>
using namespace std;

class String {
public:
	String();
	String(char *string2);
	String(const String &origin);
	~String();
	char charAt(int index);
	String slice(int start, int end = -1);
	String substr(int start, int length = -1);
	int lastIndexOf(String str,  int startindex = -1);
	int lastIndexOf(const char *str, int startindex = -1);
	String concat(String string2);
	String concat(const char *string2);
	vector<String> split(char separator = ' ');
	char* c_str();

private:
	char *entries;
	int length;

};
#endif
