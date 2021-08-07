#include <iostream>
#include <stdlib.h>
using namespace std;

//最垃圾
// int mySqrt(int x) {
//     if (x<0) return -1;
//     else if (x==0) return 0;
//     else if (x<4) return 1;
//     else{
//         for (int i = 2; i <= x/2; i++)
//         {
//             if ((long long)(i+1)*(i+1)>x) return i;
//         }
//         return -1;
//     }
// }

//二分法逼近
// int mySqrt(int x) {
//     double left = 0,right = x,result = -1;
//     if (right==0) return 0;
//     if (right==1) return 1;

//     while (right-left>1e-5)
//     {
//         result = left + (right-left)/2;
//         if (result*result>x)
//         {
//             right = result;
//         }else{
//             left = result;
//         }
//     }
//    if ((double)((int)result+1)*((int)result+1)==x)
//    {
//        return (int)result +1;
//    }else{
//        return (int)result;
//    }
// }

//牛顿迭代
int mySqrt(int x) {
    if (x==0)
    {
        return 0;
    }
    double x0 = x,C = x,temp = (x0+C/x0)/2;
    while (x0-temp>1e-5)
    {
        x0 = temp;
        temp = (temp+C/temp)/2;
    }
    return (int)x0;
}

int main(){
    int x;
    cin >> x;
    int result = mySqrt(x);
    cout << result << endl;
    system("pause");
    return 0;
}

