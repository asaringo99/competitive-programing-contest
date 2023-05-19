#include <bits/stdc++.h>
using namespace std ;
#define fast_input_output ios::sync_with_stdio(false); cin.tie(nullptr);
typedef long long ll ;
typedef long double ld ;
typedef pair<char,ll> P ;
typedef tuple<ll,ll,ll> TP ;
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define bit_count(x) __builtin_popcountll(x)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a / gcd(a,b) * b
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i,a,b) for(int i = a ; i < b ; i++)
#define endl "\n"

string S , T ;
int n , m ;

template<typename T>
struct RunLengthCompression {
    private:
        vector<pair<T,int>> res ;
        vector<T> A_ , A ;
        int n ;
        void build_(){
            A.resize(n+1) ;
            for(int i = 0 ; i < n ; i++) A[i] = A_[i] ;
            int cnt = 1 ;
            for(int i = 0 ; i < n ; i++){
                if(A[i] == A[i+1]) cnt++ ;
                else{
                    res.push_back(pair<T,int>(A[i],cnt)) ;
                    cnt = 1 ;
                }
            }
        }
    public:
        RunLengthCompression(vector<T> _A): A_(_A), n(_A.size()) {} ;
        void build() { build_() ; }
        vector<pair<T,int>> get_RLC() { return res ; }
};

int main(){
    fast_input_output
    string s , t ;
    vector<char> S , T ;
    cin >> s >> t ;
    for(char u : s) S.push_back(u) ;
    for(char u : t) T.push_back(u) ;
    RunLengthCompression<char> A(S) , B(T) ;
    A.build() ;
    B.build() ;
    vector<pair<char,int>> vec_s = A.get_RLC() ;
    vector<pair<char,int>> vec_t = B.get_RLC() ;
    n = vec_s.size() ;
    m = vec_t.size() ;
    if(n != m){
        cout << "No" << endl ;
        return 0 ;
    }
    rep(i,n){
        auto [sc,sn] = vec_s[i] ;
        auto [tc,tn] = vec_t[i] ;
        if(sc != tc){
            cout << "No" << endl ;
            return 0 ;
        }
        if(sn != tn && sn == 1){
            cout << "No" << endl ;
            return 0 ;
        }
        if(sn != tn && tn == 1){
            cout << "No" << endl ;
            return 0 ;
        }
        if(sn > tn){
            cout << "No" << endl ;
            return 0 ;
        }
    }
    cout << "Yes" << endl ;
}