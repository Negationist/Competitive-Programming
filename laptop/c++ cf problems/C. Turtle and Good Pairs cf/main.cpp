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
        string s;
        cin >> n >> s;
        if(n==1) {
            cout << s << "\n";
            continue;
        }
        int arr[26] = {};
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        int x=-1,y=-1;
        for(int i=0;i<26;i++){
            if( x == -1 || arr[i] > arr[x]){
                y = x;
                x = i;
            }
            else if(y == -1 || arr[i] > arr[y]){
                y = i;
            }
        }
        for(int i=0;i<arr[x]-arr[y];i++){
            char z = x+'a';
            cout << z;
        }
        arr[x] = arr[y];
        bool go = true;
        while(go){
            go = false;
            for(int i=0;i<26;i++){
                if(arr[i]>0) {
                    go = true;
                    char z = i+'a';

                    arr[i]--;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
