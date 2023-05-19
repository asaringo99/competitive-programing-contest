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
#define pt(a) cout << a << endl
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> C(n,vector<char>(m));
    rep(i,n) rep(j,m) cin >> C[i][j];
    ll minval = 0, maxval = 0;
    rep(i,n){
        int room2 = m / 4;
        int room1 = m / 2;
        int j = 0;
        int cnt = 0;
        rep(j,m) if(C[i][j] == '1') cnt++;
        while(j < m - 1){
            if(room2 == 0) break;
            if(C[i][j] == '1' && C[i][j+1] == '0'){
                room2--;
                cnt--;
                maxval++;
                j += 2;
            }
            else if(C[i][j] == '0' && C[i][j+1] == '1'){
                room2--;
                cnt--;
                maxval++;
                j += 2;
            }
            else if(C[i][j] == '0' && C[i][j+1] == '0'){
                room2--;
                j += 2;
            }
            else j++;
        }
        cnt -= room2 * 2;
        maxval += room2;
        maxval += cnt;
    }
    rep(i,n){
        int room2 = m / 4;
        int room1 = m / 2;
        int j = 0;
        int cnt = 0;
        rep(j,m) if(C[i][j] == '1') cnt++;
        while(j < m - 1){
            if(room2 == 0) break;
            if(C[i][j] == '1' && C[i][j+1] == '1'){
                room2--;
                cnt -= 2;
                minval++;
                j += 2;
            }
            else j++;
        }
        minval += cnt;
    }
    cout << minval << " " << maxval << endl;
}

int main(){
    fast_io
    solve();
}