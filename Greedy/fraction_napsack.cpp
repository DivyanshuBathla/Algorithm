
#include <stdio.h>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

float fracnap(vector<pair<int,int>> &item,int bag)
{

    
    float ans=0;
    int n=item.size();
    vector<pair<float,pair<int,int>>>  items;
    for(int i=0;i<n;i++)
    {
        float uw=item[i].first/float(item[i].second);
        items.push_back(make_pair(uw,item[i]));
    }
    sort(items.rbegin(),items.rend());
   
    
    for(int i=0;i<n;i++)
    {
        if(bag<=0)
        break;
        int c=items[i].second.second;
    
        int temp=bag/c;
        
        if(temp!=0)
        { 
            
        ans=ans+items[i].second.first;
        bag=bag-c;
        cout<<"\nbag="<<bag;
        cout<<"\nprofit="<<items[i].second.first;
        cout<<"\nweight="<<items[i].second.second;
        cout<<"\nunit weight="<<items[i].first;
        cout<<"\nans="<<ans;
         cout<<"\n";
        }
        else
        {
            cout<<"\n p="<<bag*items[i].first<<"\n";
            ans=ans+bag*items[i].first;
            bag=bag-bag*items[i].first;
            
       cout<<"\nbag="<<bag;
        cout<<"\nprofit="<<items[i].second.first;
        cout<<"\nweight="<<items[i].second.second;
        cout<<"\nunit weight="<<items[i].first;
        cout<<"\nans="<<ans;
            
        }
    }
    return(ans);
}
int main()
{
    vector<pair<int,int>> item;
    cout<<"Enter the number of items=";
    int n;
    int p,w;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the profit and weight=";
        cin>>p>>w;
        item.push_back(make_pair(p,w));
    }
    int bag;
    cout<<"Enter the bag capacity=";
    cin>>bag;
    float r=fracnap(item,bag);
    cout<<"\n";
cout<<"Res="<<r;
    return 0;
}
