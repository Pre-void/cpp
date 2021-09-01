#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

string version1(const string & s1,const string & s2);
const string & version2(string & s1,const string &s2);
const string & version3(string & s1,const string &s2);

int main(){
    string input;
    string copy;
    string result;

    cout << "Enter: " << endl;
    getline(cin,input);
    copy = input;
    cout << "Your Enter" << input << endl;
    result = version1(input,"###");
    cout << "Enhanced: " << result << endl;
    cout << "Orginal: " << input << endl;

    result = version2(input,"###");
    cout << "Enhanced: " << result << endl;
    cout << "Orginal: " << input << endl;

    input = copy;
    result = version3(input,"@@@");
    cout << "Enhanced: " << result << endl;
    cout << "Orginal: " << input << endl;

    system("pause");
    return 0;
}

string version1(const string & s1,const string & s2){
    string temp;
    temp = s2+s1+s2; 
    return temp;
}

const string & version2(string & s1,const string & s2){
    s1 = s2 + s1 + s2;
    return s1;
}

const string & version3(string & s1,const string & s2){
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}