#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define max_size 100

struct array {
    int *a;
    int size;
    int l;
};

typedef struct array ar;
void initialize();
void display();
void sort(ar *k)
{
    int t;
    for (int j = 0; j < k->l; j++)
    {     
        for (int i = 0; i < k->l-j; i++)
    {
      if (k->a[i]>k->a[i+1])
      {
        t=k->a[i+1];
        k->a[i+1]=k->a[i];
        k->a[i]=t;
      }
    }
      
    }
    
}
void rearrange(ar* p)
{
    int i=0,j=p->l-1;
    while (i<j)
    {
       if (p->a[j]>0)
       {
         j--;
       }
       else{
        p->a[i++]=p->a[j];
       }
       if (p->a[i]<0)
       {
        i++;
       }
       else{
        p->a[j--]=p->a[i];
       }
       
    }
    sort(p);
    
}
ar intersect(ar*p,ar*k)
{
    int i=0,j=0;
     ar q;
    q.size = max_size;
    q.l = 0;
    q.a = (int*)malloc(q.l * sizeof(int));

    sort(p);
    sort(k);
    while (i<p->l && j<k->l)
    {
        if (p->a[i]<k->a[j])
        {
            i++;
        }
        else if (k->a[j]<p->a[i])
        {
            j++;
        }
        else
        {
            q.a[q.l++]=p->a[i];
            i++;
            j++;
        }      
        
    }
    
 return q;   
} 
ar diffe(ar* p,ar* k)
{
     int i = 0, j = 0;
    ar q;
    q.size = max_size;
    q.l =0;
    q.a = (int*)malloc(q.l * sizeof(int));

    sort(p);
    sort(k);
    while (i<k->l && j<p->l)
    {
        if (k->a[i]<p->a[j])
        {
            q.a[q.l++]=k->a[i++];
        }
        else
        {
            i++;
            j++;
        }        
    }
    return q;
}

ar mergesort(ar* p, ar* k) 
 {
    int i = 0, j = 0, w = 0;
    ar q;
    q.size = max_size;
    q.l = p->l + k->l;
    q.a = (int*)malloc(q.l * sizeof(int));

    sort(p);
    sort(k);

    while (i < k->l && j < p->l) {
        if (k->a[i] < p->a[j]) {
            q.a[w++] = k->a[i++];
        }
        else {
            q.a[w++] = p->a[j++];
        }
    }

    for (; i < k->l; i++) {
        q.a[w++] = k->a[i];
    }

    for (; j < p->l; j++) {
        q.a[w++] = p->a[j];
    }

    return q;
}
ar unionq(ar* p, ar* k) 
 {
    int i = 0, j = 0;
    ar q;
    q.size = max_size;
    q.l = 0;
    q.a = (int*)malloc(q.l * sizeof(int));

    sort(p);
    sort(k);

    while (i < k->l && j < p->l) {
        if (k->a[i] < p->a[j]) {
            q.a[q.l++] = k->a[i++];
        }
        else if(k->a[i] > p->a[j]){
            q.a[q.l++] = p->a[j++];
        }
        else
        {
            q.a[q.l++]=p->a[j++];
            i++;
        }
    }

    for (; i < k->l; i++) {
        q.a[q.l++] = k->a[i];
    }

    for (; j < p->l; j++) {
        q.a[q.l++] = p->a[j];
    }

    return q;
}


void insesort(ar* p, int x)
{
    int i = p->l - 1;
    sort(p);
    while (i >= 0 && p->a[i] > x) 
    {
        p->a[i + 1] = p->a[i];
        i--; 
    }
    p->a[i + 1] = x; 
    p->l++;
}

void rotation_l(ar* p)
{
    int x=p->a[p->l-1];
    for (int i = p->l-1; i >0; i--)
    {
        p->a[i]=p->a[i-1];
    }
    p->a[0]=x;
    
}
void rotation_r(ar* p)
{
    int i;
    int x=p->a[0];
    for (i = 0; i < p->l-1; i++)
    {
        p->a[i]=p->a[i+1];
    }
    p->a[i]=x;
    
}
void left(ar *p)
{
    int i;
    for (i = 0; i < p->l-1; i++)
    {
        p->a[i]=p->a[i+1];
    }
    p->a[i]=0;
}
void right(ar *p)
{
    for (int i = p->l-1; i >0; i--)
    {
        p->a[i]=p->a[i-1];
    }
   p->a[0] =0;
}

void merge(ar* p1, ar*p2)
{
   if (p1->l+p2->l>p1->size)
   {
     return;
   }
   int i=p1->l,j=0;
   while (i<(p1->l+p2->l))
   {
      p1->a[i]=p2->a[j];
      i++,j++;
   }
   p1->l=(p1->l+p2->l);  
   
}
void wow()
{  printf("nothing happens");
}
void rev(ar* p)
{
  int t;
  int j=p->l-1;
  int i=0;
  while (i<j)
  {
    t=p->a[i];
    p->a[i]=p->a[j];
    p->a[j]=t;
    i++;
    j--;
  }  
}
void swap(int *x,int *y)
{
    int t;
        t=*x;
        *x=*y;
        *y=t;   
}
void display(ar *p) {
    for (int i = 0; i < p->l; i++) {
        printf("%d ", p->a[i]);
    }
    printf("\n");
}


void initialize(ar *p) {
    printf("Enter the number of elements: ");
    scanf("%d", &p->l);

    p->a = (int *)malloc(p->l * sizeof(int));

    for (int i = 0; i < p->l; i++) {
        scanf("%d", &p->a[i]);
    }
}
int get(ar *p,int i)
{
    if (i>0 && i<p->l)
    {
        return p->a[i];
    }
    
}
void set(ar *p,int i,int x)
{
    if (i>0 && i<p->l)
    {
        p->a[i]=x;
    }
    
}
int max(ar *p)
{
    int x=p->a[0];
    for (int i = 0; i < p->l; i++)
    {
        if (p->a[i]>x)
        {;;
            x=p->a[i]; 
        }
        
    }
    return x;
    
}
int min(ar *p)
{
    int x=p->a[0];
    for (int i = 0; i < p->l; i++)
    {
        if (p->a[i]<x)
        {
            x=p->a[i];
        }
        
    }
    return x;
    
}
int sum(ar *p)
{
    int s=0;
    for (int i = 0; i < p->l; i++)
    {
        s=s+p->a[i];
    }
 return s;   
}
int avg(ar *p)
{
    int s=0,a;
    for (int i = 0; i < p->l; i++)
    {
        s=s+p->a[i];
    }
    a=s/p->l;
 return a;   
}


void binsearch(ar *p)
{
      sort(p);
      printf("the sorted list is:\n");
      display(p);
      printf("enter the element to be found:");
      int x,f=0;
      scanf("%d",&x);
      int l=0,h=p->l-1,mid;
      while (l<h)
      {
        mid=(l+h)/2;
        if (p->a[mid]==x)
        {
            f=1;
            break;
        }
        else if (x>p->a[mid])
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
        }
         if (f==1)
    printf("successful at index: %d",mid);
   else
   printf("unsuccessful");
        
      
}
void linsearch(ar *p)
{
    printf("enter the number to be searched:\n");
    int x,i,f=0;
    scanf("%d",&x);
    for (i = 0; i < p->l; i++)
    {
        if (p->a[i]==x)
        {
            f=1;
            break;
        }
    }
   if (f==1)
    printf("successful at index: %d",i);
   else
   printf("unsuccessful");
    
}
void delete(ar* p)
{
    printf("enter the position to be deleted:");
    int q,x,i;
    scanf("%d",&x);
    q=p->a[x];
    for ( i = x; i < p->l-1; i++)
    {
        p->a[i]=p->a[i+1];
    }
    p->l--;
    printf("\nthe removed element is %d\n",q);
    
}
void insert(ar* p)
{
    printf("enter the position");
    int in,e;
    scanf("%d",&in);
    printf("\nenter the element");
    scanf("%d",&e);
    p->l++;
    for (int i = p->l-1;i>in; i--)
    {
        p->a[i]=p->a[i-1];
    }
    p->a[in]=e;
    printf("new length = %d\n",p->l);
    
}

int main() {
    int k;
    ar r;
    ar we;
    r.size = max_size;
    initialize(&r);
    int c=1;
    int w,e,in,s;
    s=0x1F604;
    while(c)
    {
    int choice = 0;
    printf("enter a choice\n");
    printf("to sort the array --> enter 1\n");
    printf("to linear search the array --> enter 2\n");
    printf("to binary search the array --> enter 3\n");
    printf("to get element at index --> enter 4\n");
    printf("to set element at index --> enter 5\n");
    printf("to insert element --> enter 6\n");
    printf("to delete an element --> enter 7\n");
    printf("for maximum element --> enter 8\n");
    printf("for minimum element --> enter 9\n");
    printf("for sum of all elements --> enter 10\n");
    printf("for avg of all elements --> enter 11\n");
    printf("for reverse of list without auxillary array --> enter 12\n");
    printf("for shiftinf the elements of the list --> enter 13\n");
    printf("for merging the list with a new list--> enter 14\n");
    printf("for left shift operation --> enter 15\n");
    printf("for right shift operation--> enter 16\n");
    printf("for array rotation operation right--> enter 17\n");
    printf("for array rotation operation left --> enter 18\n");
    printf("for rearrange the positive and negatives--> enter 19\n");
    printf("for entering element in a sorted array--> enter 20\n");
    printf("for merging two arrays into a sorted array--> enter 21\n");
    printf("for intersection of two arrays--> enter 22\n");
    printf("for difference of first and second list--> enter 23\n");
    printf("for union of the two lists--> enter 24\n");
    printf("display the array--> enter 25\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            sort(&r);
            break;
        case 2:
            linsearch(&r);
            break;
        case 3:
            binsearch(&r);
            break;
        case 4:
            printf("enter the index:\n");
            scanf("%d",&in);
            printf("\nThe value at index is:%d",get(&r,in));
            break;
        case 5:
            printf("enter the index and the data:\n");
            scanf("%d%d",&w,&e);
            set(&r,w,e);
            break;
        case 6:
            insert(&r);
            break;
        case 7:
            delete(&r);
            break;
        case 8:
            printf("The maximum value is:%d",max(&r));
            break;
        case 9:
            printf("The minimum value is:%d",min(&r));
            break;
        case 10:
            printf("The sum is:%d",sum(&r));
            break;
        case 11:
            printf("The average is:%d",avg(&r));
            break;
        case 12:
            rev(&r);
            break;
        break;
        case 13:
            wow();
            break;
        break;
        case 14:
            printf("enter the 2nd array:\n");
            ar q;
            q.size=max_size;
            initialize(&q);
            merge(&r,&q);
            printf("The new size becomes:%d",r.l);
            break;
         case 15:
            left(&r);
            break;
         case 16:
            right(&r);
        break;
         case 17:
          rotation_r(&r);
        break;
        case 18:
        rotation_l(&r);
        break;
        case 19:
        rearrange(&r);
        break;
        case 20:
        printf("\nEnter the element to be inserted:");
        scanf("%d",&k);
        insesort(&r,k);
        break;
        case 21:
        printf("\n");
        ar k;
        k.size=max_size;
        initialize(&k);
        we=mergesort(&r,&k);
        printf("The sorted merged list is:\n");
        display(&we);
        free(we.a);
        free(k.a);
        break;
        case 22:
        printf("\n");
        initialize(&k);
        we=intersect(&r,&k);
        printf("The intersected list is:\n");
        display(&we);
        free(we.a);
        free(k.a);
        break;
        case 23:
        printf("\n");
        initialize(&k);
        we=diffe(&r,&k);
        printf("The difference of the two list is:\n");
        display(&we);
        break;
        case 24:
        printf("\n");
        initialize(&k);
        we=unionq(&r,&k);
        printf("The union list is:\n");
        display(&we);
        free(we.a);
        free(k.a);
        break;
        case 25:
            display(&r);
            break;
        default:
            break;
    }
    printf("\n do you want to continue 0,1?");
    scanf("%d",&c);
    }
    printf("Thank you %lc",s);
    free(r.a);
    getch();
    return 0;
}
