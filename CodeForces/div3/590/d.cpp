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
#define endl "\n"

int q ;
set<int> A[26];

void solve(){
    string S;
    cin >> S >> q;
    int n = S.size();
    rep(i,n) A[S[i]-'a'].insert(i);
    rep(i,q){
        int t;
        cin >> t;
        if(t == 1){
            int a;
            char s;
            cin >> a >> s;
            a--;
            char c = S[a];
            A[c-'a'].erase(a);
            A[s-'a'].insert(a);
            S[a] = s;

        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            int cnt = 0;
            rep(j,26){
                auto it = A[j].lower_bound(l);
                if(it == A[j].end()) continue;
                if(*it < r) cnt++;
            }
            cout << cnt << endl;
        }
    }
}

int main(){
    fast_input_output
    solve();
}