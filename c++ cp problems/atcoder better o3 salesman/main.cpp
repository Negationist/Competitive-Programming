#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 1) BoundedSegtree: supports sum queries and two find-in-one-descent methods
template<typename T>
struct BoundedSegtree {
    ll L,R,n;
    vector<T> t;
    function<T(T,T)> merge;
    T id;
    BoundedSegtree(function<T(T,T)> op, T identity, ll left, ll right)
      : L(left), R(right), n(right-left+1),
        t(4*(right-left+1), identity),
        merge(op), id(identity) {}

    inline int idx(ll x) const { return int(x - L); }
    void set(ll x, T v)  { _set(1,0,n-1, idx(x), v); }
    void add(ll x, T dv) { _add(1,0,n-1, idx(x), dv); }
    T query(ll ql, ll qr) const {
        if(qr<ql) return id;
        return _query(1,0,n-1, idx(ql), idx(qr));
    }

    // find largest i in [L..R] with sum(i..R) >= need
    ll find_last_ge(ll need, bool &found) const {
        if(t[1] < need) { found=false; return L-1; }
        found=true;
        int pos = _find_last(1,0,n-1, need);
        return L + pos;
    }
    // find smallest i in [L..R] with sum(i..R) <= k
    ll find_first_leq(ll k, bool &found) const {
        ll total = t[1], need=total-k;
        if(need<=0){ found=true; return L; }
        if(t[1]<need){ found=false; return R+1; }
        int j=_find_last(1,0,n-1,need), i=j+1;
        if(i>=n){ found=false; return R+1; }
        found=true;
        return L + i;
    }

  private:
    void _set(int p,int l,int r,int i,T v){
        if(l==r){ t[p]=v; return; }
        int m=(l+r)>>1;
        i<=m?_set(p<<1,l,m,i,v):_set(p<<1|1,m+1,r,i,v);
        t[p]=merge(t[p<<1],t[p<<1|1]);
    }
    void _add(int p,int l,int r,int i,T dv){
        if(l==r){ t[p]=merge(t[p],dv); return; }
        int m=(l+r)>>1;
        i<=m?_add(p<<1,l,m,i,dv):_add(p<<1|1,m+1,r,i,dv);
        t[p]=merge(t[p<<1],t[p<<1|1]);
    }
    T _query(int p,int l,int r,int ql,int qr) const {
        if(qr<l||r<ql) return id;
        if(ql<=l&&r<=qr) return t[p];
        int m=(l+r)>>1;
        return merge(_query(p<<1,l,m,ql,qr),
                     _query(p<<1|1,m+1,r,ql,qr));
    }
    int _find_last(int p,int l,int r,ll need) const {
        if(l==r) return l;
        int m=(l+r)>>1;
        T rightSum = t[p<<1|1];
        if(rightSum>=need) return _find_last(p<<1|1,m+1,r,need);
        return _find_last(p<<1,l,m,need-rightSum);
    }
};

// sum-op
ll op_sum(ll a,ll b){return a+b;}

// 2) SlopeTrick wrapper with rollback and get_min
struct SlopeTrick {
    using Seg=BoundedSegtree<ll>;
    ll m=0,b=0,L,R;
    map<ll,ll> delta;
    vector<tuple<int,ll,ll>> hist;
    unique_ptr<Seg> seg;

    SlopeTrick(ll left,ll right)
      : L(left),R(right),
        seg(make_unique<Seg>(op_sum,0LL,L,R)) {}

    ll now() const { return hist.size(); }
    void rollback(ll t){
        while(hist.size()>t){
            auto [tp,x,v]=hist.back(); hist.pop_back();
            if(tp==1) m-=x;
            else if(tp==2) b-=x;
            else {
                delta[x]-=v;
                if(!delta[x]) delta.erase(x);
                seg->set(x, delta.count(x)?delta[x]:0);
            }
        }
    }

    void add_slope(ll x,ll v){
        if(!v) return;
        delta[x]+=v;
        if(!delta[x]) delta.erase(x);
        seg->set(x, delta.count(x)?delta[x]:0);
        hist.emplace_back(3,x,v);
    }

    void set_max(ll mx){
        ll om=m, ob=b;
        while(m>mx){
            auto it=prev(delta.end());
            ll x=it->first,c=it->second,y=m*x+b;
            ll t=min(c,m-mx);
            add_slope(x,-t);
            m-=t; b=y-m*x;
        }
        hist.emplace_back(1,m-om,0);
        hist.emplace_back(2,b-ob,0);
    }
    void set_min(ll mn){
        ll om=m, ob=b;
        while(m<mn){
            auto it=delta.begin();
            ll x=it->first,c=it->second,y=m*x+b;
            ll t=min(c,mn-m);
            add_slope(x,-t);
            m+=t; b=y-m*x;
        }
        hist.emplace_back(1,m-om,0);
        hist.emplace_back(2,b-ob,0);
    }

    void add_abs(ll D,ll x0){
        add_slope(x0,2*D);
        b+=D*x0;
    }

    // brute get_min over breakpoints
    pair<ll,ll> get_min() const {
        ll best=LLONG_MAX,pos=L;
        ll prevx=L, slope=m-delta.empty()?0:m-seg->query(L,R); // approximate
        ll y=slope*L+b;
        vector<pair<ll,ll>> pts(delta.begin(),delta.end());
        for(auto &pr:pts){
            ll x=pr.first,c=pr.second;
            y+=slope*(x-prevx);
            slope+=c;
            if(y<best){ best=y; pos=x; }
            prevx=x;
        }
        ll yR=y+slope*(R-prevx);
        if(yR<best){ best=yR; pos=R; }
        return {pos,best};
    }

    ll query_left(ll C) const {
        bool f; ll need=m-(-C);
        ll i=seg->find_first_leq(need,f);
        return f?max(L,i-1):L;
    }
    ll query_right(ll C) const {
        bool f; ll need=m-C;
        ll i=seg->find_last_ge(need,f);
        return f?i:R;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; ll C,D;
    cin>>N>>C>>D;
    vector<ll>X(N+1),timeSt(N+1);
    for(int i=1;i<=N;i++)cin>>X[i];

    SlopeTrick st(-100000,100000);

    timeSt[0]=st.now();
    st.add_abs(C,0);
    st.set_max(C); st.set_min(-C);

    for(int i=1;i<=N;i++){
        timeSt[i]=st.now();
        st.add_abs(D, X[i]);
        st.set_max(C); st.set_min(-C);
    }

    auto [bestPos,bestCost] = st.get_min();
    cout<<bestCost<<"\n";

    vector<ll>ans(N);
    ll pos=bestPos;
    for(int i=N;i>=1;i--){
        ans[i-1]=pos;
        st.rollback(timeSt[i-1]);
        ll l=st.query_left(C), r=st.query_right(C);
        if(pos<l) pos=l;
        else if(pos>r) pos=r;
    }
    for(ll v:ans) cout<<v<<" ";
    cout<<"\n";
    return 0;
}
