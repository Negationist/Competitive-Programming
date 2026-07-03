#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void stringxor(string &a, string &b){
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            a[i] = '1';
        } else{
            a[i] = '0';
        }
    }
}

bool stringcompare(string a, string b){
    bool bigger = true;
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i]=='1' && b[i]=='0'){
            break;
        } else if(a[i]=='0' && b[i]=='1'){
            bigger = false;
            break;
        }
    }
    return bigger;
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    cout << 1 << " " << n << " ";
    pii ans;
    bool done = true;
    int first;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            done = false;
            first = i;
            break;
        }
    }
    if(done){
        cout << "1 1\n";
    } else{
        int num = n-first;
        string best;
        while(best.size()<n){
            best.pb('0');
        }
        auto null = best;
        for(int i=0;i+num-1<n-1;i++){
            string test = null.substr(0,n-num)+s.substr(i,num);
            stringxor(test,s);
            if(stringcompare(test,best)){
                best = test;
                ans.ff = i;
                ans.ss = i+num-1;
            }
        }
        cout << ans.ff+1 << " " << ans.ss+1 << "\n";
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
