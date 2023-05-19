#include <bits/stdc++.h>
using namespace std ;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
typedef long long ll ;
typedef long double ld ;
typedef pair<ll,ll> P ;
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
using TP = tuple<ll,int,int>;

const int mod = 1000000007 ;

void solve(){
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    sort(all(A));
    rep(i,n){
        if(A.size() == 1) break;
        set<pair<int,int>> st;
        priority_queue<TP,vector<TP>,greater<TP>> que;
        que.push({A[0]+A[1],0,1});
        vector<ll> vec;
        int m = A.size();
        int cnt = 0;
        while(cnt < n - i - 1){
            auto[a,x,y] = que.top(); que.pop();
            vec.push_back(a);
            st.insert({x,y});
            cnt++;
            if(x > y) swap(x,y);
            if(y+1<m) {
                if(st.count({x,y+1})) continue;
                que.push({A[x]+A[y+1],x,y+1});
            }
            if(x+1==y) x++, y++;
            if(y<m) {
                if(st.count({x,y})) continue;
                que.push({A[x]+A[y],x,y});
            }
        }
        A = vec;
    }
    cout << A[0] % mod << endl;
}

int main(){
    fast_io
    solve();
}