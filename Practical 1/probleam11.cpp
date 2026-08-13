#include<iostream>
using namespace std;
int a[10]={1,2,3,4,5,6,7,8,9,10};
    
void reverse(int y){
    int i;
    cout<<"For "<<y+1<<" hour"<<endl;
    for( i=y;i<10;i++){
        cout<<a[i]<<" ";
    }
    for(i=0;i<y;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){

       for(int h=0;h<10;h++){
            reverse(h);
        }
          return 0;
    
    }
   
    
   
