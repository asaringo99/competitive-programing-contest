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

void solve(){
    ll n;
    string T;
    cin >> T;
    n = T.size();
    deque<char> S;
    int one = 0, zero = 0;
    rep(i,n){
        char a = T[i];
        if(a == '1') one++;
        else zero++;
        S.push_back(a);
    }
    if(one == 0 || zero == 0){
        cout << 0 << endl;
        return;
    }

    ll swp = (ll)1e12;
    ll nsp = (ll)1e12 + 1;
    ll res = 1e18;
    ll sum = 0;
    int cnt = 0;
    while(!S.empty()){
        while(!S.empty() && S.back() == '1') S.pop_back(), one--;
        while(!S.empty() && S.front() == '0') S.pop_front(), zero--;
        if(S.empty()) break;
        if(S.size() == 1) break;
        if(S.size() == 2){
            chmin(res,sum+swp);
            cout << res << endl;
            return;
        }
        chmin(res, sum + nsp * (ll)min(zero,one));
        if(S[1] == '0'){
            chmin(res, sum + swp + nsp * (zero - 1));
        }
        if(S[S.size()-2] == '1'){
            chmin(res, sum + swp + nsp * (one - 1));
        }
        while(!S.empty() && S.back() == '0') {
            sum += nsp;
            zero--;
            S.pop_back();
        }
        while(!S.empty() && S.front() == '1') {
            sum += nsp;
            one--;
            S.pop_front();
        }
        cnt++;
    }
    chmin(res,sum);
    cout << res << endl;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}