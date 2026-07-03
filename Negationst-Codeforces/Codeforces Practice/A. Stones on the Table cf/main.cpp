#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    int c=0;
    string s;
    getline (cin, s);
    for (int i=0; i<s.size()-1; i++){
        if (s[i]==s[i+1]){
           c++;
        }
    }
    cout << c;
    return 0;
}
