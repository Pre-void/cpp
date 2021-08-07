#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
char* getname(){
    char temp[80];
    cout << "Enter last name :";
    cin >> temp;
    char* pn = new char[strlen(temp)+1];
    strcpy(pn,temp);
    return pn;
}
int main(){
    char* name;
    while (true)
    {
        name = getname();
        cout << (int *)name << endl;
        cout << &name << endl;
        delete [] name;
    }
    system("pause");
    return 0;  
}