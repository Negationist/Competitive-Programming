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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n==2){
        cout << stoi(s) << "\n";
    }
    else if(n==3){
        if(s[0]=='0' || s[2]=='0'){
            cout << 0 << "\n";
        }
        else{
            int ans1 = (s[0] - '0') + (s[1]-'0')*10 + (s[2]-'0');
            int ans2 = (s[2] - '0') + (s[0]-'0')*10 + (s[1]-'0');
            int ans3 = (s[0] - '0') * ((s[1]-'0')*10 + (s[2]-'0'));
            int ans4 = (s[2] - '0') * ((s[0]-'0')*10 + (s[1]-'0'));
            ans1 = min(ans1, ans2);
            ans3 = min(ans3, ans4);
            cout << min(ans1, ans3) << "\n";
        }
    } else{
        int ansR = LLONG_MAX;
        int ans = 0;
        set<int> minD;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cout << 0 << "\n";
                return;
            }
            ans+=(s[i]-'0');
            if(s[i]-'0'==1) ans--;
            if(i==n-1){
                continue;
            }
            minD.insert((long long)(s[i]-'0')*10+(s[i+1]-'0'));
        }
            int chosen = *minD.begin();
            for(int i=0;;i++){
                int cur = ans;
                if(chosen==100) break;
                if(minD.find(chosen)==minD.end()){
                    chosen++;
                    continue;
                }
                cur+=(chosen);
                cur-=(chosen/10);
                cur-=(chosen%10);
                cur+=((chosen/10)==1);
                cur+=((chosen%10)==1);
                ansR = min(ansR,cur);
                chosen++;
            }
            cout << ansR << "\n";
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
