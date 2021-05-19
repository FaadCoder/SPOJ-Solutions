#include<bits/stdc++.h>
#define ll long long int
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define takeInput freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
using namespace std;

bool check(vector<ll> &v,ll mid,ll cows)
{
    ll cowsPlaced = 1;
    ll lastPos = v[0];
    for(ll i=1;i<(ll)v.size();i++)
    {
        if(v[i]-lastPos>=mid)
        {
            if(++cowsPlaced == cows)
                return true;
            lastPos = v[i];
        }
    }
    return false;
}

void performBinarySearch(vector<ll> &v,ll &ans,ll c)
{
    ll start = 0;
    ll end = v.back();
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        if(check(v,mid,c))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}

int main()
{
    fastIO;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        vector<ll> v(n);
        for(auto &element:v)
            cin>>element;
        sort(v.begin(),v.end());
        ll ans=0;
        performBinarySearch(v,ans,c);
        cout<<ans<<endl;
    }
}
