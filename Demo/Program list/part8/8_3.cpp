#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    // int rats = 101;
    // int &rodents = rats;
    // cout << rats << "  " << rodents << endl;
    // cout << &rats << "  "  << &rodents << endl;
    // int bunnies = 50;
    // rodents  = bunnies;
    // cout << "bunnies " << bunnies << endl;
    // cout << "rats "  <<  rats << endl;
    // cout << "rodents " << rodents << endl;
    // cout << "&bunnies " << &bunnies << endl;
    // cout << "&rodents " << &rodents << endl;
    // cout << "&rats " << &rats << endl;

    int rats = 101;
    int *pt = &rats;
    int &rodents = *pt;
    cout << rats << *pt << rodents << endl;
    cout << &rats << pt << &rodents <<endl;
    int bunnies = 50;
    pt = &bunnies;
    cout << rats << rodents << *pt << endl;
    cout << &rats << pt << &rodents << &bunnies << endl; 

    system("pause");
    return 0;

}