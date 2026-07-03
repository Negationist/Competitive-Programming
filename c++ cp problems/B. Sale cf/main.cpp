#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int n,m;
    long long sum=0;
    cin >> n >> m;
    int e[n];
    FOR(i,n){
        cin >> e[i];
    }
    sort(e,e+n);
    for (int i=0;i<m;i++){
        if (e[i]>=0){
            break;
        }
        sum-=e[i];
    }

    cout << sum;
    return 0;
}
