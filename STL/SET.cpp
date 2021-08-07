#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;
int main(){
    set<int> st;
    for (int i = 0; i < 5; i++)
    {
        st.insert(i);
    }
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        printf("%d ",*it);
    }
    
    system("pause");
    return 0;
    
}