#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<long long int> v;
    for(int i=0;i<n;i++)
    {
        int t;cin>>t;
        v.push_back(t);
    }
    
    stack<long long int> s;//单调栈
    vector<int> R(n,n-1);

    //从左向右找
    for(int i=0;i<n;i++)
    {
        while(!s.empty()&&v[s.top()]>v[i])
        {//栈首的下标temp对应的元素大于当前元素，说明temp的最右元素就是当前元素
            R[s.top()]=i-1;
            s.pop();
            if(s.empty())
                break;
        }
        s.push(i);
    }
    while(s.size())
    {
        R[s.top()]=n-1;
        s.pop();
    }

    stack<long long int> ss;
    vector<long long int> L(n,0);
    for(int i=n-1;i>=0;i--)
    {
        while(!ss.empty()&&v[ss.top()]>v[i])
        {
            L[ss.top()]=i+1;
            ss.pop();
            if(ss.empty())
                break;
        }
        ss.push(i);
    }
    while(ss.size())
    {
            L[ss.top()]=0;
            ss.pop();
    }

    long long int ans=0;
    for(int i=0;i<n;i++)
    {
        //cout<<"L["<<i<<"]"<<L[i]<<endl;
        //cout<<"R["<<i<<"]"<<R[i]<<endl;
        long long int cur=(R[i]-L[i]+1)*v[i];
        if(cur>ans) ans=cur;
    }
    cout<<ans;
    //return 0;
}