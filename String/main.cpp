#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "String.h"

using namespace std;

int main() {
    // charAt
    char a[] = "GINTAMA";
    String str0(a);
    printf("%c\n", str0.charAt(-2) );	// M
	
    // slice
    char b[] = "alibaba";
    String str1(b);
    printf("%s\n", str1.slice(3,5).c_str() ); // ba
	
    // substr
    char c[] = "apokemon";
    String str2(c);
    printf("%s\n", str2.substr(1).c_str() ); // pokemon
	
    // lastIndexOf
    char d[] = "bilibili";
    char e[] = "li";
    String str3(d);
    String sub(e);
    printf("%d\n", str3.lastIndexOf(sub) ); // 6
	
    // concat
    char f[] = "Running";
    String str4(f);
    printf("%s\n", str4.concat("Man").c_str() ); // RunningMan
	
    // split
    char g[] = "I Love You";
    String str5(g);
    vector<String> vec = str5.split();
    vector<String>::iterator iter = vec.begin();
	
    while (iter != vec.end()) {	// I.Love.You.
	printf("%s.", iter->c_str() );
        iter++;
    }
	
    return 0;
}
