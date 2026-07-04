#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void solve(){
    int n,m,q;
    cin >> n >> m >> q;
    int b[m+1];
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    b[m] = n+1;
    sort(b,b+m+1);
    int query[q],queryCopy[q];
    for(int i=0;i<q;i++){
        cin >> query[i];
        queryCopy[i] = query[i];
    }
    sort(query, query+q);
    int index = 0;
    unordered_map<int,int> answers;
    for(int i=0;i<q;i++){
        while(query[i]>b[index] && index<=m){
            index++;
        }
        if(index==0){
            int ans = b[0]-1;
            answers[query[i]] = ans;
        } else if (index==m){
            answers[query[i]] = n-b[m-1];
        } else{
            int sum = b[index]+b[index-1];
            int pos1,pos2;
            if(sum%2==0){
                pos1 = pos2 = sum/2;
            } else{
                pos1 = sum/2;
                pos2 = pos1+1;
            }
            int dis1 = b[index] - pos2;
            int dis2 = pos1 - b[index-1];
            answers[query[i]] = min(dis1,dis2);
        }
    }
    for(int i=0;i<q;i++){
        cout << answers[queryCopy[i]] << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
