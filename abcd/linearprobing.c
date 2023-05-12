#include<stdio.h>
#define MAX 10

int hashfunction(int key,int i) //division hashing function with linear probing
{
    return ((key%MAX)+i)%MAX;   //linear probing
    //return (key%MAX + (i+3*i))%MAX;   //quadratic probing
    //return (key%MAX + (i*i))%MAX; //quadratic probing
    //return ((key%MAX) + i*(key%MAX))%MAX; //double hasing    
}

void insert(int ht[],int key)
{
    int index,i;
    
    for(i=0;i<MAX;i++)
    {
    index = hashfunction(key,i);  //i prob
    if(ht[index]==-1) //bucket is empty
        {
            ht[index] = key;
            return;
        }    
    }

    printf("\n%d can't be inserted",key);    
}

int search(int ht[],int key)
{
    int index,i;
    for(i=0;i<MAX;i++)
        {
            index = hashfunction(key,i);
            if(ht[index]==key)
                return index;
        }
    return -1;
}

void delete(int ht[],int key)
{
    int index;
    index = search(ht,key);
    if(index==-1)
        printf("\n%d is not present",key);
    else
        {
            ht[index] = -1;
            printf("\n%d deleted successfully",key);
        }
}

void init(int ht[])
{
    int i;
    for(i=0;i<MAX;i++)
        ht[i] = -1;
}

void showtable(int ht[])
{
    int i;
    for(i=0;i<MAX;i++)
        printf("\n%d[%d]",i,ht[i]);
}

int main()
{
    int ht[MAX],ch,key,index;
    
    init(ht);

    do{
        printf("\n1:insert\n2:search\n3:delete\n4:show\n5:Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter key to be inserted:");
                    scanf("%d",&key);
                    insert(ht,key);
                    break;
            case 2: printf("\nEnter key to be searched:");
                    scanf("%d",&key);
                    index = search(ht,key);
                    if(index==-1)
                        printf("%d is not found",key);
                    else
                        printf("\n%d is found at %d location",key,index);
                    break;
            case 3: printf("\nEnter key to be deleted:");
                    scanf("%d",&key);
                    delete(ht,key);
                    break;
            case 4: showtable(ht);
                    break;
        }
    }while(ch!=5);

    return 0;
}