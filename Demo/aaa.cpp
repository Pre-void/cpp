#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    int a = 6;
    int b = a;
    cout << a << b <<endl;
    cout << &a << &b <<endl;
    a = 3;
    cout << a <<b << endl;
        cout << &a << &b <<endl;
    cout << "2021-09--01";
    system("pause");
    return 0;  
}