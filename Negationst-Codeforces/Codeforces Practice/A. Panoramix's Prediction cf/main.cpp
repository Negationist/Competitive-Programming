#include <iostream>
#include <cmath>

using namespace std;

bool primecheck(int a){
for (int i=2; i<=a/2;i++){
    if (a==2){
        return true;
    }
    if (a%i == 0){
        return false;
    }
}
return true;
}

int main()
{
    int a,b;
    cin >> a >> b;
    for(int i=a+1; i<b; i++){
        if (primecheck(i)){
            cout << "NO";
            return 0;
        }
    }
    if (primecheck(b)){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}
