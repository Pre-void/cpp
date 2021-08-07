#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){
    /**
    string str = "abcd";
    for (int i = 0; i < str.length(); i++)
    {
        printf("%c ",str[i]);
    }**/

    /**
    string str;
    cin >> str;
    cout << str;**/
    /**
    string str;
    cin >> str;
    cout << str;
    for (string::iterator it = str.begin(); it != str.end(); it++)
    {
        printf("%c ",*it);
    }**/
    unsigned int max = 4294967295;
    if (string::npos==-1)
    {
        printf("-1 is true\n");
    }
    if (string::npos==max);
    {
        printf("%u is also true",max);
    }
    
    system("pause");
    return 0;
}