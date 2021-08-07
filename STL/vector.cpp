#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
int main(){
    vector<int> vi;
    for (int i = 0; i < 5; i++)
    {
        vi.push_back(i);
    }
    
    vector<int>::iterator it = vi.begin();
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",*(it+i));
        printf("%d ",*(vi.begin()+i));
    }
    printf("\n");
    for (vector<int>::iterator it = vi.begin();it != vi.end();it++)
    {
        printf("%d ",*it);
    }
    

    system("pause");
    return 0;
}