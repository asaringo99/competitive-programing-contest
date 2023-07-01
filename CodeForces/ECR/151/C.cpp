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
#define leading_zero_count(x) __builtin_clz(x)
#define trailing_zero_count(x) __builtin_ctz(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"
#define v1(n,a) vector<ll>(n,a)
#define v2(n,m,a) vector<vector<ll>>(n,v1(m,a))
#define v3(n,m,k,a) vector<vector<vector<ll>>>(n,v2(m,k,a))
#define v4(n,m,k,l,a) vector<vector<vector<vector<ll>>>>(n,v3(m,k,l,a))
template<typename T,typename U>istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T,typename U>ostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T>istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>istream &operator>>(istream&is,vector<vector<T>>&v){for(T &in:v){is>>in;}return is;}
template<typename T>ostream &operator<<(ostream&os,const vector<vector<T>>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?"\n":"");}return os;}
template<typename T>ostream &operator<<(ostream&os,const set<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}

vector<vector<int>> f(string &S){
    int n = S.size();
    vector<vector<int>> nextv(n+1, vector<int>(10,n));
    for(int i = n - 1; i >= 0; i--){
        rep(j,10) nextv[i][j] = nextv[i+1][j];
        nextv[i][S[i]-'0'] = i;
    }
    return nextv;
}

void solve(){
    string S;
    cin >> S;
    int n = S.size();
    int q;
    cin >> q;
    string LS, RS;
    cin >> LS >> RS;
    vector<int> L(q), R(q);
    rep(i,q){
        L[i] = LS[i] - '0';
        R[i] = RS[i] - '0';
    }
    vector<vector<int>> dp(q+1,vector<int>(10,-1));
    auto nextv = f(S);
    // rep(i,10){
    //     rep(j,n+1) cout <<  nextv[j][i] << " "; cout << endl;
    // }
    rep(i,q){
        int l = L[i], r = R[i];
        if(i == 0) rrep(x,l,r+1){
            dp[i+1][x] = nextv[0][x];
            if(nextv[0][x] == n){
                cout << "YES" << endl;
                return;
            }
        }
        else{
            rrep(x,0,10){
                if(dp[i][x] == -1) continue;
                rrep(y,l,r+1){
                    int now = dp[i][x];
                    int nv = nextv[now+1][y];
                    if(nv == n){
                        cout << "YES" << endl ;
                        return;
                    }
                    chmax(dp[i+1][y], nv);
                }
            }
        }
    }
    cout << "NO" << endl ;
}

int main(){
    fast_io
    int t;
    cin >> t;
    rep(i,t) solve();
}