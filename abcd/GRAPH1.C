#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next;
}node;


node* append(node* head,int x)
{
 node *temp,*p;

 temp = (node*)malloc(sizeof(node));
 temp->data = x;
 temp->next = NULL;

 if(head==NULL)
   head = temp;
 else
   {
    p = head;
    while(p->next != NULL)
	 p = p->next;

    p->next = temp;
   }
 return head;
}


void display(node* head)
{
 node* p;
 p = head;
 while(p!=NULL)
     {
      printf("%d-->",p->data);
      p = p->next;
     }
 printf("NULL");
}

int visited[10]={0};

void DFS(int adj[][10],int n,int i)
{
 int j;
 printf("%d ",i);
 visited[i] = 1;
 for(j=0;j<n;j++)
     if(adj[i][j]==1 && visited[j]!=1) //connected but not visited
		DFS(adj,n,j);
}



int main()
{
 int adj[10][10],i,j,n,degree[10][2]={0},v;
 node *head[10]={NULL};

//  clrscr();
 printf("\nEnter how many vertices:");
 scanf("%d",&n);
 printf("\nEnter inputs for a graph having %d vertices",n);

 for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
	{
	 printf("\nConnection between %d and %d?(1/0):",i,j);
	 scanf("%d",&adj[i][j]);
	 if(i==j && adj[i][j]==1)
	   {
	    printf("\nSelf loop is not allowed");
	    getch();
	    exit(0);
	   }
	}
    }

 printf("\nAdjacency Matrix\n");
 for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
	printf("%d ",adj[i][j]);
     printf("\n");
    }

 for(i=0;i<n;i++)
    for(j=0;j<n;j++)
       degree[i][1] += adj[i][j];


  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
       degree[i][0] += adj[j][i];


  printf("\nIndegree Outdegree\n");
  for(i=0;i<n;i++)
    {
     for(j=0;j<2;j++)
	printf("%d\t",degree[i][j]);
     printf("\n");
    }

 for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
	{
	  if(adj[i][j]==1)
	    {
	     head[i]=append(head[i],j);
	    }
	}
    }

 printf("\nAdjacency List\n");
 for(i=0;i<n;i++)
    {
     printf("[%d]-->",i);
     display(head[i]);
     printf("\n");
    }

 printf("\nEnter the starting vertex for DFS:");
 scanf("%d",&v);

 DFS(adj,n,v);  //start from vertex v
	
//  getch();
 return 0;
}