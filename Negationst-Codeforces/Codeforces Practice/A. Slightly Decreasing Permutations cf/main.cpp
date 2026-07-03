#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int arr1[a];
    FOR(i,a){
        arr1[i]=1+i;
    }
    int arr2[a];
    FOR(i,a){
        arr2[a-1-i]=arr1[i];
    }

    FOR (i,a-b-1){
        cout << arr1[i] << " ";
    }
    FOR (i,b+1){
        cout << arr2[i] << " ";
    }
    return 0;
}
