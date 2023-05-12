#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void readarray(int a[],int n)
{
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++)
            a[i] = rand()%100;        
}

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

void heapify(int a[],int top,int last)
{
    int j,t;
    
    j = 2*top+1; //j points to left child of top
    
    if((j<last) && (a[j]<a[j+1])) //compare left and right children
        j = j+1;
    
    if((j<=last) && (a[top]<a[j]))  //compare greatest child with top
    {						// swap greater child and top
        t = a[top];
        a[top] = a[j];
        a[j] = t;

        heapify(a,j,last);
    }
}                  

void heapsort(int a[],int n)
{
    int i, t, top=0, last;
	
	for(i=n/2-1;i>=0;i--)  //initial heap 
        heapify(a,i,n-1);    
   
    printf("\nInitial Heap\n");
    display(a,n);

    for(i=n-1;i>=1;i--)
        {
            t = a[top];
            a[top] = a[i];
            a[i] = t;

            printf("\nAfter Iteration %d : ",n-i);
            display(a,n);
            heapify(a,top,i-1);
        }
}

int main()
{
    int a[100],n;
    printf("\nEnter how many numbers:");
    scanf("%d",&n);

    readarray(a,n);

    printf("\nBefore Sorting:\n");
    display(a,n);
    
    heapsort(a,n);

    printf("\nAfter Sorting:\n");
    display(a,n);
    return 0;
}