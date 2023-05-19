#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
typedef long long ll ;
typedef long double ld ;
typedef pair<char,ll> P ;
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
#define endl "\n"

int n ;
int A[440];

int main(){
    fast_input_output
    cin >> n ;
    rep(i,n) cin >> A[i], A[i]--;
    vector<P> res;
    int a = 0;
    set<int> odd, eve;
    rep(i,n) if(A[i] % 2 != i % 2) {
        a++;
        if(i % 2 == 0) eve.insert(i);
        if(i % 2 == 1) odd.insert(i);
    }
    int m = eve.size();
    int p = 0;
    while(!odd.empty()){
        int oid = *odd.begin();
        int eid = *eve.begin();
        int id = min(oid,eid);
        int nd = max(oid,eid);
        odd.erase(oid);
        eve.erase(eid);
        while(nd - id != 1){
            res.push_back({'B',id+1});
            swap(A[id],A[id+2]);
            if(odd.count(id+2)){
                odd.erase(odd.find(id+2));
                odd.insert(id);
            }
            if(eve.count(id+2)){
                eve.erase(eve.find(id+2));
                eve.insert(id);
            }
            id += 2;
        }
        swap(A[id],A[id+1]);
        res.push_back({'A',id+1});
    }
    rep(i,n){
        rep(j,n){
            if(A[j] == i){
                int k = j;
                while(k != i){
                    res.push_back({'B',k-1});
                    swap(A[k-2],A[k]);
                    k -= 2;
                }
                break;
            }
        }
    }
    cout << res.size() << endl;
    for(P p : res){
        cout << p.first << " " << p.second << endl;
    }
}