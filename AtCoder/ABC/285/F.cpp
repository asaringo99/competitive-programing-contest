#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

template<typename T = bool>
struct SegmentTree{
    int n , n_;
    vector<T> dat;
    vector<pair<int,int>> range;
    SegmentTree(int _n){
        n = 1 ;
        n_ = _n ;
        while(n < _n) n *= 2;
        dat.resize(2 * n - 1,0);
        range.resize(2 * n - 1);
        range[0] = {0,n};
        for(int i = 0 ; i < n - 1 ; i++){
            auto [l,r] = range[i];
            range[2*i+1] = {l,l+(r-l)/2};
            range[2*i+2] = {l+(r-l)/2,r};
        }
    }
    void update(int k , T x){
        k += n - 1 ;
        dat[k] = x ;
        while(k > 0){
            k = (k - 1) / 2 ;
            dat[k] = (dat[2*k+1] & dat[2*k+2]) ;
        }
    }
    T sub_query(int a , int b , int k , int l , int r){
        if(r <= a || b <= l) return 1 ;
        if(a <= l && r <= b) return dat[k] ;
        T lef = sub_query(a,b,2*k+1,l,(l+r)/2) ;
        T rig = sub_query(a,b,2*k+2,(l+r)/2,r) ;
        return (lef & rig) ;
    }
    T query(int a , int b){
        return sub_query(a,b,0,0,n) ;
    }
};

int n;
string S;
int q;
set<int> st[30];

int main(){
    fast_io
    cin >> n >> S >> q;
    SegmentTree segtree(n);
    rep(i,n){
        st[S[i]-'a'].insert(i);
    }
    rep(i,n-1) {
        segtree.update(i,(S[i] <= S[i+1]));
        // cout << segtree.query(i,i+1) << endl;
    }

    rep(i,q){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            char c;
            cin >> x >> c;
            x--;
            int id = S[x] - 'a';
            st[id].erase(x);
            st[c-'a'].insert(x);
            S[x] = c;
            if(x > 0) segtree.update(x-1,(S[x-1] <= S[x]));
            if(x < n - 1) segtree.update(x,(S[x] <= S[x+1]));
        }
        if(t == 2){
            int l, r;
            cin >> l >> r;
            l--; r--;
            if(l == r){
                pt("Yes");
                continue;
            }
            // cout << "seg: " << segtree.query(l,r) << endl;
            if(!segtree.query(l,r)){
                pt("No");
                continue;
            }
            set<int> set_S, set_T;
            rep(k,26){
                if(st[k].empty()) continue;
                auto it = st[k].lower_bound(l);
                if(it == st[k].end()) continue;
                int id = *it;
                if(id <= r) set_S.insert(k);
            }
            // cout << "set : ";
            // for(int u : set_S) cout << u << " "; cout << endl;
            bool ok = false;
            if(set_S.size() == 0) ok = true;
            else if(set_S.size() == 1) ok = true;
            else if(set_S.size() == 2) ok = true;
            else{
                auto it = set_S.begin();
                auto jt = set_S.end(); jt--;
                set_S.erase(it++);
                int start = *it;
                set_S.erase(jt--);
                int end = *jt;
                // cout << start << " " << end << endl;
                ok = true;
                for(int k = start; k <= end; k++){
                    if(st[k].empty()) continue;
                    auto sit = st[k].begin();
                    auto eit = st[k].end(); eit--;
                    int sid = *sit;
                    int eid = *eit;
                    if(l > sid || eid > r) ok = false;
                }
                if(ok) pt("Yes");
                else pt("No");
            }

        }
    }
}