#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    long long mn = LLONG_MAX;
    long long mx = 0;
    cin >> n;
    int maxDiff = 0;
    vector<int> e(n);
    for (int i=0; i<n;i++){
        cin >> e[i];
        mn = min(mn,(long long)e[i]);
        mx = max(mx,(long long)e[i]);
    }
    long long t1 = 0, t2 = 0;
    for (int i=0; i<n;i++){
        t1+=(e[i]==mn);
        t2+=(e[i]==mx);

    }
    cout << mx - mn << " ";
    if (mn==mx){
        cout << n*(n-1)/2;
    }
    else{
        cout << t1*t2;
    }
    return 0;
}
