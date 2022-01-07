#include <stdio.h>
#include<stdlib.h>
struct edge{
    int des;
    int weight;
    struct edge * adj;
};
struct vertex{
    int src;
    struct edge *e;
};
struct graph_info{
    int src;
    int des;
    int weight;
    struct graph_info *next;
};
struct disjoint_set{
    int parent;
    int child;
};
typedef struct disjoint_set set;
typedef struct graph_info info;
typedef struct edge edge;
typedef struct vertex vertex;

void addedge(vertex *v,int src,int des,int weight,int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        if(v[i].src==-1||v[i].src==src)
        {
            break;
        }
    }
    if(src==des)
    {
         v[i].src=src;
        edge *temp=(edge*)malloc(sizeof(edge));
        temp->des=des;
        temp->weight=weight;
        temp->adj=v[i].e;
        v[i].e=temp;
        v[j].src=des;
        return;
    }
    for(j=0;j<n;j++)
    {
       if((v[j].src==-1||v[j].src==des)&&j!=i)
        {
            break;
        } 
    }
    if(i>=n||j>=n)
    {
       printf("\nCant find the vertex");
       return;
    }
    else
    {
        v[i].src=src;
        edge *temp=(edge*)malloc(sizeof(edge));
        temp->des=des;
        temp->weight=weight;
        temp->adj=v[i].e;
        v[i].e=temp;
        
        
        v[j].src=des;
         edge *temp1=(edge*)malloc(sizeof(edge));
        temp1->des=src;
        temp1->weight=weight;
        temp1->adj=v[j].e;
        v[j].e=temp1;
    }
}

void display_edge(edge * e)
{
    while(e!=NULL)
    {
        printf("(%d %d) ",e->des,e->weight);
        e=e->adj;
    }
}
void display(vertex v[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(v[i].src==-1)
        break;
        printf("%d ",v[i].src);
        display_edge(v[i].e);
        printf("\n");
    }
}
info * insert(info *head,info *temp)
{
     info * first=head;
     info *frnd=NULL;
     if(head==NULL)
     head=temp;
     else{
         while (head!=NULL)
         {
             if(head->weight>temp->weight)
             break;
             frnd=head;
             head=head->next;
         }
         if(head==first)
         {
             temp->next=head;
             head=temp;
         }
         else if(head==NULL)
         {
              frnd->next=temp;
              temp->next=NULL;
              head=first;

         }
         else{ 
             head=frnd;
         temp->next=head->next;
         head->next=temp;
         head=first;
         }
     }
     
     return(head);
}

info * create_edge(info *head,int src,edge * e)
{
    while(e!=NULL)
    {
        info *temp=(info*)malloc(sizeof(info));
        temp->src=src;
        temp->des=e->des;
        temp->weight=e->weight;
        temp->next=NULL;
        head=insert(head,temp);
        e=e->adj;
    }
    return(head);
}
info * create_info(info *head,vertex v[],int n)
{
    for(int i=0;i<n;i++)
    {
        head=create_edge(head,v[i].src,v[i].e);
        
    }
    
         
     return(head);
}
int find(set s[],int n,int elem)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i].child==elem)
        break;
    }
    if(s[i].child!=s[i].parent)
    return(find(s,n,s[i].parent));
    else
    return(s[i].parent);
}
void update(set *s,int n,int src ,int des)
{
    for(int i=0;i<n;i++)
    {
        if(s[i].child==des)
        {
            if(s[i].child!=s[i].parent)
            { 
              int elem=s[i].parent;  
              s[i].parent=src;
              update(s,n,src,elem);
            }
            else
            {
              s[i].parent=src;

            }
            break;
        }
    }
}
int MCST(info *head,set s[],int n)
{
    int sum=0;
    while(head!=NULL)
    {
        int f1,f2;
        f1=find(s,n,head->src);
        f2=find(s,n,head->des);
        if(f1!=f2)
        {    
        sum=sum+head->weight;
        update(s,n,head->src,head->des);
        }
        head=head->next;
    }
    return(sum);
}
int main() {
    int n;
    int src,des,weight,ch;
    printf("Enter the number of vertex you want in graph=");
    scanf("%d",&n);
    vertex v[n];
    for(int i=0;i<n;i++)
    {
        v[i].src=-1;
        v[i].e=NULL;
    }
    
    do{
        printf("\nMain menu\n1.To insert edge\n2.To display graph");
        int c;
        scanf("%d",&c);
        switch(c)
        {
            case 1:  printf("\nEnter the src destination and weight of the edge=");
                    scanf("%d%d%d",&src,&des,&weight);
                    addedge(v,src,des,weight,n);
                    break;
            case 2: display(v,n);
                   break;
        }
        printf("\nDo you want to do more opeations=");
        scanf("%d",&ch);
    }while(ch!=0);
   
   info *head=NULL;
   head=create_info(head,v,n); 
 
   
   
    set s[n];
    for(int i=0;i<n;i++)
    {
        s[i].parent=v[i].src;
        s[i].child=v[i].src;
    }
    printf("\nMinimum cost=%d",MCST(head,s,n));
    return 0;
}
