#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

struct free_throws
{
    string name;
    int made;
    int attempts;
    float percent;
};

void display(const free_throws &ft);
void set_pc(free_throws &ft);
free_throws & accumulate(free_throws &target,const free_throws &source);

int main(){
    free_throws one = {"Ifelsa Branch",13,14};
    free_throws two = {"Andor Knott",10,16};

    system("pause");
    return 0;
}