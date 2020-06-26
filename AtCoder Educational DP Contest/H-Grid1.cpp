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
#define INF 1e9+1
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
    int h,w;
    cin >> h >> w;
    int dp[h + 1][w + 1];
    char a[h + 1][w + 1];
    fls(i,1,h+1){
        fls(j,1,w+1){
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }
    dp[1][1] = 1;
    fls(i,2,h+1){
        if(a[i][1]=='#')
            break;
        if(a[i-1][1]=='.'&&a[i][1]=='.')
            dp[i][1] = 1;
    }
    fls(i,2,w+1){
        if(a[1][i]=='#')
            break;
        if(a[1][i-1]=='.'&&a[1][i]=='.')
            dp[1][i] = 1;
    }
    fls(i,2,h+1){
        fls(j,2,w+1){
            if(a[i][j]=='.')
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%mod;
        }
    }
    cout << dp[h][w] << endl;
}
