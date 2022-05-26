/******************************************************************************/

                 

#include <iostream>
#include<vector>
#include<queue> 
#define n 8
using namespace std;
void adjancedlist(vector<int> *v,int src,int des)
{
    
    v[src].push_back(des);
    v[des].push_back(src);
}

/*In bft we use queue 
Tc=O(V+E) for adjanced list and O(v^2) for adjanced list*/
bool cycledetection(vector<int> *v,int s,int *vis)
{
    queue<int> q;
    q.push(s);
    int parent[n]={-1};
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
                parent[v[temp][i]]=temp;
            }
            else if(parent[temp]!=v[temp][i])
            return true;
        }
    }
    return false;
}
bool iscycle(vector<int> *v,int s,int *vis)
{
    int i=0;
    while(i<n)
    {
        if(vis[i]==0&&cycledetection(v,i,vis))
        return true;
    }
    return false;
}
int main()
{
    vector<int> v[n];
    int vis[n]={0};
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
    
    if(iscycle(v,0,vis))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    

    return 0;
}
