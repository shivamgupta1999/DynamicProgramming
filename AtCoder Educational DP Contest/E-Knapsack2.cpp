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
    ll n,w;
    cin >> n >> w;
    ll wg[n], v[n], sum = 0;
    fl(i,n){
        cin >> wg[i] >> v[i];
        sum += v[i];
    }
    ll dp[n][sum + 1];

    fl(i,n){
        fl(j,sum+1){
            if(j == 0) {
				dp[i][j] = 0;
				continue;
			}

            dp[i][j] = INF;
            if(i == 0) {
                if(j == v[i])
				dp[i][j] = wg[i];
				continue;
			}

            if(j < v[i]) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = min(dp[i - 1][j - v[i]] + wg[i], dp[i - 1][j]);
			}
        }
    }
    ll result;
	for(int i = sum; i >= 0; i--) {
		if(dp[n - 1][i] <= w) {
			result = i;
			break;
		}
	}
    cout << result << endl;
}
