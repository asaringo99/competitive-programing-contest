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
typedef pair<int,int> P ;
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

int n, m;
string S;

void solve(){
    cin >> n >> m >> S;
    vector<int> M(m,0);
    set<int> col;
    int N = n * m;
    int c = 0;
    rep(i,n*m){
        if(S[i] == '0'){
            cout << 0 << " ";
            c = i + 1;
            continue;
        }
        break;
    }
    int s = 0;
    rep(i,n){
        rep(j,m){
            if(i*m+j+c >= n*m) break;
            if(S[i*m+j+c] == '0'){
                s++;
            }
            else{
                col.insert((i*m+j)%m);
                s = 0;
            }
            if(s >= m){
                M[j]++;
            }
            cout << col.size() + (i * m + j) / m + 1 - M[j] << " ";
        }
    }
    cout << endl;
}

int main(){
    int z;
    cin >> z;
    rep(i,z) solve();
}