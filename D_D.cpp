/*
  "Solve puzzles, write dreams, code greatness. Keep going, Nahin!"
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;
#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define fo(i, n) for(int i=0;i<n;i++)
#define ofo(i, n) for(int i=1;i<=n;i++)
#define rfo(i,n) for(int i=n-1;i>=0;i--)
#define setBit(n, i) (n  (1LL << i))
#define even(x) !(x&1)
#define odd(x) x&1
#define found(x,y) x.find(y)!=x.end()
#define notfound(x,y) x.find(y)==x.end()
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define MAX(a) *max_element(all(a))
#define MIN(a) *min_element(all(a))
#define UNIQUE(a) sort(all(a));a.erase(unique(all(a)),a.end())
#define lb_pos(a,x) lower_bound(all(a),x) - a.begin()
#define ub_pos(a,x) upper_bound(all(a),x) - a.begin()
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))
#define ha cout << "YES\n";
#define na cout << "NO\n";
#define gr goto read;
#define start() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void Ammu () {            cerr << endl;}
template < typename T, typename ... hello>void Ammu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}
ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }
ll digitalRoot (ll x)  { return (1 + (x-1)%9);}
const ll N = 1e5+555; ll dp[N];
ll binpow(ll base, ll exp, ll mod) {
ll res = 1;while(exp > 0){if(exp%2==1)res=res*base%mod;base=base * base % mod;exp /= 2;}return res;}

ll fact[N], invFact[N];
void precompute() {fact[0] = invFact[0] = 1;
    for (ll i = 1; i < N; i++) {
   fact[i] = fact[i-1] * i % MOD; invFact[i] = binpow(fact[i], MOD-2, MOD);}}

ll nCr(ll n, ll r) {if (r > n or r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;}

ll nPr(ll n,ll r){if (r > n or r < 0) return 0; else  return fact[n]*invFact[n-r]%MOD;}

bool is_prime(ll n){if(n<=1)return false; if(n<=3)return true; if(n%2==0 or n%3==0)return false;
for(ll i=5;i*i<=n;i+=6){ if(n%i==0 | n%(i+2)==0) return false;}return true;}

vector<ll>sieve(ll limit){vector<bool> is_prime(limit + 1, true);vector<ll>primes;
is_prime[0]=is_prime[1]=false;for(ll p=2;p<=limit;p++){if(is_prime[p]){primes.push_back(p);
for (ll i = p * p; i <= limit; i += p) {is_prime[i] = false;}}}return primes;}

map<ll,bool> vis;   map<ll,list<ll>> adj;  map<ll,ll> level,parent;
void addedge(ll v,ll w) {adj[v].PB(w);  adj[w].PB(v); }

void dfs(ll v) { vis[v]=true; for(auto x:adj[v]) { if(!vis[x]) dfs(x);}}
void bfs(ll start) {
    queue<ll> q;q.push(start);vis[start] = true;level[start] = 0;parent[start] = -1;
   while(!q.empty()) {ll v = q.front(); q.pop();
    for(auto x: adj[v]) {if(!vis[x]) { vis[x] = true; level[x] = level[v] + 1;  parent[x] = v;  q.push(x);}}}}

    vl shortest_path(ll start, ll end) {
    vl path; if(!vis[end]) return path; for(ll v = end; v != -1; v = parent[v]) {path.PB(v);}reverse(all(path)); return path;}

ll dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}; ll dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

int32_t main() {
    start();
   // precompute();
    ll tc; cin >> tc;
    read:
    while(tc--) {
    ll a,b,c,d,e,f,i,j,m,n,k,l,ans=0,res=0,cnt=0,cnt1=0,sum=0,t=1; bool ok = true; map<ll,ll>mp; string s1,s2,s3;
    cin>>n;   //vl v(n); //for(auto &x:v)cin>>x;
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(i==0)continue;
        if(s[0]=='1' and s[1]=='1' and s[2]=='1')res++;
        else if(s[0]=='1' and s[1]=='1' and s[2]=='0')ans++;
        else if(s[0]=='0' and s[1]=='1' and s[2]=='1')ans++;

    }
    if(ans==0 and res==0){
        cout<<"Nono\n";
        gr
    }
    if(res==0){
        if(ans%2==1)cout<<"Yesyes\n";
        else cout<<"Nono\n";
    }
    else
    {
        if(res%2==0 ){
             if(ans%2==1)cout<<"Yesyes\n";
             else cout<<"Nono\n";
        }
        else
            cout<<"Yesyes\n";

    }



    }
    return 0;
}