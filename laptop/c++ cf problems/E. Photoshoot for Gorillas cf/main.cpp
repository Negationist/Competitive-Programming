#include <bits/stdc++.h>

using namespace std;

void solve(){
    priority_queue<int> monkHeap;
    priority_queue<int> jungHeap;
    int n,m,k;
    cin >> n >> m >> k;
    int sC = ((n+1)/2)*((m+1)/2);
    int most = min(k*k,sC);
    int w;
    cin >> w;
    for (int i=0;i<w;i++){
        int a;
        cin >> a;
        monkHeap.push(a);
    }
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int h = min(i+1,n-i);
            int v = min(j+1,m-j);
            int current = min(most,h*v);
            jungHeap.push(current);
        }
    }
    long long sum = 0;
    for(int i=0;i<w;i++){
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
