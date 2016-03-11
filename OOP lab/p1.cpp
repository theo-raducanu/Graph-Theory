#include <iostream>

using namespace std;

class graf_orientat
{
    int lin;
    int** A = new int*[lin];
public :
friend istream& operator>>(istream &in,graf_orientat &x)
    {
    in>>x.lin;
    for (int i = 0; i < x.lin; ++i)
     {
         x.A[i] = new int[x.lin];
         for(int j=0;j<x.lin;++j)
             in>>x.A[i][j];
     }
    return in;
    }
friend ostream &operator<<( ostream &out,graf_orientat &x)
      {
        for (int i = 0; i < x.lin; ++i)
        {
            for (int j = 0; j < x.lin; ++j)
            out<<x.A[i][j]<<" ";
            out<<endl;
        }
         return out;
      }
};

int main()
{
    graf_orientat a;
    //ifstream f("graf.in");
    cin>>a;
    cout<<a;
    return 0;
}
