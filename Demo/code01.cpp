#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){

    int ori = 6;
    int* update = &ori;
    cout << *update << endl;
    cout << update << endl;
    cout << &update << endl;
    cout << *&update << endl;
    system("pause");
    return 0;
}
