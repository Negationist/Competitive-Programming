#include <bits/stdc++.h>

using namespace std;

void solve(){
    priority_queue<long long> monkHeap;
    priority_queue<long long> jungHeap;
    long long n,m,k;
    cin >> n >> m >> k;
    long long w;
    cin >> w;
    for (long long i=0;i<w;i++){
        long long a;
        cin >> a;
        monkHeap.push(a);
    }
    for (long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            long long ubx = (n-k+1);
            long long uby = (m-k+1);
            long long x = min({i+1,n-i,ubx,k});
            long long y = min({j+1,m-j,uby,k});
            long long current = x*y;
            jungHeap.push(current);
        }
    }
    long long sum = 0;
    for(long long i=0;i<w;i++){
        sum+=monkHeap.top()*jungHeap.top();
        monkHeap.pop();
        jungHeap.pop();
    }
    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


