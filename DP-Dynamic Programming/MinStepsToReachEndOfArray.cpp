#include <bits/stdc++.h>
using namespace std;

int minjumps(int arr[],int n)
{
    int *jumps = new int[n];
    if(n==0 || arr[0]==0)
        return -1;
    jumps[0]=0;
    
    for(int i=1;i<n;i++)
    {
        jumps[i]=INT_MAX;
        for(int j=0;j<i;j++)
        {
            if(j+arr[j]>=i && jumps[j]!=INT_MAX)
            {
                jumps[i]=min(jumps[i],jumps[j]+1);
                break;
            }
        }
    }
    if(jumps[n-1]== INT_MAX)
    return -1;
    return jumps[n-1];
}

void solve(){
    int  n; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<minjumps(arr,n);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	   solve();
	   cout<<endl;
	}
	return 0;
}
