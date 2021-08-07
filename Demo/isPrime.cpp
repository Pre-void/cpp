#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPrime(int n){
    if (n<=1)
    {
        return false;
    }
    int sqr = (int)sqrt(1.0*n);
    for (int i = 2; i <= sqr; i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
    
    
}

int main(){
    int PrimeList[101];
    for (int i = 1; i <= 100; i++)
    {
        if (isPrime(i))
        {
            PrimeList[i] = 1;
        }
        
    }
    
    system("pause");
    return 0;
}