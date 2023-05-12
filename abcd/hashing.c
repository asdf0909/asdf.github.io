#include<stdio.h>
#define MAX 10
int hashfunction(int key,int i)
{
    return ((key%MAX)+i)%MAX;
}
void insert(int hashtable[],int key)
{
    int i,index;
    for(i=0;i<MAX;i++)
    {
        index = hashfunction(key,i);
        if(hashtable[index]==-1)
            {
                hashtable[index] = key;
                return;
            }    
    }
    printf("\n%d can't be inserted",key);
}
int search(int hashtable[],int key)
{
    int i,index;
    for(i=0;i<MAX;i++)
    {
        index = hashfunction(key,i);
        if(hashtable[index] == key)
            return index;
    }
    return -1;
}
void delete(int hashtable[],int key)
{
    int index;
    index = search(hashtable,key);
    if(index==-1)
        printf("%d is not found",key);
    else
        hashtable[index]=-1;    
}
void showtable(int hashtable[])
{
    int i;
    for(i=0;i<MAX;i++)
        printf("%d[%d]\n",i,hashtable[i]);
}
void init(int hashtable[])
{
    int i;
    for(i=0;i<MAX;i++)
        hashtable[i]=-1;
}
int main()
{
    int hashtable[MAX],ch,key,index;
    init(hashtable);
    do{
        printf("1:Insert\n2:Search\n3:Delete\n4:Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter key to be inserted:");
                    scanf("%d",&key);
                    insert(hashtable,key);
                    showtable(hashtable);
                    break;
            case 2: printf("\nEnter key to be searched:");
                    scanf("%d",&key);
                    index = search(hashtable,key);
                    if(index==-1)
                        printf("key not found");
                    else
                        printf("key is found at %d location",index);
                    break;
            case 3: printf("\nEnter key to be deleted:");
                    scanf("%d",&key);
                    delete(hashtable,key);
                    showtable(hashtable);
                    break;                    
        }
    }while(ch!=4);

    return 0;
}