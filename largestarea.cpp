#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main()
{
    //MAH
    vector<int> ansnsl;
    vector<int> ansnsr;
    stack<pair<int,int>> st;
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    } 
    for(int i=0; i<n; i++)
    {
        if(st.size()==0)
        {
            ansnsl.push_back(-1);
        }
        else if(st.size()>0 && st.top().first<arr[i])
        {
            ansnsl.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first>=arr[i])
        {
            while(st.size()>0 && st.top().first>=arr[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                ansnsl.push_back(-1);
            }
            else if(st.size()>0 && st.top().first<arr[i])
            {
                ansnsl.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});
    }
    stack<pair<int,int>> st1;
    for(int i=n-1; i>=0; i--)
    {
        if(st1.size()==0)
        {
            ansnsr.push_back(-1);
        }
        else if(st1.size()>0 && st1.top().first<arr[i])
        {
            ansnsr.push_back(st1.top().second);
        }
        else if(st1.size()>0 && st1.top().first>=arr[i])
        {
            while(st1.size()>0 && st1.top().first>=arr[i])
            {
                st1.pop();
            }
            if(st1.size()==0)
            {
                ansnsr.push_back(-1);
            }
            else if(st1.size()>0 && st1.top().first<arr[i])
            {
                ansnsr.push_back(st1.top().second);
            }
        }
        st1.push({arr[i],i});
    }
    vector<int> ansnsr1;
    for(int i=n-1; i>=0; i--)
    {
        ansnsr1.push_back(ansnsr[i]);
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(ansnsl[i]==-1 && ansnsr1[i]==-1)
        {
            ans=max(ans,n*arr[i]);
            // cout<<ans<<"hello";
        }
        else if(ansnsl[i]==-1)
        {
            ans=max(ans,(ansnsr1[i]*arr[i]));
            // cout<<ans<<"hello1";
        }
        else if(ansnsr1[i]==-1)
        {
            ans=max(ans,(n-(ansnsl[i]+1))*arr[i]);
            // cout<<ans<<"hello3";
        }
        else
        {
            ans=max(ans,(ansnsr1[i]-ansnsl[i]-1)*arr[i]);
        }
    }
    cout<<ans;
    cout<<endl;
}