# include <iostream>
# include <vector>
using namespace std;

string X,Y;
vector< vector<int> > c(101, vector<int>(101,0));
int m,n,ctr;
 
void LONGEST()
{
     m = X.length(),n=Y.length();
 
     int i,j;
     for (i=0;i<=m;i++)
         for (j=0;j<=n;j++)
             c[i][j]=0;
 
     for (i=1;i<=m;i++)
         for (j=1;j<=n;j++)
         {
             if (X[i-1]==Y[j-1])
                c[i][j]=c[i-1][j-1]+1;
             else
                 c[i][j]=max(c[i][j-1],c[i-1][j]);
         }
}
 
void print(int i,int j)
{
    if (i==0 || j==0)
       return;
    if (X[i-1]==Y[j-1])
    {
       print(i-1,j-1);
       cout<<X[i-1];
    }
    else if (c[i][j]==c[i-1][j])
         print(i-1,j);
    else
        print(i,j-1);
}
 
int main(int argc,char *argv[])
{
X=argv[1];
Y=argv[2];
LONGEST();
print(m,n);    
}
