#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
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
#define endl "\n"

struct Compress{
    vector<int> vec ; // 元の値の座標圧縮後の値
    unordered_map<int,int> mp ; // 元の値がどの値に変換されたか
    Compress(vector<int> A){
        int n = A.size() ;
        vector<int> B(n) ;
        for(int i = 0 ; i < n ; i++) B[i] = A[i] ;
        vec.resize(n) ;
        sort(A.begin(),A.end()) ;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(A.begin(),A.end(),B[i]) ;
            vec[i] = it - A.begin() ;
            mp[B[i]] = it - A.begin();
        }
    }
    size_t size() {return vec.size() ; }
    inline int at(ll i) { return mp[i] ; }
    inline int operator [] (int i) { return vec[i] ; }
};

int n , q ;
ll A[202020] , B[202020] ;
int mpa[505050] , mpb[505050] ;
bool useda[505050] , usedb[505050] ;
set<int> st ;
bool res[202020] ;

vector<TP> vec[500] ;

int main(){
    fast_input_output
    cin >> n ;
    vector<int> vvv ;
    rep(i,n) cin >> A[i] , vvv.push_back(A[i]) ;
    rep(i,n) cin >> B[i] , vvv.push_back(B[i]) ;
    Compress ccc(vvv) ;
    rep(i,n) A[i] = ccc.at(A[i]) ;
    rep(i,n) B[i] = ccc.at(B[i]) ;

    cin >> q ;
    rep(i,q){
        int x , y ;
        cin >> x >> y ;
        vec[x/447].push_back({y,x,i}) ;
    }
    rep(i,500) sort(vec[i].begin(),vec[i].end()) ;
    int ok = 0 ;
    int lef = 0 , rig = 0 ;
    rep(i,450){
        for(TP tp : vec[i]){
            auto [rv,lv,id] = tp ;
            int k = id ;
            while(rig < rv){
                mpb[B[rig]]++ ;
                if(!usedb[B[rig]] && !useda[B[rig]]) ok++ ;
                if(!usedb[B[rig]] && useda[B[rig]]) ok-- ;
                usedb[B[rig]] = true ;
                rig++ ;
            }
            while(rig > rv){
                rig-- ;
                mpb[B[rig]]-- ;
                if(mpb[B[rig]] == 0){
                    usedb[B[rig]] = false ;
                    if(useda[B[rig]]) ok++ ;
                    if(!useda[B[rig]]) ok-- ;
                }
            }
            while(lef < lv){
                mpa[A[lef]]++ ;
                if(!useda[A[lef]] && !usedb[A[lef]]) ok++ ;
                if(!useda[A[lef]] && usedb[A[lef]]) ok-- ;
                useda[A[lef]] = true ;
                lef++ ;
                // cout << useda[A[lef]] << " " << usedb[A[lef]] << endl ;
                // cout << ok << endl ;
            }
            while(lef > lv){
                lef-- ;
                mpa[A[lef]]-- ;
                if(mpa[A[lef]] == 0){
                    useda[A[lef]] = false ;
                    if(usedb[A[lef]]) ok++ ;
                    if(!usedb[A[lef]]) ok-- ;
                }
            }
            // cout << ok << " " << id << " " << lv << " " << rv << endl ;
            if(ok == 0) res[k] = true ;
            else res[k] = false ;
        }
    }
    rep(i,q) {
        if(res[i]) cout << "Yes" << endl ;
        else cout << "No" << endl ;
    }
}