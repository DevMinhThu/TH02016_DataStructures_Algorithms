//Ho ten:
//Lop:
//MaSV:
//De: Tim kiem nhi phan

#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

int binarySearch(int *a,int n,int x);

//===chuong trinh chinh===
int main()
{
    //khai bao tep doc vao
    ifstream fin("daykhoadasapxep.txt");

    //khai bao bien
    int i,n,x;

    //doc vao so luong phan tu day khoa trong tep
    fin>>n;

    //khai bao mang dong
    int *a = new int[n];

    //doc va in ra cac phan tu trong day khoa
    cout<<"Cac phan tu trong day khoa la: \n";
    for(i=0;i<n;i++)
    {
        fin>>a[i];
        cout<<a[i]<<"  ";
    }

    //tim kiem
    cout<<"\n\nNhap gia tri x can tim: "; cin>>x;
    int kq = binarySearch(a,n,x);

    if(kq==-1)
        printf("\n\nKhong tim duoc %d trong day khoa: ",x);
    else
        printf("\n\nTim duoc %d trong day khoa tai vi tri %d. ",x,kq);

    //huy mang dong
    delete [] a;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
int binarySearch(int *a,int n,int x)
{
    //1.khoi tao
    int L=0,R=n-1,m;
    while(L<=R)
    {
        //tim chi so phan tu o giua
        m=(L+R)/2;
        if(x<a[m]) R=m-1;
        else
            if(x>a[m]) L=m+1;
            else return m+1;
    }
    return -1;
}

int binarySearch(int *a,int n,int x)
{
    //Khai bao
    int L=0,R=n-1,m;

    while(L<=R)
    {
        m = (L+R)/2;

        if(x<a[m]) R=m-1;
        else
            if(x>a[m]) L=m+1;
            else return m+1;
    }
    return -1;
}









