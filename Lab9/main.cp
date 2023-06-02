#include<iostream>
using namespace std;

//addition function

int add(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
    
}

//average function
float average(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return ((float)sum/n);
    
}

//validation function
int validate(int n)
{
    if(n>=1 && n<=99)
    {
        return n;
    }
    else
    {
        cout<<"enter valid number"<<endl;
        return 0;
    }
    
}
int main()
{
    int n,element;
    
    cout<<"Enter the count: ";
    cin>>n;
    int arr[n];
    cout<<"enter element:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        int res= validate(element);
        
        if(res==0)
        {
            i--;
            continue;
        }
        else
        {
            arr[i]=res;
        }
    }
    int total=add(arr,n);
    float avg=average(arr,n);
    cout<<"Total sum: "<<total<<endl;
    cout<<"Average: "<<avg<<endl;
    
}
