#include <iostream>
#include <fstream>
using namespace std;

class graf_orientat
{
    int n,m;
    int** A = new int*[n];
public :
friend istream& operator>>(istream &in,graf_orientat &x)
    {
    in>>x.n>>x.m;
    int n1,n2;
    for (int i = 1; i <=x.n; i++)
        x.A[i] = new int[x.n];
    for (int i = 1; i <=x.n; i++)
        for (int j = 1; j <=x.n; j++)
        x.A[i][j]=0;
    for (int i = 1; i <=x.m; i++)
    {
        in>>n1>>n2;
        x.A[n1][n2]=1;
    }
    return in;
    }
friend ostream &operator<<( ostream &out,graf_orientat &x)
      {
        cout<<x.n<<" noduri si "<<x.m<<" muchii\n";
        for (int i = 1; i <=x.n; i++)
            for (int j = 1; j <=x.n; j++)
            if(x.A[i][j])
            out<<i<<" "<<j<<endl;
         return out;
      }
};
int main()
{
    graf_orientat a;
    ifstream f("graf.in");
    f>>a;
    cout<<a;
    return 0;
}
