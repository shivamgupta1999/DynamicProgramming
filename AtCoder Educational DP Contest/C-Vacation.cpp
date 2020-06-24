//Shivam gupta (Codeforces handle : shivam_1999)

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define ld long double
typedef vector<long long> vi;
typedef vector<vi> vvi;
typedef pair<long long, long long> pii;
typedef vector<pair<long long, long long>> vpii;
typedef map<long long, long long> mii;
#define pb push_back
#define mp make_pair
#define endl '\n'
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(x) x.begin(), x.end()
#define sorta(x) sort(x.begin(),x.end())
#define sortd(v) sort(all(v), greater<ll>())
#define el cout << endl;
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define cpresent(container, element) (find(all(container), element) != container.end())
#define deb(x) cout << #x << x << endl;
#define fl(i,n) for(ll i=0;i<n;i++)
#define fls(i,x,n) for(ll i=x;i<n;i++)
#define flr(i,n)  for(ll i=n-1;i>=0;i--)
#define fla(i,v)  for(auto i:v)    
#define in(v) for(auto &i:v){cin>>i;}
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define tt    \
    int T;    \
    cin >> T; \
    while (T--)

int main()
{   fast
    ll n;
    cin >> n;
    vi a(n),b(n),c(n);
    fl(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    ll dp[n][3];
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    fls(i,1,n){
        fl(j,3){
            if (j == 0)
                dp[i][j] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
            if (j == 1)
                dp[i][j] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
            if (j == 2)
                dp[i][j] = max(dp[i - 1][1], dp[i - 1][0]) + c[i];
        }
    }
    cout << max3(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]) << endl;
}