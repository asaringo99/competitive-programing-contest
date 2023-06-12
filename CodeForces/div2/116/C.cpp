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
    vector<vector<int>> A(m);
    vector<int> B(n+10, -1);
    rep(i,m){
        int k;
        cin >> k;
        rep(j,k){
            int x;
            cin >> x;
            x--;
            B[x] = j;
            A[i].push_back(x);
        }
    }

    vector<pair<int,int>> res;
    int now = 0;
    int sum = 0;
    rep(p,m){
        now = p;
        rep(z,A[p].size()){
            bool empty = false;
            if(B[sum] == -1) empty = true;
            if(B[sum] == now) continue;
            if(empty){
                rrep(i,sum+1,n){
                    if(B[i] == now){
                        res.push_back({i,sum});
                        B[i] = -1;
                        break;
                    }
                }
            }
            else{
                int pos = -1, epos = -1;
                rrep(i,sum+1,n){
                    if(B[i] == -1) epos = i;
                    if(B[i] == now) pos = i;
                }
                res.push_back({sum,epos});
                res.push_back({pos,sum});
                B[pos] = -1;
            }
            sum++;
        }
    }
    cout << res.size() << endl;
    for(auto[x,y]: res) cout << x + 1 << " " << y + 1 << endl;
}

int main(){
    // fast_io
    solve();
}