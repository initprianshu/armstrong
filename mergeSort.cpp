#include <iostream>

using namespace std;

void merge(int *a,int l,int mid,int h)
{
	int i=l,j=mid+1,k=0,temp[h-l+1];
	for( ; (i<=mid) and (j<=h); k++)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			i++;
		}
		else
		{
			temp[k]=a[j];
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		i++;
		k++;
	}
	while(j<=h)
	{
		temp[k]=a[j];
		j++;
		k++;
	}
	for(int q=l; q<=h; q++)
	{
		a[q]=temp[q-l];
	}
}

void mergesort(int *a,int l,int h)
{
	int mid=(l+h)/2;
	if(l<h)
	{
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,mid,h);
	}
}

int main()
{
	int n;
	cout<<"Enter number of elements : ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements : \n";
	for(int i=0; i<n; i++) cin>>arr[i];
	mergesort(arr,0,n-1);
	cout<<"Array after sorting is : ";
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}