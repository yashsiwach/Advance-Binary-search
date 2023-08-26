#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << x << " ";
//6 7 8 4 3 
//0 0 1 1 1
//calculate the lower bound now after converting 
bool check(vector<int>& v, int mid)
{
    //main condition
    if(mid==v.size()-1) return 1;
    if (v[mid] > v[mid+1])
    {
        return true;
    }
    return false;
}

int solve(vector<int>& v,  int anstemp)
{
    int l = 0, h = v.size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(v, mid))
        {
            anstemp = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    clock_t time_req = clock();

    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    

    int anstemp = -1;
    int ans = solve(v, anstemp);
    cout<<ans;
    

#ifndef ONLINE_JUDGE
    cout << endl
         << "Time: " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
#endif
}