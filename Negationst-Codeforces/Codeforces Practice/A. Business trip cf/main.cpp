#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int k,c=0;
    cin >> k;
    if(k==0){
        cout << 0;
        return 0;
    }
    int e[12];
    FOR(i,12){
        cin >> e[i];
    }
    sort(e,e+12);
    FOR(i,12){
        k-=e[11-i];
        c++;
        if(k<=0){
            cout << c;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
