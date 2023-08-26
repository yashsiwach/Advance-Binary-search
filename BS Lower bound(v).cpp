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

bool check(vector<int>& v, int mid,int target)
{
    //main change in if condition
    if (v[mid] == target)
    {
        return true;
    }
    return false;
}

int solve(vector<int>& v, int target, int anstemp)
{
    int l = 0, h = v.size() - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(v, mid,target))
        {
            //store the ans if 1 and search in left part tooo
            anstemp = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (anstemp != -1 && v[anstemp] == target)
    {
        return anstemp;
    }
    else
    {
        return -1; 
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

    int target;
    cin >> target;

    int anstemp = -1;
    int ans = solve(v, target, anstemp);
    if (ans == -1)
    {
        cout << "Element not found";
    }
    else
    {
        cout << ans;
    }

#ifndef ONLINE_JUDGE
    cout << endl
         << "Time: " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
#endif
}