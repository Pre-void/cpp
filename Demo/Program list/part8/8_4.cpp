#include<iostream>
#include<stdlib.h>
using namespace std;

void swapr(int &,int &);
void swapp(int *,int *);
void swapv(int , int);

int main(){
    int value1 = 1;
    int value2 = 2;
    cout << "swapr" << endl;
    swapr(value1,value2);
    cout << value1 << value2 << endl;

    cout << "swapp" << endl;
    swapp(&value1,&value2);
    cout << value1 << value2 << endl;

    cout << "swapv" << endl;
    swapv(value1,value2);
    cout << value1 << value2 << endl;

    system("pause");
    return 0;

}

void swapr(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b =temp;
}

void swapp(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swapv(int a,int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}