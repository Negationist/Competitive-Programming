using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll a, b; cin >> a >> b;
        ll sig_bits = 63 - __builtin_clzll(a);
        ll sig_bits_2 = 63 - __builtin_clzll(b);
        //cout << sig_bits << " " << sig_bits_2 << "\n";
        if(sig_bits_2 == sig_bits){
            cout << "1\n";
            cout << a << " " << b << "\n";
            continue;
        }
        ll next = -1;
        //cout << sig_bits << "hi\n";
        for(ll i = sig_bits - 1; i >= 0; i--){
            if(a & (1LL << i)){
                next = i;
                break;
            }
        }
        //cout << next << "hi2\n";
        if(next == -1){
            cout << next << "\n";
            continue;
        }
        ll best = (1 << (next + 1)) - 1;
        if(b <= best){
            if(b == best){
                cout << "1\n";
                cout << a << " " << b << "\n";
            }
            else{
                cout << "2\n";
                cout << a << " " << best << " " << b << "\n";
            }
        }
        else{
            cout << "-1\n";
        }
    }
}
