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

    system("pause");
    return 0;  
}