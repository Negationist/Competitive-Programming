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
    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int k = min((n+m)/3,min(n,m));
    cout << k << "\n";
    int l=0, r=n-1;
    vi c;
    vi d;
    while(l<r){
        int diff = a[r]-a[l];
        c.pb(diff);
        ++l;
        --r;
    }
    l = 0;
    r = m-1;
    while(l<r){
        int diff = b[r]-b[l];
        d.pb(diff);
        ++l;
        --r;
    }
    int i=0,j=0;
    int cnt1 = n, cnt2 = m;
    int ans = 0;
    int temp;
    bool top = false;
    bool bottom = false;
    int num = 0;
    for(int l=1;l<=k;l++){
        if(top){ //ran out of tops, only thing we could do is remove tops and add bottoms
            while(i>=0){
                ans-=c[i];
                cnt1+=2;
                ++cnt2;
                --num;
                while(cnt1>0 && cnt2>1 && j<m && num<k){
                    --cnt1;
                    cnt2-=2;
                    ans+=d[j];
                    ++j;
                    ++num;
                }
                ans = max(temp,ans);
                if(num==k){
                    break;
                }
            }
        } else if(bottom){
            while(j>=0){
                ans-=d[j];
                cnt2+=2;
                ++cnt1;
                --num;
                while(cnt1>1 && cnt2>0 && i<m && num<k){
                    --cnt2;
                    cnt1-=2;
                    ans+=c[i];
                    ++j;
                    ++num;
                }
                ans = max(temp,ans);
                if(num==k){
                    break;
                }
            }
        }
        if(c[i]>d[j]){
            if(cnt1>1 && cnt2>0){
                ans+=c[i];
                cnt1-=2;
                --cnt2;
                ++i;
                ++num;
            } else{
                if(cnt1<2){
                    bottom = true;
                } else{
                    top = true;
                }
            }
            if(i==c.size()){
                top = true;
                temp = ans;
            }
        } else{
            if(cnt2>1 && cnt1>0){
                ans+=d[j];
                cnt2-=2;
                --cnt1;
                ++j;
                ++num;
            } else{
                if(cnt2<2){
                    top = true;
                } else{
                    bottom = true;
                }
            }
            if(j==d.size()){
                bottom = true;
                temp = ans;
            }
        }
        cout << ans << "\n";
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
