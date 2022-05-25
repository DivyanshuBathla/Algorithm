/******************************************************************************

                 

#include <iostream>
#include<vector>
#include<queue> 
using namespace std;
void adjancedlist(vector<int> *v,int src,int des)
{
    
    v[src].push_back(des);
    v[des].push_back(src);
}
/*In bft we use queue 
Tc=O(V+E) for adjanced list and O(v^2) for adjanced list*/
void bfs(vector<int> *v,int s,int *vis)
{
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!(q.empty()))
    {
        int temp=q.front();
        cout<<temp<<" ";
        q.pop();
        for(int i=0;i<v[temp].size();i++)
        {
            if(vis[v[temp][i]]!=1)
            {
                q.push(v[temp][i]);
                vis[v[temp][i]]=1;
            }
        }
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
    bfs(v,1,vis);

    return 0;
}
