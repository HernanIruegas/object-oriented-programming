#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    char a[11];
    char b[11];
    char c[11];
    int iN;
    
    cin>>iN;
    while(iN<0 || iN>20)
    {
        cin>>iN;
    }
    
    for(int iA=0; iA<iN; iA++)
    {
    cin>>a>>b>>c;
        
    if(strcmp(a,b)<=0)
    {
       if(strcmp(b,c)<=0)
         cout<<a<<" "<<b<<" "<<c<<endl;
       else
       {
         if(strcmp(c,a)<0)
            cout<<c<<" "<<a<<" "<<b<<endl;
         else
            cout<<a<<" "<<c<<" "<<b<<endl;
        }
     }
    else 
    {
       if(strcmp(b,c)<=0)
       {
          if(strcmp(a,c)<=0)
            cout<<b<<" "<<a<<" "<<c<<endl;
          else
            cout<<b<<" "<<c<<" "<<a<<endl;
       }
       else
          cout<<c<<" "<<b<<" "<<a<<endl;
    }
    }
    return 0;
}