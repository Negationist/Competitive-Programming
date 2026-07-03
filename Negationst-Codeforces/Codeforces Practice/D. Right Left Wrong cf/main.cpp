#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    FOR(i,n){
        cin >> arr[i];
    }
    string x;
    cin >> x;

    priority_queue<int> RHeap;
    priority_queue<int, vector<int>, greater<int>> LHeap;


    FOR(i,n){
        if (x[i]=='L'){
            LHeap.push(i);
        } else{
            RHeap.push(i);
        }
    }
    while(!RHeap.empty() && !LHeap.empty()){
        if (RHeap.top()<=LHeap.top()){
            break;
        }
        int l = LHeap.top();
        int r = RHeap.top();
        for(int i=l;i<=r;i++){
            sum+=arr[i];
        }
        RHeap.pop();
        LHeap.pop();
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
