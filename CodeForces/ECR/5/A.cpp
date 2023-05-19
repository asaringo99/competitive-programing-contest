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
    string S, T;
    cin >> S >> T;
    int n = S.size(), m = T.size();
    reverse(all(S));
    reverse(all(T));
    while(!S.empty()){
        if(S.back() == '0') S.pop_back();
        else break;
    }
    while(!T.empty()){
        if(T.back() == '0') T.pop_back();
        else break;
    }
    reverse(all(S));
    reverse(all(T));
    if(S == T){
        cout << "=" << endl;
        return;
    }
    if(S.size() > T.size()){
        cout << ">" << endl;
        return;
    }
    else if(S.size() < T.size()){
        cout << "<" << endl;
        return;
    }
    else{
        rep(i,S.size()){
            if(S[i] - '0' > T[i] - '0'){
                cout << ">" << endl;
                return;
            }
            else if(S[i] - '0' < T[i] - '0'){
                cout << "<" << endl;
                return;
            }
        }
    }
    cout << "=" << endl;
}

int main(){
    fast_io
    solve();
}