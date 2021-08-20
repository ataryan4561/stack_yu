#include<bits/stdc++.h>
using namespace std;
int MAH(vector<int> arr,int n)
{
    int ans=0;
    stack<pair<int,int>> st;
    stack<pair<int,int>> st1;
    vector<int> nsl;
    vector<int> nsr;
    for(int i=0; i<n; i++)
    {
        if(st.size()==0)
        {
            nsl.push_back(-1);
        }
        else if(st.size()>0 && st.top().first<arr[i])
        {
            nsl.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first>=arr[i])
        {
            while(st.size()>0 && st.top().first>=arr[i])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                nsl.push_back(-1);
            }
            else if(st.size()>0 && st.top().first<arr[i])
            {
                nsl.push_back(st.top().second);
            }
        }
         st.push({arr[i],i});
    }
    for(int i=n-1; i>=0; i--)
    {
        if(st1.size()==0)
        {
            nsr.push_back(-1);
        }
        else if(st1.size()>0 && st1.top().first<arr[i])
        {
            nsr.push_back(st1.top().second);
        }
        else if(st1.size()>0 && st1.top().first>=arr[i])
        {
            while(st1.size()>0 && st1.top().first>=arr[i])
            {
                st1.pop();
            }
            if(st1.size()==0)
            {
                nsr.push_back(-1);
            }
            else if(st1.size()>0 && st1.top().first<arr[i])
            {
                nsr.push_back(st1.top().second);
            }
        }
         st1.push({arr[i],i});
    }
    vector<int> nsr1;
    for(int i=n-1; i>=0; i--)
    {
        nsr1.push_back(nsr[i]);
    }
    // for(int i=0; i<n; i++)
    // {
    //     cout<<nsr1[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     cout<<nsl[i]<<" ";
    // }
    for(int i=0; i<n; i++)
    {
        if(nsl[i]==-1 && nsr[i]==-1)
        {
            // cout<<n*arr[i]<<" " <<arr[i]<<" ";
            ans=max(ans,n*arr[i]);
        }
        else if(nsl[i]==-1)
        {
            // cout<<nsr1[i]*arr[i]<<" "<<arr[i]<<"bdkd";
            ans=max(ans,nsr1[i]*arr[i]);
        }
        else if(nsr1[i]==-1)
        {
            // cout<<(n-(nsl[i]+1))*arr[i]<<" -3-3-3-3";
            ans=max(ans,(n-(nsl[i]+1))*arr[i]);
        }
        else 
        {
            // cout<<(nsr1[i]-nsl[i]-1)*arr[i]<<" -4-4-4-4";
            // cout<<"hello"<<endl;
            ans=max(ans,(nsr1[i]-nsl[i]-1)*arr[i]);
        }
    }
    return ans;
}
int main()
{
     int n,m;
    cin>>n>>m;
    vector<vector<int>> what(n,vector<int> (m,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>what[i][j];
        }
    }
    vector<int> v(m,0);
    int realans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(what[i][j]==0)
            {
                v[j]=0;
            }
            else 
            {
                v[j]=v[j]+what[i][j];
            }
        }
        // int f=MAH(v,m);
        // cout<<f<<endl;
        // for(int k=0; k<m; k++)
        // {
        //     cout<<v[k];
        // }
        realans=max(realans,MAH(v,m));
    }
    cout<<realans<<endl;
}