#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

void solve(){
    priority_queue<long long> oddHeap;
    priority_queue<long long, vector<long long>, greater<long long>> evenHeap;
    int n;
    cin >> n;
    FOR(i,n){
        long long a;
        cin >> a;
        if (a%2==0){
            evenHeap.push(a);
        } else{
            oddHeap.push(a);
        }
    }
    if(evenHeap.size()==0 || oddHeap.size()==0){
        cout << 0 << endl;
        return;
    }
    int evens = evenHeap.size();
    long long z = oddHeap.top();
    while(evenHeap.size()!=0){
        if(evenHeap.top()>z){
            cout << evens + 1 << endl;
            return;
        } else z+=evenHeap.top();
           evenHeap.pop();
    }
    cout << evens << endl;
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
