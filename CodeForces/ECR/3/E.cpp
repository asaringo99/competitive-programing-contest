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
#define repi(it,S) for(auto it = S.begin() ; it != S.end() ; it++)
#define pt(a) cout << a << endl
#define DEBUG(...) ; cout << #__VA_ARGS__ << endl ; for(auto x : {__VA_ARGS__}) cout << x << "  " ; cout << endl ;
#define DEBUG_LIST(...) cout << #__VA_ARGS__ << endl ; DEBUG_REP(__VA_ARGS__) ;
#define DEBUG_REP(V) cout << "{ " ; repi(itr,V) cout << *itr << ", " ; cout << "}" << endl ;
#define debug(a) cout << #a << " " << a << endl
#define all(a) a.begin(), a.end()
#define endl "\n"

template<typename Key,typename Val>
struct hash_map{
    using u32=uint32_t;
    using u64=uint64_t;
    using Data=pair<Key,Val>;
    protected:
        template <typename K>
        inline u64 randomized(const K&key)const{
            return u64(key)^r;
        }
    template<typename K,enable_if_t<is_integral<K>::value,nullptr_t> = nullptr>
    inline u64 inner_hash(const K&key)const{
        return (randomized(key)*11995408973635179863ULL);
    }
    template<typename K,enable_if_t<is_integral<decltype(K::first)>::value,nullptr_t> = nullptr,enable_if_t<is_integral<decltype(K::second)>::value,nullptr_t> = nullptr>
        inline u64 inner_hash(const K&key)const{
            u64 a=randomized(key.first),b=randomized(key.second);
            a*=11995408973635179863ULL;
            b*=10150724397891781847ULL;
            return (a+b);
    }
    template <typename K,enable_if_t<is_integral<typename K::value_type>::value,nullptr_t> = nullptr>
    inline u64 inner_hash(const K&key)const{
        static constexpr u64 mod=(1LL << 61)-1;
        static constexpr u64 base=950699498548472943ULL;
        u64 res=0;
        for(auto&elem:key) {
            __uint128_t x=__uint128_t(res)*base+(randomized(elem)&mod);
            res=(x&mod)+(x>>61);
        }
        __uint128_t x=__uint128_t(res)*base;
        res=(x&mod)+(x >> 61);
        if(res>=mod)res-=mod;
        return (res<<3);
    }
    inline u32 hash(const Key&key)const{
        return inner_hash(key)>>shift;
    }
    void reallocate(u32 new_cap){
        vector<Data>new_data(new_cap);
        vector<bool>new_flag(new_cap,false);
        shift=64-__lg(new_cap);
        for(u32 i=0;i<cap;i++){
            if(flag[i]&&!dflag[i]){
                u32 h=hash(data[i].first);
                while(new_flag[h])h=(h+1)&(new_cap-1);
                new_data[h]=move(data[i]);
                new_flag[h]=true;
            }
        }
        data.swap(new_data);
        flag.swap(new_flag);
        cap=new_cap;
        dflag.resize(cap);
        fill(dflag.begin(),dflag.end(),false);
    }
    inline bool should_extend(u32 x)const{return x*2>=cap;}
    inline bool should_shrink(u32 x)const{return 4<cap&&x*10<=cap;}
    inline void extend(){reallocate(cap<<1);}
    inline void shrink(){reallocate(cap>>1);}
    public:
    u32 cap,s;
    vector<Data>data;
    vector<bool>flag,dflag;
    u32 shift;
    static u64 r;
    static constexpr uint32_t DEFAULT_SIZE=4;
    struct iterator{
        u32 i;
        hash_map<Key,Val>*p;
        explicit constexpr iterator():i(0),p(nullptr){}
        explicit constexpr iterator(u32 i,hash_map<Key,Val>*p):i(i),p(p){}
        explicit constexpr iterator(u32 i,const hash_map<Key,Val>*p):i(i),p(const_cast<hash_map<Key,Val>*>(p)){}
        const Data& operator*()const{
            return const_cast<hash_map<Key,Val>*>(p)->data[i];
        }
        Data& operator*(){return p->data[i];}
        Data* operator->(){return &(p->data[i]);}
        friend void swap(iterator&a,iterator&b){swap(a.i,b.i);swap(a.p,b.p);}
        friend bool operator==(const iterator&a,const iterator&b){return a.i==b.i;}
        friend bool operator!=(const iterator&a,const iterator&b){return a.i!=b.i;}
        iterator& operator++(){
        assert(i!=p->cap&&"iterator overflow");
        do{
            i++;
            if(i==p->cap)break;
            if(p->flag[i]&&!(p->dflag[i]))break;
        } while(true);
        return *this;
        } 
        iterator operator++(int){
            iterator tmp(*this);
            ++(*this);
            return tmp;
        }
        iterator& operator--(){
            do{
                i--;
                if(p->flag[i]&&!(p->dflag[i]))break;
                assert(i!=0&&"iterator underflow");
            } while(true);
            return *this;
        }
        iterator operator--(int){
            iterator tmp(*this);
            --(*this);
            return tmp;
        }
    };
    using itr=iterator;
    explicit hash_map():cap(DEFAULT_SIZE),s(0),data(cap),flag(cap),dflag(cap),shift(62){}
    itr begin()const{
        u32 h=0;
        while(h!=cap){
            if(flag[h]&&!dflag[h])break;
            h++;
        }
        return itr(h,this);
    }
    itr end()const{return itr(this->cap,this);}    
    friend itr begin(hash_map<Key,Val>&a){return a.begin();}
    friend itr end(hash_map<Key,Val>&a){return a.end();}
    itr find(const Key&key)const{
        u32 h=hash(key);
        while(true){
            if(!flag[h])return this->end();
            if(data[h].first==key){
                if(dflag[h])return this->end();
                return itr(h,this);
            }
            h=(h+1)&(cap-1);
        }
    }
    bool contain(const Key&key)const{return find(key)!=this->end();}
    int count(const Key&key)const{return int(find(key)!=this->end());}
    itr insert(const Data&d){
        u32 h=hash(d.first);
        while(true){
            if(!flag[h]){
                if(should_extend(s+1)){
                    extend();
                    h=hash(d.first);
                    continue;
                }
                data[h]=d;
                flag[h]=true;
                s++;
                return itr(h,this);
            }
            if(data[h].first==d.first){
                if(dflag[h]){
                    data[h]=d;
                    dflag[h]=false;
                    s++;
                }
                return itr(h,this);
            }
            h=(h+1)&(cap-1);
        }
    }
    bool erase(itr it){
        if(it==this->end())return false;
        s--;
        if(should_shrink(s)){
            Data d=data[it.i];
            shrink();
            it=find(d.first);
        }
        int ni=(it.i+1)&(cap-1);
        if(flag[ni]){
            dflag[it.i]=true;
        }
        else{
            flag[it.i]=false;
        }
        return true;
    }
    bool erase(const Key&key){return erase(find(key));}
    bool empty()const{return s==0;}
    u32 size()const{return s;}
    void clear(){
        s=0;
        fill(flag.begin(),flag.end(),false);
        fill(dflag.begin(),dflag.end(),false);
    }
    void reserve(int n){
        if(n<=0)return;
        n=1<<(__lg(n)+2);
        if(cap<u32(n))reallocate(n);
    }
    Val& operator[](const Key&key){
        u32 h=hash(key);
        while(true){
            if(!flag[h]){
                if(should_extend(s+1)){
                    extend();
                    h=hash(key);
                    continue;
                }
                data[h]=Data(key,Val());
                flag[h]=true;
                s++;
                return data[h].second;
            }
            if(data[h].first==key){
                if(dflag[h])data[h].second=Val();
                return data[h].second;
            }
            h=(h+1)&(cap-1);
        }
    }
    bool emplace(const Key&key,const Val&val){
        return insert(Data(key,val));
    }
};
template<typename Key,typename Val>uint64_t hash_map<Key,Val>::r=chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();

struct UnionFind {
    private:
        vector<int> par ; //親
        vector<int> lank ; //木の深さ
        vector<int> volume ; //構成する集合のサイズ
        vector<int> edge ; //構成する集合の辺の数

    public:
        UnionFind(int n){
            //n要素で初期化
            par.resize(n) ;
            lank.resize(n) ;
            volume.resize(n) ;
            edge.resize(n) ;
            for(int i = 0 ; i < n ; i++){
                par[i] = i ;
                lank[i] = 0 ;
                volume[i] = 1 ;
                edge[i] = 0 ;
            }
        }
        //木の根を求める
        int root(int x) {
            if(par[x] == x) return x ;
            else return par[x] = root(par[x]) ;
        }

        //xとyの属する集合を合併
        void unite(int x , int y){
            x = root(x);
            y = root(y) ;
            if(x == y) {
                edge[x]++ ;
                return ;
            }
            if(lank[x] < lank[y]){
                par[x] = y ;
                volume[y] += volume[x] ;
                edge[y] += edge[x] + 1 ;
            } else {
                par[y] = x ;
                volume[x] += volume[y] ;
                edge[x] += edge[y] + 1 ;
                if(lank[x] == lank[y]) lank[x]++ ;
            }
        }

        bool same(int x , int y) { return root(x) == root(y) ; }
        int size(int x) { return volume[root(x)] ; }
        int edge_num(int x) { return edge[root(x)] ; }
};

unordered_set<int> st;
vector<tuple<ll,int,int,int>>  E, F, G, H;

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<int> ans(n);
    rep(i,m){
        int u , v ,w;
        cin >> u >> v >> w;
        u-- ; v-- ;
        E.push_back({w,u,v,i});
    }
    F = E;
    sort(all(E));
    UnionFind uf(n);
    ll res = 0;
    rep(i,m){
        auto[w,v,u,id] = E[i];
        if(uf.same(u,v)) {
            G.push_back({w,v,u,id});
            continue;
        }
        H.push_back({w,u,v,id});
        uf.unite(v,u);
        st.insert(id);
        res += w;
    }
    rep(i,m){
        if(st.count(i)) ans[i] = res;
    }
    UnionFind ufd(n);
    int j = 0;
    rep(i,G.size()){
        auto[val,a,b,idx] = G[i];
        ufd.unite(a,b);
        while(j < H.size()){
            auto[w,u,v,id] = H[j++];
            if(ufd.same(u,v)) {
                ans[idx] = res + abs(w-val);
                break;
            }
        }
    }
}

int main(){
    fast_io
    solve();
} 