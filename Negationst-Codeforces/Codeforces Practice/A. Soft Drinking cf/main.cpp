#include <bits/stdc++.h>

using namespace std;

int main()
{
    int toasts = INT_MAX;
    int n,k,l,c,d,p,nl,np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    toasts = min(toasts,k*l/nl);
    toasts = min(toasts,c*d);
    toasts = min(toasts,p/np);
    cout << toasts/n;
    return 0;
}
