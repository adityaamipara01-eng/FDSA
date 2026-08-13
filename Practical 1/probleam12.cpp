#include<iostream>
using namespace std;

int main()
{
    int n,i,j,w;

    cout<<"Enter Number of Book IDs : ";
    cin>>n;

    int a[n];

    
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    
    for(i=0;i<n;i++)
    {
        w=1;

        
        bool found=false;
        for(j=0;j<i;j++)
        {
            if(a[i]==a[j])
            {
                found=true;
                break;
            }
        }

        if(found)
        {
            continue;
        }

    
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                w++;
            }
        }

        
        if(w>1)
        {
            cout<<"Book ID "<<a[i]<<" Borrowed "<<w<<" Times"<<endl;
        }
    }

    return 0;
}