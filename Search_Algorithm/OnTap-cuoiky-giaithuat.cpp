#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

void selectionSort(int *a,int n);
void insertSort(int *a,int n);
void bubbleSort(int *a,int n);
void quickSort(int* &a,int L,int R);

//===chuong trinh chinh===
int main()
{
    //Khai bao tep doc vao
    ifstream fin("daykhoa.txt");

    //khai bao bien
    int i,n;

    //Doc so luong phan tu day khoa
    fin>>n;

    //Khai bao mang dong
    int *a = new int[n];

    //in ra day khoa co trong tep
    cout<<"Day khoa doc duoc tu tep la: ";
    for(i=0;i<n;i++)
    {
        fin>>a[i];
        cout<<a[i]<<"  ";
    }

    selectionSort(a,n);
    cout<<"\n\nCac phan tu sau khi sap xep bang SelectionSort la: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"  ";
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void selectionSort(int *a,int n)
{
    int i,j,tg,k;
    for(i=0;i<n-1;i++)
    {
        //1.Tim phan tu co gia tri nho nhat
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[k]) k=j;
        }

        //2.Doi cho
        if(k!=i) // tại đây k đóng vai trò là j: phần tử có giá trị nhỏ
        {
            tg=a[k];
            a[k]=a[i];
            a[i]=tg;
        }
    }
}

void insertSort(int *a,int n)
{
    int i,j,tg;
    for(i=1;i<n;i++)
    {
        tg=a[i];
        j=i-1;
        while(tg<a[j] && j>-1)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tg;
    }
}

void bubbleSort(int *a,int n)
{
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

void quickSort(int* &a,int L,int R)
{
    if(L>=R) return;

    int i=L, j=R, k=(L+R)/2, x=a[k], tg;

    do
    {
        //Duyệt từ trái sang phải cho đến khi gặp ai>=x
        while(a[i]<x) i++;

        //Duyệt từ phải sang trái cho đến khi gặp aj<=x
        while(a[j]>x) j--;

        //Đổi chỗ cho ai và aj
        if(i<j)
        {
            tg = a[i];
            a[i] = a[j];
            a[j] = tg;
        }

    }while(i<j);

    //Gọi đệ quy ở phân nửa bên trái
    quickSort(a,L,j-1);
    //Gọi đệ quy ở phân nửa bên phải
    quickSort(a,j+1,R);
}


