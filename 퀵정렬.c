#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
int partition(int list[], int left,int right)
{
    int pivot,temp,low,high;
    low = left;
    high= right+1;
    pivot=list[left];
    do
    {
        do
        {
            low++;
        }while(list[low]<pivot && low<=right);
        do
        {
            high--;
        }while(list[high]>pivot);

        if(low<high)
        {
            swap(list[low],list[high],temp);
        }
    }while(low<high);
    swap(list[left],list[high],temp);
    return high;
}

void quicksort(int list[], int left,int right)
{
    if(left<right)
    {
        int q=partition(list, left, right);
        quicksort(list,left,q-1);
        quicksort(list,q+1,right);
    }
}

int main()
{
    int list[6]={10,2,20,7,50,1};
    quicksort(list,0,5);
    for(int i=0; i<6; i++)
    {
        printf("%d ",list[i]);
    }
    return 0;
}
