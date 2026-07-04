#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << endln
#define each(a, x) for(auto &&a : x)

using namespace std;

void solve(){
    vector<string> a;
    for(int i=0;i<7;i++){
        string s;
        cin >> s;
        a.pb(s);
    }
    sort(a.begin(),a.end());
    int inc = 0;
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
            for(int k=j+1;k<7;k++){
                for(int l=k+1;l<7;l++){
                    ++inc;
                    cout << a[i] << ", " << a[j] << ", " << a[k] << ", " << a[l] << "\n";
                }
            }
        }
    }
    cout << "i printed " << inc << " things\n";
    /*for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<7;k++){
                for(int l=0;l<7;l++){
                    set<int> s;
                    s.insert(i);
                    s.insert(j);
                    s.insert(k);
                    s.insert(l);
                    if(s.size()==4){
                        cout << a[i] << ", " << a[j] << ", " << a[k] << ", " << a[l] << "\n";
                    }
                }
            }
        }
    }*/
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
