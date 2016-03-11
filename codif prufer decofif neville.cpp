#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
using namespace std;

int main()
{
    int n,x,y,max=0,j,k,l,dim;
    ifstream f("in.txt");
    f>>dim;
    vector<pair<int,int> > leg (dim+1);
    for (int i=1; i<=dim; i++)
    {
        f>>x>>y;
        leg[i]=(make_pair(x,y));
    }
    for(int i=1;i<=dim;i++)
        cout <<leg[i].first<<" "<<leg[i].second<<endl;
     vector<int> apar(dim+2), prufer(dim+1);
    for (int i=1; i<=dim; i++)
    {
       apar[leg[i].first]++;
       apar[leg[i].second]++;
    }
    cout<<"Grade :"<<endl;
    for(int i=1;i<=dim+1;i++)
        cout <<apar[i]<<" ";

    for(int j=1;j<=dim;j++)
	{

		for(int i=1;i<=dim+1;i++)
		{
			if(apar[i]==1)
			{
				l=i;
				break;
			}
		}
		for(k =1;k<=dim;++k)
		{
			if(leg[k].first==l || leg[k].second==l)
			{
				if(leg[k].first==l)
				{
					apar[leg[k].second]--;
					prufer[j]=leg[k].second;

				}
				else
				{
					apar[leg[k].first]--;
					prufer[j]=leg[k].first;
				}
				leg[k].first=-1;
				leg[k].second=-1;
				break;

			}
		}
		apar[l] = 0;
	}
	prufer[dim]  = dim+1;
	cout<<endl<<"Prufer :"<<endl;
	for( k =1; k <=dim-1; ++k)
		cout<<prufer[k]<<" ";

    /*NEVILLE*/
    cout<<endl<<"Dati lungimea codificarii neville : ";
    cin>>dim;
    cout<<"Dati o codificarea neville : ";
	vector<int>neville(dim+1);
	for(int i=1; i <=dim;i++)
            cin>>neville[i];
    vector<int> apar2(dim+3);
    for(int i=1;i<=dim+2;i++)
        apar2[i]=1;
    for(int i=1;i<=dim;i++)
        apar2[neville[i]]++;
    vector<pair<int,int> > leg2;
    vector<int> temp;

    cout<<endl;
    cout<<"Grade :";
    cout<<endl;
    for(int i=1;i<=dim+2;i++)
        cout<<apar2[i]<<" ";
    cout<<endl;
    int ult,pen;
    pen=neville[dim-1];
    ult=neville[dim];
    for(j=1;j<=dim;j++)
    {
        temp.clear();
        for(int i=1;i<=dim+2;i++)
        {
            if(apar2[i]==1)
             {
                temp.push_back(i);
                apar2[i]=0;
             }
        }
        for(int i=0;i<temp.size();i++)
        {
            for(int k=1;k<=dim;k++)
                if(neville[k]>0)
                {
                    leg2.push_back(make_pair(temp[i],neville[k]));
                    neville[k]=0;
                    break;
                }
        }
        for(int i=0;i<leg2.size();i++)
            apar2[leg2[i].second]--;
    }
    leg2.push_back(make_pair(ult,pen));
    cout<<endl<<"Muchii :"<<endl;
    for(int i=0;i<leg2.size();i++)
        cout<<leg2[i].first<<" "<<leg2[i].second<<endl;

  return 0;
}
