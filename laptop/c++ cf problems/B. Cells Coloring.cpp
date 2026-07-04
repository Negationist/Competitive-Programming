using namespace std;
#include <bits/stdc++.h>
#define ll long long
typedef pair<int, int> pii;
#define MAXN 255

int row[MAXN];
int col[MAXN];
char input[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, m, c1, d; cin >> n >> m >> c1 >> d;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            input[i][j] = s[j];
            if(s[j] == '.'){
                row[i] += 1; col[j] += 1;
            }
        }
    }
    priority_queue<pair<pii, pii>> track;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(input[i][j] == '.'){
                track.push({{max(row[i], col[j]), min(row[i], col[j])}, {i, j}});
            }
        }
    }

    ll res = ((track.top()).first.first) * c1;
    ll cnt0 = 0;
    while(track.size() > 0){
        auto [val, index] = (track.top());
        auto [r, c] = index;
        auto [val1, val2] = val;
        //cerr << r << " " << c << " " << val1 << " " << val2  << " " << row[r] << " " << col[c] << "hi\n";
        track.pop();
        //cerr << r << " " << c << " " << val1 << " " << val2  << " " << row[r] << " " << col[c] << "hi3\n";
        
        pii tmp1 = {val1, val2}; pii tmp2 = {val2, val1}; pii tmp3 = {row[r], col[c]};
        //cerr << r << " " << c << " " << val1 << " " << val2  << " " << row[r] << " " << col[c] << "hi4\n";
        if((tmp1 != tmp3) && (tmp2 != tmp3)){
            //cerr << r << " " << c << " " << val1 << " " << val2  << " " << row[r] << " " << col[c] << "hi5\n";
            continue;
        }
        //cout << r << " " << c << " " << val1 << " " << val2 << "hi2\n";
        input[r][c] = '*';
        for(int j = 0; j < m; j++){
            if(input[r][j] == '.'){
                int og_row = row[r];
                int og_col = col[j];
                //track.erase({{max(og_row, og_col), min(og_row, og_col)}, {r, j}});
                track.push({{max(og_row - 1, og_col), min(og_row - 1, og_col)}, {r, j}});
            }
        }
        row[r] -= 1;
        for(int j = 0; j < n; j++){
            if(input[j][c] == '.'){
                int og_row = row[j];
                int og_col = col[c];
                //track.erase({{max(og_row, og_col), min(og_row, og_col)}, {j, c}});
                track.push({{max(og_row, og_col - 1), min(og_row, og_col - 1)}, {j, c}});
            }
        }
        col[c] -= 1;
        cnt0 += 1;
        
        ll check = ((track.top()).first.first) * c1 + cnt0 * d;
        res = min(res, check);
        //cout << ((track.top()).first.first) << " " << c  << " " << cnt0 << " " << d  << " " << res << "\n";
    }
    cout << res << "\n";
}