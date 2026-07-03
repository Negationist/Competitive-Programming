#include <bits/stdc++.h>

#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

unordered_map<int,long long> lookup;

int Fib(int n){
if (lookup.find(n)!=lookup.end()){
    return lookup[n];
} else{
int a = Fib(n-1)+Fib(n-2);
lookup[n] = a;
return a;
}
}
int FibFinder(int n){
int i=0;
int total = 0;
while (true){
    if (Fib(i)==n){
        return i;
    }
    total+=Fib(i);
    i++;
}
}


int main()
{
    lookup[0] = 0;
    lookup[1] = 1;
    int a;
    cin >> a;
    if (a==0){
        cout << "0 0 0";
        return 0;
    } else if(a==1){
        cout << "0 0 1";
        return 0;
    } else if(a==2){
        cout << "0 1 1";
        return 0;
    } else if(a==3){
        cout << "1 1 1";
        return 0;
    }
    int base = FibFinder(a);
    cout << Fib(base-4) << " " << Fib(base-3) << " " << Fib(base-1);
    return 0;
}
