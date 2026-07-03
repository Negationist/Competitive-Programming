#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;
using ll = long long;
using ld = long double;
void solve(){
    for(int i=0;i<2;i++){int z; cin >> z;}
    string a,b;
    cin >> a >> b;
    vector<pair<int,int>> b1, b2;
    int cnt = 1;
    for(int i=1;i<a.size();i++){
        if(a[i]==a[i-1]){
            ++cnt;
        } else{
            b1.pb({a[i-1]-'0',cnt});
            cnt = 1;
        }
    }
    b1.pb({a.back()-'0',cnt});
    cnt = 1;
    for(int i=1;i<b.size();i++){
        if(b[i]==b[i-1]){
            ++cnt;
        } else{
            b2.pb({b[i-1]-'0',cnt});
            cnt = 1;
        }
    }
    b2.pb({b.back()-'0',cnt});
    //deal with weird edge cases
    if(b2.size()==1){
        if(b2[0].ff == 1){
            if(b1.size()==1 && b1[0].ff==1 && b1[0].ss>=b2[0].ss){
                cout << "yes\n";
            } else{
                cout << "no\n";
            }
            return;
        }
    }
    if(b1.size()==1){
        if(b2.size()!=1){
            cout << "no\n";
        } else{
            if(b1[0].ss>=b2[0].ss  && b1[0].ff==b2[0].ff){
                cout << "yes\n";
            }  else{
                cout << "no\n";
            }
        }
        return;
    }
    //ok they are both sizeable
    int l1 = 0, r1 = b1.size()-1, l2 = 0, r2 = b2.size()-1;
    if(b2[0].ff==1){
        if(b1[0].ff==1 && b1[0].ss>=b2[0].ss){
            l1++;
            l2++;
        } else{
            cout << "no\n";
            return;
        }
    }
    if(b2[r2].ff==1){
        if(b1[r1].ff==1 && b1[r1].ss>=b2[r2].ss){
            r1--;
            r2--;
        } else{
            cout << "no\n";
            return;
        }
    }
    for(int i=l2;i<=r2;i++){
        if(b2[i].ff==0){
            int k = b2[i].ss;
            while(k>0 && l1<=r1){
                if(b1[l1].ff==0){
                    k-=b1[l1].ss;
                }
                l1++;
            }
            if(k>0){
                cout << "no\n";
                return;
            }
        } else{
            bool flag = false;
            while(l1<=r1){
                if(b1[l1].ff==1 && b1[l1].ss >= b2[i].ss){
                    flag = true;
                    l1++;
                    break;
                }
                l1++;
            }
            if(!flag){
                cout << "no\n";
                return;
            }
        }
    }
    cout << "yes\n";
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
