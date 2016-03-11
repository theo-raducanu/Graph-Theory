#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int,char> > myvector;
int dim,n;

int pred( pair<int,char> a, pair<int,char> b)
{
    return (a.first<b.first);
}
void afis()
{
        cout<<'\n';
        for(int i=dim-1;i>=0;i--)
        cout <<myvector[i].first<< ' ' << myvector[i].second<<'\n';
}
int main()
{
    cin>>dim;
    for (int i=0; i<dim; i++)
    {
        cin>>n;

    }
    sort(myvector.begin(),myvector.end(),pred);

    cout << '\n'<<"Secventa sortata :"<<'\n';
    for (  vector<pair<int,char> >::iterator it = myvector.begin() ; it != myvector.end(); it++)
        cout << (*it).first<<' '<<(*it).second<<endl;

    cout << '\n'<<"Havel hakini :"<<'\n';
    if(myvector[0].first<0)
    {
        cout<<"cel putin un element negativ -> nu este secventa grafica";
        return 0;
    }
    if(myvector[dim-1].first>=dim)
    {
        cout<<"cel putin un element >= dimensiunea secventei -> nu este secventa grafica";
        return 0;
    }
    int aux;
    while(myvector.back().first>=0)
    {
        afis();
        if(myvector.front().first<0)
        {
            cout<<"Secventa nu este grafica";
            return 0;
        }
        if(myvector.back().first==0 && myvector.front().first==0)
        {
            cout<<"Secventa este grafica";
            return 0;
        }
        aux=myvector.back().first;
        myvector.pop_back();
        dim--;
        for(int i=dim-1;i>=dim-aux;i--)
            myvector[i].first--;
            sort(myvector.begin(),myvector.end(),pred);
    }
    cout<<"Secventa este grafica";

  return 0;
}
