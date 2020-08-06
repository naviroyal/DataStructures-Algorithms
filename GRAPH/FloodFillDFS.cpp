
#include <iostream>
using namespace std;

int R,C;

void print(char mat[][])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<mat[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void floodFill(char mat[][],int i,int j,char ch,char color)
{
    if(i<0||j<0||i>=R||j>=C||mat[i][j]!=ch)
    {
        return;
    }
    mat[i][j]=color;
    floodFill(mat,i+1,j,ch,color);
    floodFill(mat,i,j+1,ch,color);
    floodFill(mat,i-1,j,ch,color);
    floodFill(mat,i,j-1,ch,color);
}

int main()
{
    int mat[50][50];
    cin>>R>>C;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>mat[i][j];
        }
    }
    floodFill(mat,8,13,'.','R')
    print(mat)

    return 0;
}

