#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long  int t;
    cin>>t;
    while(t--)
    {
       long long int n;
        cin>>n;
        long long int a;
       long long  int sum=0;
        for(long long int i=0;i<n;i++)
        {
            cin>>a;
            sum=sum+a;
        }

        long long int extra = sum%n ;
        int result=(n-extra)*extra;

        cout<<result<<endl;
    }
}
