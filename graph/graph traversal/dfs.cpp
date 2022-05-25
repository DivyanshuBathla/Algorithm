/******************************************************************************



#include <iostream>
#include<vector>
using namespace std;
void adjancedlist(vector<int> *v,int src,int des)
{
    
    v[src].push_back(des);
    v[des].push_back(src);
}
/*Stack is used in DFT but we are not using any stack in code instead the stack we are talking about is reccursion stack
TC=O(V+E) in case of adjanced list and O(V^2) in case of adjaced list*/ 
void dfs(vector<int> *v,int s,int *vis)
{
    cout<<s<<" ";
    vis[s]=1;
    for(int i=0;i<v[s].size();i++)
    {
        if(vis[v[s][i]]!=1)
        dfs(v,v[s][i],vis);
    }
}

int main()
{
    vector<int> v[5];
    int vis[5]={0};
    while(1)
    {
        int a,b,ch;
        cout<<"\nEnter the src and des";
        cin>>a>>b;
        adjancedlist(v,a,b);
        cout<<"\nDo you want to enter more";
        cin>>ch;
        if(ch==0)
        break;
    }
    dfs(v,1,vis);

    return 0;
}
