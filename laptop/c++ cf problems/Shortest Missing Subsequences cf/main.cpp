#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>

using namespace std;

void populate(string &v, set<char>&s){
    for(int i=0;i<v.size();i++){
        s.insert(v[i]);
    }
}

void solve(){
    string v;
    cin >> v;
    set<char> s;
    populate(v,s);
    string h;
    cin >> h;
    int ans=0;
    //find subsequence directly
    for(int i=0;i<h.size();i++){
        s.erase(h[i]);
        if(!s.size()){
            ans++;
            populate(v,s);
        }
    }
    ans++;
    populate(v,s);
    //fill intervals
    map<char,vector<int>>p;
    for(int i=0;i<h.size();i++){
        int cur = h[i];
        p[cur].pb(i);
    }
    //find max size
    int q;
    cin >> q;
    while(q--){
        string cur;
        cin >> cur;
        if(cur.size()!=ans){
            cout << 0 << "\n";
            continue;
        }
        int index=0;
        int place=-1;
        while(true){
            char z = cur[index];
            if(s.find(z)==s.end()){
                cout << 0 << "\n";
                break;
            }
            //check if its actually in the set
            if(index==ans-1){
                if(p[z].size()==0){
                    cout << 1 << "\n";
                    break;
                }
                if(place>p[z].back()){
                    cout << 1 << "\n";
                } else{
                    cout << 0 << "\n";
                }
                break;
            }
            //if last check that it is not findable
            int l = 0, r=p[z].size()-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(mid<0){
                    l=0;
                    break;
                }
                if(p[z][mid]>=place){
                    r = mid-1;
                } else{
                    l = mid+1;
                }
            }
            place = p[z][l]+1;
            index++;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
