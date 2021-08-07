#include<iostream>
#include<stdlib.h>
using namespace std;

int fill_array(double ar[],int);
int main(){
    double ar[10];
    fill_array(ar,5);
    system("pause");
    return 0;
}

int fill_array(double ar[],int limit){
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value # " << (i+1) << ":";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get()!='\n')
            {
                continue;
            }
            cout << "Bad input;input process terminated.\n";
            break;
        }else if (temp<0)
        {
            break;
        }
        ar[i] = temp;
    }
    return i;
}