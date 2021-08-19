// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate span of stock’s price for all n days.
// The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
// {100, 80, 60, 70, 60, 75, 85}
// {1, 1, 1, 2, 1, 4, 6}
#include<bits/stdc++.h>
#include<stack>
using namespace std;
int getpos(vector<int> arr,int ele)
{
    int c=0;
    for(auto i : arr)
    {
        if(i==ele)
        {
            return c;
        }
        c++;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    stack<int> st;
    // int pop=0;
    for(int i=0; i<n; i++)
    {
        if(st.size()==0)
        {
            ans.push_back(1);
        }
        else if(st.size()>0 && st.top()>arr[i])
        {
            ans.push_back(1);
        }
        else if(st.size()>0 && st.top()<=arr[i])
        {
            // int count=1;
            while(st.size()>0 && st.top()<=arr[i])
            {
                st.pop();
                // pop++;
                // count++;
            }
            int fu=getpos(arr,st.top());
            ans.push_back(i-fu);
        }
        st.push(arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}