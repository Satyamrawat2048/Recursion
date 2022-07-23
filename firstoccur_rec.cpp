#include<bits/stdc++.h>
using namespace std;
int recu(int a[], int n,int i,int val )
{ if(i==n) return -1;
  if(a[i]==val) return i ;

  return recu(a,n,i+1 ,val) ;
}
int main(){
  
  int a[]={ 1,2,25,6,7,15,8,90} ,val=5;
  int n= sizeof(a)/sizeof(int) ;
  cout<< recu(a,n , 0,val ); 

 return 0;
}