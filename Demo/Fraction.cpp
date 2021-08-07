#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Fraction{
    int up,down;
    Fraction(int _up,int _down){
        up = _up;
        down = _down;
    }
    Fraction(){}
};

int gcd(int x,int y){
    if (y == 0)
    {
        return x;
    }else{
        return gcd(y,x%y);
    }
}

Fraction reduction(Fraction result){
    if (result.down<0)
    {
        result.up = -result.up;
        result.down = -result.down;
    }else if (result.up == 0)
    {
        result.down = 1;
    }else{
        int d = gcd(result.up,result.down);
        result.up = result.up/d;
        result.down = result.down/d;
    }
    return result;
}

Fraction add(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up*f2.down+f2.up*f1.down;
    result.down = f1.down*f2.down;
    return reduction(result);
}

Fraction sub(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up*f2.down - f1.down*f2.up;
    result.down = f1.down*f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up*f2.up;
    result.down = f1.down*f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up*f2.down;
    result.down = f1.down*f2.up;
    return reduction(result);
}

void show(Fraction r){
    r = reduction(r);
    if (r.down == 1)
    {
        printf("%lld\n",r.up);
    }else if (abs(r.up)>r.down)
    {
        printf("%d %d/%d\n",r.up/r.down,abs(r.up)%r.down,r.down);
    }else{
        printf("%d/%d\n",r.up,r.down);
    }
}

int main(){
    Fraction f1,f2,result;
    f1 = Fraction(-8,3);
    f2 = Fraction(1,2);
    result = multi(f1,f2);
    show(result);
    printf("%d %d",result.up,result.down);
    system("pause");
    return 0;
}