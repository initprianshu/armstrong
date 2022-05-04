#include<bits/stdc++.h>

using namespace std;

struct items
{
    int value,weight;
    float ratio;
};

bool method(items i1,items i2)
{
    return i1.ratio>i2.ratio;
}

void fractionalKnapsack(items *a,int w,int n)
{
    int ans=0;
    cout<<"Values that are added are : "<<endl;
    for(int i=0; i<n; i++)
    {
        if(w>=a[i].weight)
        {
            ans+=a[i].value;
            cout<<a[i].value<<" "<<a[i].weight<<endl;
            w-=a[i].weight;
        }
        else
        {
            cout<<w*a[i].ratio<<" "<<w<<endl;
            ans+=a[i].ratio*w;
            break;
        }
    }
    cout<<"Max value is : "<<ans<<endl;
}

int main()
{
    int w = 50;
    items arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int size=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++) arr[i].ratio=(float)arr[i].value/arr[i].weight;
    sort(arr,arr+size,method);
    fractionalKnapsack(arr,w,size);
}