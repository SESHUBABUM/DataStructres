// Example program
#include <iostream>
#include <string>
using namespace std;
/*Weighted Union find algorithms with path compression */
class UF
{
    int N;
    int *sz;
    int *arr;
public:
     UF(int n)
     {
         this->N=n;
         sz=new int[n];
         arr=new int[n];
         for(int i=0;i<N;i++)
         {
             sz[i]=1;
             arr[i]=i;
         }
     }
     int root(int x)
     {
         while(x!=arr[arr[x]])
         {
             x=arr[arr[x]];
         }
         return x;
     }
     bool isConnected(int x,int y)
     {
         return(root(x)==root(y));
     }
     void Union(int x,int y)
     {
         int x1=root(x);
         int y1=root(y);
         if(sz[x1] < sz[y1])
         {
             arr[x1]=y1;
             sz[y1]+=sz[x1];
         }
         else
         {
             arr[y1]=x1;
             sz[x1]+=sz[y1];             
         }
         
     }
     
    
};

int main()
{
  UF uf(10);
  uf.Union(2,3);
  uf.Union(2,1);
  uf.Union(0,1);
  cout<< uf.isConnected(0,3)<<endl;
  return 0;
}
