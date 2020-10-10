#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Ham cai dat phep toan sap xep
void insertSort(int *a, int n);

//===chuong trinh chinh===
int main()
{
    //khai bao tep doc vao
    ifstream fin("daykhoa.txt");

    //khai bao bien
    int n,i;

    //doc so luong phan tu trong day khoa tu tep
    fin>>n;

    //tao mang dong
    int *a = new int[n];

    //doc va xuat day khoa tu tep ra man hinh
    cout<<"Day khoa doc tu tep la: \n";
    for(i=0;i<n;i++)
    {
        fin>>a[i];
        cout<<a[i]<<" ";
    }

    insertSort(a,n);

    //xuat day khoa sau khi sap xep ra man hinh
    cout<<"\n\nDay khoa sau khi sap xep la: \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void insertSort(int *a, int n)
{
    int i,j,tg;
    for(i=1;i<n;i++)
    {
        tg=a[i];
        j=i-1;
        while(tg<a[j] && j>-1)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tg;
    }
}
