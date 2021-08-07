#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    int rats = 101;
    int &rodents = rats;

    cout << "rats: " << rats << "rodents: "<< rodents << endl;
    rats++;
    cout << "rats: " << rats << "rodents: "<< rodents << endl;
    rodents++;
    cout << "rats: " << rats << "rodents: "<< rodents << endl;
    cout << "&rats = " << &rats << endl;
    cout << "&rodents = " << &rodents <<endl;

    system("pause");
    return 0;
}