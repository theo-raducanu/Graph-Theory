#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

typedef struct {
	int from; 
	int to; 
} EdgeList; 

int main()
{	
	EdgeList* edgeList;
	int i=0, n=0;
	int *prufer, *degre, *temp, *present; 

	FILE* f = fopen("In.txt", "r");

	fscanf(f,"%d", &n);

	edgeList = (EdgeList*) calloc(n, sizeof(EdgeList));
	degre = (int*) calloc(n, sizeof(int));
	temp = (int*) calloc(n-2, sizeof(int));	
	present = (int*) calloc(n, sizeof(int));	


	prufer = (int*) calloc( n -2, sizeof(int));
	printf("Edges: \n") ;
	while(!feof(f))
	{
		fscanf(f, "%d%d", &edgeList[i].from, &edgeList[i].to); 
		printf(" %d - %d \n", edgeList[i].from, edgeList[i].to);

		++degre[edgeList[i].from]; 
		++degre[edgeList[i].to]; 


		// set the grad of the vertex

		++i; 
	}

	// fa => Prufer	

	int k =0, l= 0,t =0 ; 

	printf("\n$$$$$$$$$$      ");

	for( k =0; k < n; ++k)
		printf(" %d ", k);


	printf("\nA Degrees:      ");

	for( k =0; k < n; ++k)
		printf(" %d ", degre[k]);

	printf("\n");

	printf("The prufer code: ");

	printf("\n");

	int j = 0; 
	for( j= 0; j < n-2; ++j)
	{

		// find the vertex with the smallest grad		
		for( k=0; k < n;k++)
		{
			if(degre[k] == 1)			
			{				 
				l = k; 
				break; 
			}
		}

		// ok we have in l the min point, get on what it is

		// ok find the pair of this
		for(  k =0; k < n-1; ++k)
		{
			if( edgeList[k].from == l || edgeList[k].to == l)
			{
				//cut it off, delete the edge and decrease the degree of the vertex
				if(edgeList[k].from ==l)
				{
					--degre[prufer[j] = edgeList[k].to]; 					

				}
				else
				{
					--degre[prufer[j] = edgeList[k].from]; 
				}
				edgeList[k].from = -1; 
				edgeList[k].to = -1; 

				break; 

			}

		}

		degre[l] = 0; // no more additional data on this vertex

	}
	prufer[n-2]  = n-1; 
	for( k =0; k < n-1; ++k)
		printf(" %d ", prufer[k]);

	printf("\n");


	// Prufer => tree

	// we will reconstruct into the edgeList the vertexes
	l = 0;


	for (  j =0;  j < n-1; ++j)
	{
		memset(present,0, n*sizeof(int) ) ; // reset the count array 

		for( k = j ; k < n-2; ++k)
			present[prufer[k]] = 1;  // see what we have 

		for( k = 0; k < j; k++)  // also present the point we alread deduced
			present[temp[k]] = 1; 

		for( k =0 ; k < n; ++k)
			if(!present[k]) // not present
			{
				edgeList[j].from = prufer[j] ; // found the pair 
				edgeList[j].to  = k;  // k and current
				temp[j] = k;  // add it as already deduced vertex
				break;		  // we need to do this only for the minimal/ once
			}
	}





		printf("\n The prufer code transformed back: edges \n"); 


		for( i =0; i< n-1; ++i)
		{
			printf(" %d - %d \n", edgeList[i].from, edgeList[i].to);
		}
		printf("\n");
		// Finish

		free(edgeList);



		return 1; 

}

/* 
Sample input in file:

8 
1 2
1 6
1 7
0 1
0 3
0 4
4 5


Sample output:
Edges:
1 - 2
1 - 6
1 - 7
0 - 1
0 - 3
0 - 4
4 - 5

$$$$$$$$$$       0  1  2  3  4  5  6  7
A Degrees:       3  4  1  1  2  1  1  1
The prufer code:
1  0  4  0  1  1  7

The prufer code transformed back: edges
1 - 2
0 - 3
4 - 5
0 - 4
1 - 0
1 - 6
1 - 7

Press any key to continue . . .
*/