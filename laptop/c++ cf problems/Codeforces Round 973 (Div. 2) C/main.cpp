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
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int cnt = 0;
        bool left = false;
        bool endgame = false;
        int n;
        cin >> n;
        int ans;
        if(n==1){
            cout << "? 0\n";
            cout.flush();
            cin >> ans;
            if(ans==1){
                cout << "! 0\n";
            } else{
                cout << "! 1\n";
            }
            cout.flush();
            continue;
        }
        int cur = 0;
        string s = "0";
        cout << "? " << s << "\n";
        cout.flush();
        cin >> ans;
        if(ans == 0){
            string output;
            for(int i=0;i<n;i++){
                output.push_back('1');
            }
            cout << "! " << output << endl;
            cout.flush();
            continue;
        }
        s = "01";
        cout << "? " << s << "\n";
        cout.flush();
        while(true){
            cin >> ans;
            if(s.size()==n && ans==1){
                cout << "! " << s << "\n";
                break;
            }
            if(endgame){
                if(ans==0){
                    if(left){
                        if(s[0]=='1'){
                            s[0]='0';
                        } else{
                            s[0] = '1';
                        }
                    } else{
                        if(s[s.size()-1]=='1'){
                            s[s.size()-1] = '0';
                        } else{
                            s[s.size()-1] = '1';
                        }

                    }
                } else{
                    if(left)  s.insert(0,1,'0');
                    else s.push_back('0');
                }
                cout << "? " << s << "\n";
                continue;
            }
            if(ans==0){
                cnt++;
                if(cnt==2){
                    endgame = true;
                    if(left){
                       s.erase(0,1);
                    } else{
                        s.pop_back();
                    }
                    left = !left;
                    if(left){
                        s.insert(0,1,cur+'0');
                    } else{
                        s.push_back(cur+'0');
                    }
                    cout << "? " << s << "\n";
                    cout.flush();
                    continue;
                }
                if(left){
                    s[0] = cur+'0';
                }
                else{
                    s[s.size()-1] = cur+'0';
                }
            } else{
                cnt = 0;
                left = !left;
                if(left){
                    s.insert(0,1,cur + '0');
                } else{
                    s.push_back(cur+'0');
                }

            }
            cout << "? " << s << "\n";
            cout.flush();
            cur = 1-cur;
        }

    }
    return 0;
}
