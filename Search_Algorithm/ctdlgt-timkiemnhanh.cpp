#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

void quickSort(int* &a, int L, int R);

//===chuong trinh chinh===
int main()
{
    //Khai bao tep doc vao
    ifstream fin("daykhoa.txt");

    //Khai bao bien
    int i,x,n;

    //Doc so luong phan tu khoa co trong day
    fin>>n;

    //Khai bao mang dong
    int *a = new int[n];

    //Xuat ra man hinh cac phan tu co trong tep
    cout<<"Cac phan tu trong tep la: \n";
    for(i=0;i<n;i++)
    {
        fin>>a[i];
        cout<<a[i]<<"  ";
    }

    //goi ham sap xep
    quickSort(a,0,n-1);

    //dua ra man hinh
    cout<<"\n\nDay khoa sap xep tang dan la: \n";
    for(i=0;i<n;i++)
        cout<<a[i]<<"  ";

    //Huy mang dong
    delete [] a;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void quickSort(int* &a, int L, int R)
{
    if(L>=R)
    {
        return;
    }
    //khai bao
    int i=L,j=R,k=(L+R)/2,x=a[k],tg;

    do
    {
        //duyet tu trai sang phai cho den khi ai>=x
        while(a[i]<x) i++;

        //duyet tu phai sang trai cho den khi aj<=x
        while(a[j]>x) j--;

        //doi cho ai va aj
        if(i<j)
        {
            tg=a[i];
            a[i]=a[j];
            a[j]=tg;
        }

    }while(i<j);

    //goi de quy phan doan ben trai
    quickSort(a,L,j-1);

    //goi de quy phan doan ben phai
    quickSort(a,j+1,R);
}
