#include<iostream>
#include<stdlib.h>
using namespace std;

double besty(int);
double pam(int);
void estimate(int,double (*pf)(int));

int main(){
    int code;
    cout << "How many lines of code do you need?" << endl;
    cin  >> code;
    cout << "Betsy" << endl;
    estimate(code,besty);
    cout << "Pam" << endl;
    estimate(code,pam);

    system("pause");
    return 0;
}

double besty(int lns){
    return 0.05*lns;
}

double pam(int lns){
    return 0.03*lns+0.0004*lns*lns;
}

void estimate(int lines,double (*pf)(int)){
    cout << lines << "lines will take";
    cout << (*pf)(lines) << "hour(s)\n";
}