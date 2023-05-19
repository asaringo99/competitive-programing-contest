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

int z ;

void solve(){
    string S, T;
    cin >> S;
    int n = S.size();
    T = S;
    reverse(T.begin(),T.end());
    string ord = "";
    vector<bool> B(26,false);
    rep(i,n){
        int a = T[i]-'a';
        if(B[a]) continue;
        B[a] = true;
        ord += T[i];
    }
    vector<int> C(26,0), D(26,0);
    for(char u : S){
        C[u-'a']++;
    }
    reverse(ord.begin(),ord.end());
    int bef = 0, sum = 0;
    int m = ord.size();
    for(int i = m ; i > 0 ; i--){
        int k = ord[i-1] - 'a';
        if(C[k] % i != 0){
            cout << -1 << endl;
            return;
        }
        int d = C[k] / i;
        D[k] = d;
        sum += d;
        vector<int> E(26,0);
        for(int j = bef ; j < bef + sum ; j++){
            E[T[j]-'a']++;
        }
        bef += sum;
        if(D != E){
            cout << -1 << endl;
            return;
        }
    }
    string res = "";
    rep(i,sum) res += S[i];
    string ver = res;
    string s = res;
    rep(i,m){
        string t = "";
        for(char u : s) if(u != ord[i]) t += u;
        ver += t;
        s = t;
    }
    if(ver == S) cout << res << " " << ord << endl;
    else cout << -1 << endl;
}

int main(){
    fast_input_output
    cin >> z ;
    rep(i,z) solve();
}