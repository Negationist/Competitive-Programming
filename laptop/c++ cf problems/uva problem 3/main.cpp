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
    bool founda = false;
    bool foundb = false;
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,d;
    set<int> a;
    set<int> b;
    unordered_map<int,int> c;
    for(int i=c;i<=d;i++){
        string x;
        cin >> x;
        if(x == "Fizz"){
            founda = true;
            a.insert(i);
            for(int j=1;j<=i/2;j++){
                if(i%j==0){
                    a.insert(j);
                }
            }
        } else if(x == "Buzz"){
            foundb = true;
            b.insert(i);
            for(int j=1;j<=i/2;j++){
                if(i%j==0){
                    a.insert(j);
                }
            }
        } else if(x == "FizzBuzz"){
            for(int j=1;j<=i/2;j++){
                if(i%j == 0){
                    c[j] = i/j;
                }
            }
        }
        for(int x : a){
            if (s.find(x) != s.end()){
                if(c[x]!=0){
                    if (b.find(c[x] != b.end())){
                        cout << x << " " << c[x];
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
;
