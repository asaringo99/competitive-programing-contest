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

int n, k ;

int main(){
    fast_input_output
    cin >> n >> k ;
    int N = n;
    if(2 * k > n){
        cout << -1 << endl;
        return 0;
    }
    int p = n / k;
    int res = 1;
    while(n / (2 * k) > 1){
        vector<int> out;
        for(int i = res ; i < res + 2 * k ; i++) out.push_back(i);
        rrep(i,k,2*k) cout << out[i] << " ";
        rrep(i,0,k) cout << out[i] << " ";
        res += 2 * k;
        n -= k;
        n -= k;
    }
    if(n % (2 * k) <= k){
        vector<int> out;
        rrep(i,res,N+1) out.push_back(i);
        rrep(i,k,out.size()) cout << out[i] << " ";
        rrep(i,0,k) cout << out[i] << " ";
    }
    else{
        int q = n % (2 * k);
        vector<int> out;
        rrep(i,res,N+1) out.push_back(i);
        rrep(i,k,2*k) cout << out[i] << " ";
        rrep(i,0,q-k) cout << out[i] << " ";
        rrep(i,out.size()-k,out.size()) cout << out[i] << " ";
        rrep(i,q-k,k) cout << out[i] << " ";
        rrep(i,2*k,out.size()-k) cout << out[i] << " ";
    }
    cout << endl;
}