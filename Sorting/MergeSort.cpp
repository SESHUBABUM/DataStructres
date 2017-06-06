// Example program
#include <iostream>
#include <string>
using namespace std;
class MergeSort
{
   public:
   void merge(int input[],int aux[],int lo,int mid,int hi)
   {
       int k;
       for(int k=lo;k<=hi;k++)
       aux[k]=input[k];
       int i=lo,j=mid+1;
       for(k=lo;k<=hi;k++)
       {
           aux[k]=input[k];
       }
       for(k=lo;k<=hi;k++)
       {
           if(i> mid) input[k]=aux[j++];
           else if(j>hi) input[k]=aux[i++];
           else if( aux[i] > aux[j]) input[k]=aux[j++];
           else input[k]=aux[i++];
       }
    }
   
   void sort(int input[],int aux[],int lo,int hi)
   {
        if(hi<=lo) return;
        int mid= (lo+hi)/2;
        sort(input,aux,lo,mid);
        sort(input,aux,mid+1,hi);
        merge(input,aux,lo,mid,hi);
   }
};

int main()
{
  MergeSort obj;
  int a[]={10,20,30,1,2,23,12,34,444,21};
  int n=sizeof(a)/sizeof(int);
  int *aux=new int[n];
  obj.sort(a,aux,0,n-1);
  for(int i=0;i<n;i++)
  {
      cout<<a[i] << " ";
  }
  delete[] aux;
}
