#include <bits/stdc++.h>
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define print(x) cout << (x) << "\n"
#define each(a, x) for(auto &&a : x)

using namespace std;
int mod;

struct Matrix {
    int cell[2][2];

    Matrix() {
        memset(cell, 0, sizeof(cell));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    res.cell[i][j] = (res.cell[i][j] + (cell[i][k] * other.cell[k][j]) % mod) % mod;
        return res;
    }

    void identity() {
        memset(cell, 0, sizeof(cell));
        for(int i = 0; i < 2; i++) cell[i][i] = 1;
    }

    void debug() {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++)
                cout << cell[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
};

struct segTree {
    vector<Matrix> tree;
    int n;

    segTree(vector<Matrix> &a) {
        int _n = a.size();
        n = 1;
        while(n < _n) n *= 2;
        tree.assign(2 * n, Matrix());

        for(int i = 0; i < n; i++) tree[i + n].identity();
        for(int i = 0; i < _n; i++) tree[i + n] = a[i];

        for(int i = n - 1; i >= 1; i--)
            tree[i] = tree[i * 2] * tree[i * 2 + 1];
    }

    Matrix prod(int a, int b) {
        Matrix resl, resr;
        resl.identity();
        resr.identity();
        a += n; b += n;
        while(a <= b) {
            if(a & 1) resl = resl * tree[a++];
            if(!(b & 1)) resr = tree[b--] * resr;
            a >>= 1;
            b >>= 1;
        }
        return resl * resr;
    }
};

void solve() {
    int m, n;
    cin >> mod >> n >> m;
    vector<Matrix> a(n);
    for(int i = 0; i < n; i++) {
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        a[i].cell[0][0] = x;
        a[i].cell[0][1] = y;
        a[i].cell[1][0] = z;
        a[i].cell[1][1] = w;
    }

    segTree tree(a);
    while(m--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        Matrix res = tree.prod(l, r);
        res.debug();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
