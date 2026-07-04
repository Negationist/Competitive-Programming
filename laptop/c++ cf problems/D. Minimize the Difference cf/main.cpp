#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            int sum = a[i], cnt = 1;
            while(s.size() && s.top().first >= sum/cnt){
            sum+= s.top().first * s.top().second;
            cnt+= s.top().second;
            s.pop();
        }
        s.push({sum/cnt , cnt - sum%cnt});
        if(sum%cnt != 0){
            s.push({sum/cnt + 1, sum%cnt});
        }
        }
        int mx = s.top().first;
        while(s.size()>1){
            s.pop();
        }
        cout << mx - s.top().first << "\n";
    }
    return 0;
}
