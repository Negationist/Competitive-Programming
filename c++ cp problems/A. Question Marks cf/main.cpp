#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,a=0,b=0,c=0,d=0;
        cin >> n;
        string s;
        cin >> s;
        for(int i=0;i<4*n;i++){
            if(s[i]=='A') a++;
            if(s[i]=='B') b++;
            if(s[i]=='C') c++;
            if(s[i]=='D') d++;
        }
        a = min(a,n);
        b = min(b,n);
        c = min(c,n);
        d = min(d,n);
        cout << a+b+c+d << endl;
    }
    return 0;
}
