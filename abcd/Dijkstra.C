#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 8
 
void dijkstra(int G[MAX][MAX],int n,int startnode);
 
int main()
{
    int G[MAX][MAX]={
		{0,0,0,0,0,0,0,0},
		{30,0,0,0,0,0,0,0},
		{100,80,0,0,0,0,0,0},
		{0,0,120,0,0,0,0,0},
		{0,0,0,150,0,25,0,0},
		{0,0,0,100,0,0,90,140},
		{0,0,0,0,0,0,0,140},
		{170,0,0,0,0,0,0,0}
	};
	int i,j,n,u;
    printf("Enter no. of vertices:");
    n=8;//scanf("%d",&n);
    /*
    printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	    scanf("%d",&G[i][j]);

    */
    printf("\nEnter the starting node:");
    u=4;//scanf("%d",&u);
    dijkstra(G,n,u);
    return 0;
}
 
void dijkstra(int G[MAX][MAX],int n,int startnode)
{
 int cost[MAX][MAX],dist[MAX],visited[MAX],pred[MAX],u,i,j,min,count;

 //initial-1 copy adjacency matrix to cost matrix, convert 0 to infinity
 for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		if(G[i][j]==0)
			cost[i][j] = INFINITY;
		else
			cost[i][j] = G[i][j];
			
			
 //initial-2 copy cost of startnode into distance array,all visited = 0,all pred = startnode
  for(i=0;i<n;i++)
	{
	dist[i] = cost[startnode][i];
	visited[i] = 0;
	pred[i] = startnode;
	}
	
 //	initial-3 dist of startnode=0, visited of startnode=1,count=1
	dist[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	
 while(count<n-1)
	{
	 //step-1 find minimum distance and select u vertext i.e. nextnode
	 min = INFINITY;
	 for(i=0;i<n;i++)
		{
			if(visited[i]!=1 && dist[i]<min)
				{
					min = dist[i];
					u = i;
				}
		}
	 //step-2 visited of u = 1
	 visited[u] = 1;
	 
	 //step-3 update dist array and pred array according to next node
	 for(i=0;i<n;i++)
		{
		 if(visited[i]!=1)
			{
				if(min+cost[u][i]<dist[i])
					{
						dist[i] = min + cost[u][i];
						pred[i] = u;
					}
			}
		}
	
	 count++;
	}	
	
	// print the path and dist of each node
	for(i=0;i<n;i++)
		{
			if(i!=startnode)
			{
			printf("\nDistance of %d from %d is %d:",i,startnode,dist[i]);
			printf("\nPath : %d",i);
			
			j = i;
			do{
				j = pred[j];
				printf("<-%d ",j);				
			}while(j!=startnode);     
			
			}
		}	
}