#include <iostream>
using namespace std;

int main(){
    int wt[]={0,2,3,4,5};
    int p[]={0,1,2,5,6};
    int m=8;
    int n=4;

    int k[n+1][m+1];

    for(int i=0; i<=n;i++){
        for(int w=0;w<=m;w++){
            if(i==0||wt==0){
                k[i][w]=0;
            }
            else if(wt[i]<=w) k[i][w]=max(p[i]+k[i-1][w-wt[i]],k[i-1][w]);
            else k[i][w]=k[i-1][w];
        }
    }
    cout<<"The maximum profit is "<<k[n][m];
    return 0;
}




























