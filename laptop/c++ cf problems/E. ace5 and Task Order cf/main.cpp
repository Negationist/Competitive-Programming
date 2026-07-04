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

char ask(int x){
    cout << "? " << x << "\n";
    cout.flush();
    char z;
    cin >> z;
    return z;
}

void solve(){
    int n;
    cin >> n;
    while(true){
        char temp = ask(1);
        if(temp=='=') break;
    }
    int lo = 0;
    for(int i=2;i<=n;i++){
        char z = ask(i);
        if(z=='<'){
            ++lo;
        }
        ask(1);
    }
    int x = 1+lo;
    vi ans(n+1);
    auto conquer = [&](auto self, int l, int r, vector<int> &pos)->void{
        if(l==r){
            ans[pos[0]] = l;
            return;
        }
        int _n = pos.size();
        int index;
        int mid = (l+r)/2;
        //cout << "looking for " << mid << "\n";
        //cout << "x is currently " << x << "\n";
        cout.flush();
        for(int i=0;i<_n;i++){
            bool flag = false;
            while(true){
                char z = ask(pos[i]);
                if(x>mid){
                    if(z=='<'){
                        --x;
                    } else if(z=='='){
                        break;
                    } else if(z=='>'){
                        ++x;
                        break;
                    }
                } else if(x<mid){
                    if(z=='>'){
                        ++x;
                    } else if(z=='='){
                        break;
                    } else if(z=='<'){
                        --x;
                        break;
                    }
                } else{
                    //cout << "im here\n";
                    cout.flush();
                    if(z=='>'){
                        ++x;
                        break;
                    } else if(z=='='){
                        flag = true;
                        break;
                    } else if(z=='<'){
                        --x;
                        break;
                    }
                }
            }
            if(flag){
                index = pos[i];
                break;
            }
        }
        vi higher,lower;
        for(int i=0;i<_n;i++){
            if(pos[i]==index) continue;
            char z = ask(pos[i]);
            if(z=='<'){
                lower.pb(pos[i]);
            } else{
                higher.pb(pos[i]);
            }
            ask(index);
        }
        ans[index] = x;
        if(r-l==1){
            int other = (pos[0]==index?pos[1]:pos[0]);
            ans[other] = (ans[index]==l?r:l);
        } else{
            self(self,l,mid-1,lower);
            self(self,mid+1,r,higher);
        }
    };
    vi iotaa(n);
    for(int i=0;i<n;i++){
        iotaa[i] = i+1;
    }
    conquer(conquer,1,n,iotaa);
    cout << "! ";
    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    cout.flush();
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
