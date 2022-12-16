// Himanshu Pandey

#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

//--------------------------------------------------------------------------------------------------------------------------
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
//--------------------------------------------------------------------------------------------------------------------------
int main(){
    vector<vector<long long int>>mon;
    vector<long long int>v1 = {50, 70, 54, 83, 52, 78}, v2 = {71, 52, 58, 60, 71}, v3 = {66, 56, 56, 94, 60, 86, 73}, v4 = {83, 99}, v5 = {98, 98, 79}, v6 = {76}, v7 = {52, 51, 84, 54}, v8 = {82, 86, 91, 79, 94, 92, 59, 94};
    mon.pb(v1);
    mon.pb(v2);
    mon.pb(v3);
    mon.pb(v4);
    mon.pb(v5);
    mon.pb(v6);
    mon.pb(v7);
    mon.pb(v8);
    
    // for(auto it : mon){
    //     for(auto itt: it){
    //         cout << itt << ", ";
    //     }
    //     cout << "\n";
    // }
    long long modulo = 11*7*3*5*17*13*19*2;
    vector<long long int> cnt(8,0);

    for(long long int i = 0; i<10000; i++){
        for(long long int j = 0; j<8; j++){
            if(j==0){
                while(mon[j].size()>0){
                    long long int num = mon[j][mon[j].size()-1];
                    mon[j].pop_back();
                    //num%=modulo;
                    cnt[j]++;
                    num = num*3;
                    //num/=3;
                    num%=modulo;
                    if(num%11==0)mon[2].pb(num);
                    else mon[7].pb(num);
                }
            }

            if(j==1){
                while(mon[j].size()>0){
                    long long int num = mon[j][mon[j].size()-1];
                    cnt[j]++;
                    //num%=modulo;
                    mon[j].pop_back();
                    num = num*num;
                    num%=modulo;
                    //num/=3;
                    if(num%7==0)mon[0].pb(num);
                    else mon[2].pb(num);
                }
            }

            if(j==2){
                while(mon[j].size()>0){
                    long long int num = mon[j][mon[j].size()-1];
                    cnt[j]++;
                    mon[j].pop_back();
                    //num%=modulo;
                    num = num + 1;
                    num%=modulo;
                    //num/=3;
                    if(num%3==0)mon[7].pb(num);
                    else mon[5].pb(num);
                }
            }

            if(j==3){
                while(mon[j].size()>0){
                    long long int num = mon[j][mon[j].size()-1];
                    cnt[j]++;
                    mon[j].pop_back();
                    //num%=modulo;
                    num = num + 8;
                    num%=modulo;
                    //num/=3;
                    if(num%5==0)mon[6].pb(num);
                    else mon[4].pb(num);
                }
            }

            if(j==4){
                while(mon[j].size()>0){
                    long long int num = mon[j][mon[j].size()-1];
                    cnt[j]++;
                    mon[j].pop_back();
                    //num%=modulo;
                    num = num + 3;
                    num%=modulo;
                    //num/=3;
                    if(num%17==0)mon[1].pb(num);
                    else mon[0].pb(num);
                }
            }

            if(j==5){
                while(mon[j].size()>0){
                    long long int num = mon[j][mon[j].size()-1];
                    cnt[j]++;
                    mon[j].pop_back();
                    //num%=modulo;
                    num = num + 4;
                    num%=modulo;
                    //num/=3;
                    if(num%13==0)mon[6].pb(num);
                    else mon[3].pb(num);
                }
            }

            if(j==6){
                while(mon[j].size()>0){
                    long long int num = mon[j][mon[j].size()-1];
                    cnt[j]++;
                    mon[j].pop_back();
                    //num%=modulo;
                    num = num*17;
                    num%=modulo;
                    //num/=3;
                    if(num%19==0)mon[4].pb(num);
                    else mon[1].pb(num);
                }
            }

            if(j==7){
                while(mon[j].size()>0){
                    long long int num = mon[j][mon[j].size()-1];
                    cnt[j]++;
                    mon[j].pop_back();
                    //num%=modulo;
                    num = num + 7;
                    num%=modulo;
                    //num/=3;
                    if(num%2==0)mon[5].pb(num);
                    else mon[3].pb(num);
                }
            }
        }
    }
    sort(cnt.rbegin(), cnt.rend());
    cout << cnt[0]*cnt[1] << endl;
    

}