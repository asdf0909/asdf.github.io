#include<stdio.h>
#define MAX 7
int parent[MAX]={-1,-1,-1,-1,-1,-1,-1};

int find(int i)
{//find the root of the tree that contains i
    while(parent[i]!=-1)
		i = parent[i];

    return i;
}
int uni(int i,int j)
{//if the roots are different, it unites the two trees by making one root the parent of the other and returns 1
    if(i!=j)
	{
	    parent[j] = i;
	    return 1;
	}
    return 0;
}

int main()
{
    int i,j,a,b,u,v,e,min,mincost = 0;
    int n;    
    // int cost[MAX][MAX]={
	// {9999,5,3,9999,9999,9999,9999},
	// {5,9999,4,6,2,9999,9999},
	// {3,4,9999,5,9999,6,9999},
	// {9999,6,5,9999,8,6,9999},
	// {9999,2,9999,8,9999,3,5},
	// {9999,9999,6,6,3,9999,4},
	// {9999,9999,9999,9999,5,4,9999}
    // };    

    int cost[MAX][MAX]={
	{9999,20,9999,9999,9999,4,9999},
	{20,9999,8,9999,9999,9999,7},
	{9999,8,9999,6,9999,9999,9999},
	{9999,9999,6,9999,10,9999,9},
	{9999,9999,9999,10,9999,15,11},
	{4,9999,9999,9999,15,9999,9999},
	{9999,7,9999,9,11,9999,9999}
    };
	
	// //modify MAX to 8
	// int cost[MAX][MAX]={
	// 	{9999,9999,9999,9999,9999,9999,9999,9999},
	// 	{30,9999,9999,9999,9999,9999,9999,9999},
	// 	{100,80,9999,9999,9999,9999,9999,9999},
	// 	{9999,9999,120,9999,9999,9999,9999,9999},
	// 	{9999,9999,9999,150,9999,25,9999,9999},
	// 	{9999,9999,9999,100,9999,9999,90,140},
	// 	{9999,9999,9999,9999,9999,9999,9999,100},
	// 	{170,9999,9999,9999,9999,9999,9999,9999}
	// };
	
	

    // printf("\nEnter number of vertices:");
    n = MAX; // scanf("%d",&n);

    printf("\nThe edges of Minimum Cost Spanning Tree are\n");
    for(e=0;e<n-1;e++)
	{
	    //step-1 find minimum cost
	    min = 9999;
	    for(i=0;i<n;i++)		
		{
		    for(j=0;j<n;j++)
			{
			    if(cost[i][j]<min)
				{
				    min = cost[i][j];
				    a = u = i;
				    b = v = j;
				}
			}
		}

	    //step-2 call find() and uni() and deselect visited edge
	    u = find(u);
	    v = find(v);
	    if(uni(u,v))
		{
		    printf("\n%d edge (%d,%d) = %d",e+1,a,b,min);
		    mincost += min;
		}
	    else
			e--;
			
	    cost[a][b] = cost[b][a] = 9999; // Make edge cost 9999 so that it wont be selected again
	}
	printf("\n");
	for(i=0;i<MAX;i++)
		printf("%d\t",parent[i]);

    printf("\nMinimum cost = %d",mincost);
    return 0;
}