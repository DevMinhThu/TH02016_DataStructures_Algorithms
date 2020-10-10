#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Ham cai dat phep toan sap xep
void selectionSort(int *a, int n);

//===chuong trinh chinh===
int main()
{
    //khai bao tep doc vao
    ifstream fin("daykhoa.txt");

    //khai bao bien
    int n,i;

    //doc so luong phan tu trong day khoa
    fin>>n;

    //khai bao mang dong
    int *a = new int[n];

    //doc vao day khoa va in ra man hinh
    cout<<"Day khoa doc tu tep la: \n";
    for(i=0;i<n;i++)
    {
        fin>>a[i];
        cout<<a[i]<<" ";
    }

    selectionSort(a,n);

    //day so sau khi sap xep la
    cout<<"\n\nDay khoa sau khi sap xep la: \n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void selectionSort(int *a, int n)
{
    int i,j,tg,k;
    for(i=0;i<n-1;i++)
    {
        //Tim vi tri k cua phan tu nho nhat
        k=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[k])
            {
                k=j;
            }
        }

        //Doi cho ak va ai
        if(k!=i)
        {
            tg=a[k];
            a[k]=a[i];
            a[i]=tg;
        }
    }
}
