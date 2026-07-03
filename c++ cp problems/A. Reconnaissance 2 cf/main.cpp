#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    int e[t];
    FOR(i,t){
        cin >> e[i];
    }
    int minDiff = abs(e[t-1]-e[0]);
    int s1=1;
    int s2=t;
    FOR(i,t-1){
        if(minDiff > abs(e[i]-e[i+1])) {
                minDiff = abs(e[i]-e[i+1]);
                s1 = i+1;
                s2 = i+2;
        }
    }
    cout << s1 << " " << s2;
    return 0;
}
