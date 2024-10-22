#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void bubblesort(int arr[30],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
        if(arr[i]>arr[j])
          {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
          }
      }
    }
}
void insertionsort(int arr[30],int n)
{
  int i,j,temp;
  for(i=1;i<n;i++)
  {
    temp=arr[i];
    j=i-1;
    while(j>=0 && temp<=arr[j])
    {
      arr[j+1]=arr[j];
      j=j-1;
    }
    arr[j+1]=temp;
  }
}
void fork1()
{
  int arr[30],arr1[25],n,i,status;
  printf("\nEnter the no of values in array :: ");
  scanf("%d",&n);
  printf("\nEnter the array elements :: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  int pid=fork();
  if(pid==0)
  {
    sleep(10);
    printf("\nChild Process\n");
    printf("\n\nChild Process ID = %d",getpid());
    insertionsort(arr,n);
    printf("\n\n\n\nElements Sorted Using Insertion Sort :: ");
    printf("\n");
    for(i=0;i<n;i++)
    {
      printf("%d\t",arr[i]);     
    }
    printf("\b");
    printf("\n\n\nParent Process ID = %d",getpid());
    system("ps-x");
  }
  else
  {
    printf("\n\n\n\nParent Process\n");
    printf("\n\nParent Process ID = %d",getpid());
    bubblesort(arr,n);
    printf("\n\n\nElements Sorted Using Bubble Sort :: ");
    printf("\n");
    for(i=0;i<n;i++)
    {
      printf("%d\t",arr[i]);     
    }
    printf("\n\n\n");
  }
}
int main()
{
  fork1();
  return 0;
}
