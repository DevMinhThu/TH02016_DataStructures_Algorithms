#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao ham cac giai thuat
void selectionSort(int *a,int n);
void insertSort(int *a,int n);
void bubbleSort(int *a,int n);
void quickSort(int *a,int L,int R);

//===chuong trinh chinh===
int main()
{
    //Khai bao tep doc vao
    fstream fin("daykhoa.txt");

    //Khai bao bien
    int i,n;

    //Doc so luong phan tu trong tep
    fin>>n;

    //Khai bao mang dong a
    int *a = new int[n];

    //xuat day khoa ra man hinh
    cout<<"Cac phan tu trong tep daykhoa.txt la: \n";
    for(i=0;i<n;i++)
    {
        fin>>a[i];
        cout<<a[i]<<"  ";
    }

    //Sap xep chon
    selectionSort(a,n);
    cout<<"\n\nCac phan tu sau khi sap xep bang SelectionSortla: \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }

    cout<<endl;
    return 0;
}
//==dinh nghia ham===
void selectionSort(int *a,int n)
{
    //Khai bao bien
    int i,j,tg,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        //Tim vi tri k cua phan tu nho nhat
        for(j=i+1;j<n;j++)
            if(a[j]<a[k]) k=j;

        //Doi cho ak va ai
        if(k!=i)
        {
            tg=a[k];
            a[k]=a[i];
            a[i]=tg;
        }
    }
}

void insertSort(int *a,int n)
{
    //Khai bao bien
    int i,j,tg;
    for(i=1;i<n;i++)
    {
        tg=a[i];
        j=i-1;
        while(tg<a[j] && j>-1)
        {
            a[j+1] =a[j];
            j--;
        }
        a[j+1] = tg;
    }
}
void bubbleSort(int *a,int n)
{
    //Khai bao bien
    int i,j,tg;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                tg=a[j];
                a[j]=a[j-1];
                a[j-1]=tg;
            }
        }
    }
}

void quickSort(int *a,int L,int R)
{
    if(L>=R) return;

    int i=L, j=R, k=(L+R)/2, x=a[k], tg;

    do
    {
        //Duyet tu trai sang ccho den khi gap phan tu ai>=x
        while(a[i]<x) i++;
        //Duyet tu phai sang ccho den khi gap phan tu aj<=x
        while(a[j]>x) j--;

        //doi cho ai va aj
        if(i<j)
        {
            tg=a[i];
            a[i]=a[j];
            a[j]=tg;
        }

    }while(i<j);

    //Goi de quy phan doan ben trai
    quickSort(a,L,j-1);
    //Goi de quy phan doan ben phai
    quickSort(a,j+1,R);

}
