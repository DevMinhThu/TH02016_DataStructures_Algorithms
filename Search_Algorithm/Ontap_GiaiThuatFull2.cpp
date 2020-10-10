//Ho ten: Vu Minh Thu
//Lop: K63TH
//MaSv: 637865
//De: Cac giai thuat

#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao ham cai dat cac giai thuat
void selectionSort(int *a, int n); // Sap xep chon
void insertSort(int *a, int n);// Sap xep chen
void bubbleSort(int *a, int n);// Sap xep sui bot
void quickSort(int* &a, int L, int R);

//===chuong trinh chinh===
int main()
{
    //Khai bao tep doc vao
    ifstream fin("daykhoa.txt");
    ofstream fout("ketquasapxep.txt");//Khai bao ghi kq vao trong tep

    //Khai bao bien
    int i,n;

    //Doc so luong phan tu trong day khoa
    fin>>n;

    //Khai bao mag dong a
    int *a = new int[n];

    //In ra man hinh day khoa cos trong tep
    cout<<"Day khoa co trong tep la: ";
    for(i=0;i<n;i++)
    {
        fin>>a[i];
        cout<<a[i]<<" ";
    }

    //Day khoa sau khi sap xep la
    selectionSort(a,n);
    cout<<"\nDay khoa sau khi sap xep la: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
        fout<<a[i]<<"  ";
    }

    //Sap xep chen
    insertSort(a,n);
    cout<<"\nDay khoa sau khi sap xep chen la: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    //Sap xep xui bot
    bubbleSort(a,n);
    cout<<"\nDay khoa sau khi sap xep xui bot la: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

    //Huy mang dong
    delete [] a;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void selectionSort(int *a,int n)
{
    int i,j,k,tg;
    for(i=0;i<n-1;i++)
    {
        k=i;
        //Tim phan tu nho nhat
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[k]) k=j;
        }

        //Doi cho phan tu nho nhat len dau day
        if(k!=i)
        {
            tg=a[k];
            a[k]=a[i];
            a[i]=tg;
        }
    }
}

void insertSort(int *a, int n)
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

void bubbleSort(int *a, int n)
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

void quickSort(int* &a, int L, int R)
{
    if(L>=R) return;

    //Khai bao bien
    int i=L, j=R, k=(L+R)/2, x=a[k], tg;

    do
    {
        //Duyet tu trai sang cho den khi gap phan tu a[i]>=x
        while(a[i]<x) i++;
        //Duyet tu phai sang cho den khi gap phan tu a[j]<=x
        while(a[j]>x) j--;

        //Doi cho ai va aj
        if(i<j)
        {
            tg=a[i];
            a[i]=a[j];
            a[j]=tg;
        }

    }while(i<j);

    //Goi de quy o phan nua ben trai (Khi mà i va j trung nhau tai diem x)
    quickSort(a,L,j-1); // j-1 điểm cuối của phân nửa bên trái
    //Goi de quy o phan nua ben phai
    quickSort(a,j+1,R); // j-1 điểm đầu phân nửa bên phải
}
