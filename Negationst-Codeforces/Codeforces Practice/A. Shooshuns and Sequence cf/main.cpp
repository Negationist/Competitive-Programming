#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n,k,index;
    bool distinct = false;
    cin >> n >> k;
    int e[n];
    FOR(i,n){
        cin >> e[i];
        if(e[i]!=e[i-1]&&i>0){
            distinct = true;
        }
    }
    if(!distinct || n==1){
        cout << 0;
        return 0;
    }
    int a = e[k-1];
    for(int i=k;i<n;i++){
        if (a != e[i]){
            cout << -1;
            return 0;
        }
    }

    for(int i=k-2; i>=0;i--){
        if(e[i] != a){
            index = i;
            break;
        }
    }
    cout << index+1;

    return 0;
}
