#include<bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N,int M);

int main()
{
    	int T;
	cin>>T;
	while(T--){
		int N<M;
		cin>>N>>M;
		vector<int>A[N];
		for(int i=0;i<N;i++)
		{
			vector<int>temp(M);
			A[i]=temp;
			for(int j=0;j<M;j++){	
				cin>>A[i][j];
			}
		}
		cout<< findIslands(A,N,M)<<endl;
	}
	return 0;
}


int isInside(int row, int col,int N,int M) 
{ 
    // row number is in range, column 
    // number is in range and value is 1 
    // and not yet visited 
    return (row >= 0) && (row < N) && (col >= 0) && (col < M); 
} 
void DFS(vector<int> A[],int row,int col,vector<vector<int>> &visited,int N,int M)
{
    int posRow[]={ -1, -1, -1, 0, 0, 1, 1, 1 }; 
    int posCol[]={ -1, 0, 1, -1, 1, -1, 0, 1 }; 
    visited[row][col]=true;
    for(int k=0;k<8;k++){
        int u=row+posRow[k];int v=col+posCol[k];
        if(isInside(u,v,N,M) &&visited[u][v]==0 && A[u][v]){
            DFS(A,u,v,visited,N,M);
        }
    }
}

int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    vector<vector<int>> visited(N,vector<int> (M,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            visited[i][j]=0;
        }
    }
    
    int cnt=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j] && !visited[i][j])
            {
                DFS(A,i,j,visited,N,M);
                cnt++;
            }
        }
    }
    return cnt;
}

