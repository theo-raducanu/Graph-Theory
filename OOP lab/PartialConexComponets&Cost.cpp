/*
13 20
0 1 7
0 3 5
1 2 8
1 4 7
1 3 9
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
7 8 1
7 9 5
8 10 5
8 9 2
8 11 3
9 11 2
10 12 2
10 11 1
11 12 4
*/

/*
Grafuri orientate, reprezentate cum doreste programatorul:
clasa graf orientat sa contina metode pentru: citirea grafului, care sa supraincarce operatorul >>; afisarea grafului, care sa supraincarce operatorul <<; 
citirea si afisarea sa foloseasca acelasi mod de reprezentare a grafului, care sa arate intreaga structura a grafului, ceea ce parcurgerile urmatoare nu pot face; 
parcurgerea in latime; parcurgerea in adancime; determinarea matricii (existentei) drumurilor; determinarea componentelor tare conexe, nu ca grafuri, ci ca liste de varfuri;
 o metoda care sa determine daca graful este tare conex, care poate folosi oricare dintre metodele anterioare; o metoda de supraincarcare a operatorului +, 
care sa determine, din doua grafuri orientate avand aceeasi multime de varfuri, graful orientat cu aceeasi multime de varfuri ca si acele doua grafuri, 
si cu multimea arcelor egala cu, reuniunea multimilor arcelor acelor doua grafuri (bineinteles, tinand cont de orientarea arcelor);
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#define inf 999999
using namespace std;

int a[100][100],b[100][100],s[100],tata[100];
ifstream f("graf.in");

void citire(int &n,int &m)
{
    int l,j,k,i;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>l>>j>>k;
        a[l][j]=a[j][l]=k;
    }

}
void afisaremat(int x[100][100],int n)
{
    int i,j;
    cout<<"     ";
    for(i=0;i<n;i++)
    {
        cout<<setw(4)<<i<<setw(4);
    }
    cout<<"\n\n";
    cout<<setw(4);
     for(i=0;i<n;i++)
    {
        cout<<i<<" ";
        for(j=0;j<n;j++)
        {
            if(i>0 && j<i)
                cout<<setw(4)<<"-"<<setw(4);
            else
             {
                 if(x[i][j]==inf)
                    cout<<setw(4)<<"inf"<<setw(4);
                else
                    cout<<setw(4)<<x[i][j]<<setw(4);
             }
        }
        cout<<endl;

    }
}
void royfloyd(int a[100][100],int n)
{
    for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(a[i][j]==0)
                    b[i][j]=inf;
                else
                    b[i][j]=a[i][j];
    for(int i=0;i<n;i++)
            b[i][i]=0;
    //CORMEN Floyd-Warshall
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(b[i][j]>b[i][k]+b[k][j])
                    b[i][j]=b[i][k]+b[k][j];
}

void descompun_drum(int i,int j,int n)
{
    int k=1,p=i;
    cout<<setw(4)<<i<<" ";
    while(k<=n && p!=j)
    {
        if(a[p][k] && b[p][j]==b[p][k]+b[k][j])
        {
            cout<<k<<" ";
            p=k;
        }
        k++;
    }
}

void drum_min(int n)
{
    int i,j;
    cout<<setw(6)<<"i= ";
    cin>>i;
    cout<<setw(6)<<"j= ";
    cin>>j;
    if(b[i][j]!=inf)
    {
        cout<<"Lungimea drumului minim de la i la j este "<<b[i][j]<<endl;
        cout<<"Drumul minim de la i la j :\n";
        descompun_drum(i,j,n);
    }
    else
        cout<<"Drumul de la i la j nu exista\n";
    cout<<endl;
}

//CORNEL.EDU
void dfs(int u,int cnt,int n)
{
    if(!s[u])
    {
        s[u]=cnt;
    for(int v=0;v<n;v++)
        if(!s[v] && a[u][v])
            dfs(v,cnt,n);
    }
}

void componente_conexe(int n)
{
    int k,x,ok=1;
    for(k=0;k<n;k++)
        dfs(k,k+1,n);
    for(k=1;k<=n;k++)
     {
         if(ok==1)
            cout<<setw(4);
         ok=0;
         for(x=0;x<n;x++)
              if(s[x]==k)
              {
                ok=1;
                cout<<x<<" ";
              }
         if(ok)
            cout<<endl;
    }

}

// http://www.c-program-example.com
int cauta(int i,int n)
{
    while(tata[i]!=inf)
        i=tata[i];
    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        tata[j]=i;
        return 1;
    }
    return 0;
}

void kruskal(int n)
{
    int ne=0,c,b,i,j,u=0,v=0,min,mincost=0,comp,ncomp=0,k;
    for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
              if(a[i][j]==0)
                   a[i][j]=inf;
    for(int i=0;i<n;i++)
        tata[i]=inf;
    cout<<"Dati un nod intre 0-"<<n-1<<" : ";
    cin>>k;
    cout<<"Arborele partial de cost minim al componentei conexe din care face parte nodul "<<k<<" este format din :\n";
    comp=s[k];
    for(i=0;i<n;i++)
        if(s[i]==comp)
            ncomp++;
    while(ne<ncomp-1)
    {
        for(i=0,min=inf;i<n;i++)
        {
            if(s[i]==comp)
            for(j=0;j<n;j++)
            {
                if(a[i][j]<min && s[j]==comp)
                {
                    min=a[i][j];
                    c=u=i;
                    b=v=j;
                }
            }
        }

        u=cauta(u,ncomp);
        v=cauta(v,ncomp);
        if(uni(u,v))
        {
            cout<<"\n"<<setw(4)<<(ne++)+1<<" muchia ("<<c<<","<<b<<") ="<<min<<"\n";
            mincost +=min;
        }
        a[c][b]=a[b][c]=inf;
    }
        cout<<"\n\tCost minim al arborelui partial = "<<mincost<<"\n";
}

int main()
{
    int n,m,i,j;
    citire(n,m);
    royfloyd(a,n);
    cout<<"a) Matricea drumurilor cu ponderi minime :\n\n";
    afisaremat(b,n);
    cout<<"\nb) Drumul minim dintre i si j :\n";
    drum_min(n);
    cout<<"\nc) Componentele conexe :\n";
    componente_conexe(n);
    cout<<"\nd) Arborele partial de cost minim al unei componente conexe:\n";
    kruskal(n);
    return 0;
}
