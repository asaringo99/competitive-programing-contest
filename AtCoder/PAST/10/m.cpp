#include <bits/stdc++.h>
using namespace std ;
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

template<typename T , int MAX_BIT>
struct BinaryTrie {
    private:
        BinaryTrie *nxt[2] ;
        BinaryTrie *root ;
        T lazy ;
        int exist ;
        int duplicate ;
        vector<int> accept ;


        void push(const T &bit, int bit_index, int id, bool dupe = false) {
            if(bit_index == -1) {
                exist++ ;
                if(dupe) duplicate++ ;
                accept.push_back(id) ;
            }
            else {
                auto &to = nxt[bit >> bit_index & 1] ;
                if(!to) to = new BinaryTrie() ;
                int i = bit_index - 1 ;
                to->push(bit, i, id, dupe) ;
                exist++ ;
                if(dupe) duplicate++ ;
            }
        }

        void erase(const T &bit, int bit_index, bool dupe = false) {
            if(bit_index == -1) {
                exist-- ;
                if(dupe) duplicate-- ;
            }
            else {
                nxt[bit >> bit_index & 1]->erase(bit, bit_index - 1) ;
                exist-- ;
                if(dupe) duplicate-- ;
            }
        }

        int64_t count_less(const T &bit, int bit_index) {
            if(bit_index == -1) return 0 ;
            int64_t ret = 0 ;
            if(bit >> bit_index & 1) {
                if(nxt[0]) ret += nxt[0]->size() ;
                if(nxt[1]) ret += nxt[1]->count_less(bit, bit_index - 1) ;
            }
            else {
                if(nxt[0]) ret += nxt[0]->count_less(bit, bit_index - 1) ;
            }
            return ret ;
        }

        pair<T, BinaryTrie *> kth_element(int64_t k, int bit_index) {
            if(bit_index == -1) return {0, this} ;
            if((nxt[0] ? nxt[0]->size() : 0) <= k) {
                auto ret = nxt[1]->kth_element(k - (nxt[0] ? nxt[0]->size() : 0), bit_index - 1) ;
                ret.first |= T(1) << bit_index ;
                return ret ;
            }
            else return nxt[0]->kth_element(k, bit_index - 1) ;
        }

    public:
        BinaryTrie() : lazy(0) , exist(0) , nxt{nullptr, nullptr}, root(this) {}
        void push(const T &bit) { push(bit, MAX_BIT, exist) ; }
        void erase(const T &bit) { erase(bit, MAX_BIT) ; }
        pair<T, BinaryTrie *> kth_element(int64_t k) { return kth_element(k, MAX_BIT) ; }
        T get_kth(int64_t k) { return kth_element(k, MAX_BIT).first ; }
        int64_t count_less(const T &bit) { return count_less(bit, MAX_BIT) ; }
        size_t size() const { return exist ; }
};

int n , q ;
ll A[505050] ;
unordered_map<int,int> mp ;

int main(){
    BinaryTrie<int,31> V ;
    cin >> n >> q ;
    rep(i,n) {
        cin >> A[i] ;
        mp[A[i]] = i ;
        V.push(A[i]) ;
    }
    rep(i,q){
        int t ;
        cin >> t ;
        if(t == 1){
            int a , x ;
            cin >> a >> x ;
            a-- ;
            int b = A[a] ;
            V.erase(b) ;
            V.push(x) ;
            A[a] = x ;
            mp[x] = a ;
        }
        if(t == 2){
            int a ;
            cin >> a ;
            a-- ;
            int x = A[a] ;
            int cnt = V.count_less(x) ;
            cout << n - cnt << endl ;
        }
        if(t == 3){
            int r ;
            cin >> r ;
            int v = V.get_kth(n-r) ;
            cout << mp[v] + 1 << endl ;
        }
    }
}