#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q,i,sl,sr;
    int o=0; int z=0;
    cin >> q;
    vector<int>l;
    vector<int>r;
    for (i=0; i<q; i++){
        int a,b;
        cin >> a >> b;
        l.push_back(a);
        r.push_back(b);
    }
    for (i = 0; i<q; i++){
        if(l[i]==0){
            o++;
        } else{
            z++;
        }
    }
    if (o>=z){
        sl = z;
    } else {
    sl = o;
    }
    o = 0;
    z = 0;
    for (i = 0; i<q; i++){
        if(r[i]==0){
            o++;
        } else{
            z++;
        }
    }
    if (o>=z){
        sr = z;
    } else {
    sr = o;
    }

    cout << sl +sr;
    return 0;
}
