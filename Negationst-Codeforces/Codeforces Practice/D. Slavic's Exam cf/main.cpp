#include <bits/stdc++.h>

#define FOR(i,m,n) for(int i=m;i<n;i++)

using namespace std;

void solve(){
        string s,t;
        cin >> s >> t;
        int p=0, n=s.size(), m=t.size();
        FOR(i,0,n){
                if (p<m){
                    if(s[i]==t[p]){
                            p++;
                    }
                    else if(s[i]=='?'){
                            s[i]=t[p++];
                    }
                } else if(s[i]=='?'){
                    s[i]='a';
                }
        }
        if (p==m){
            cout << "YES" << endl;
            cout<<s<<endl;
        } else{
            cout << "NO" << endl;
        }
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
