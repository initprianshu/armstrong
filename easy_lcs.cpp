#include <iostream>
#include <string.h>

using namespace std;

int LCS(char *x, char *y, int m, int n){
    int L[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0) L[i][j]=0;
            else if(x[i-1]==y[j-1]) L[i][j]=L[i-1][j-1]+1;
            else L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[m][n];
}

int main(){
    char x[]="abcd";
    char y[]="bcd";
    int m=strlen(x);
    int n=strlen(y);
    cout<<"Longest substring is "<<LCS(x,y,m,n)<<endl;
    return 0;
}