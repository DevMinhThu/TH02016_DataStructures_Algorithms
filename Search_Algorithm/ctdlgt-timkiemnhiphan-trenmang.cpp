/*
#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

int binarySearch(int *a, int n, int x);//tim kiem nhi phan tren mang

//===chuong trinh chinh===
int main()
{
    //Khai bao tep doc vao
    ifstream fin("daykhoatimkiem.txt");

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

    //Tim kiem
    cout<<"\n\nNhap phan tu x can tim: "; cin>>x;

    int kq = binarySearch(a,n,x);

    //xuat ra gia tri can tim
    if(kq)
        printf("\n\nTim thay %d trong day khoa tai vi tri %d: ",x,kq);
    else
        printf("\n\nKhong tim thay %d trong day khoa",x);

    //Huy mang dong
    delete [] a;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
int binarySearch(int *a, int n, int x)
{
    //1.khoi tao
    int L=0, R=n-1, m;

    //2.tim kiem
    while(L<=R)
    {
        //3.tinh chi so m
        m = (L+R)/2;
        if(x<a[m]) // Nếu giá trị x nhập vào mà NHỎ hơn giá trị ở giữa thì tìm BÊN TRÁI
            R=m-1; // Khi tìm bên trái, vị trí con trỏ L vẫn giữ nguyên, Nhưng R phải chuyển đến vị trí m-1 để tìm x ở phần mảng bên trái
        else
            if(x>a[m]) // Nếu giá trị x nhập vào mà LỚN hơn giá trị ở giữa thì tìm BÊN PHẢI
                L=m+1; // Khi tìm bên phải, vị trí con trỏ R vẫn giữ nguyên, Nhưng L phải chuyển đến vị trí m+1 để tìm x ở phần mảng bên phải
            else return m+1;
    }
    return 0;
}
*/


#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

//Khai bao ham cai dat giai thuat tim kiem nhi phan
int binarySearch(int *a, int n, int x);

//===chuong trinh chinh===
int main()
{
    //Khai bao tep day khoa
    ifstream fin("daykhoadasapxep.txt");

    //Khai bao bien
    int i,n,x;

    //Doc so luong phan tu tu day khoa
    fin>>n;

    //Khai bao mang dong
    int *a = new int[n];

    //Day khoa tu tep la:
    cout<<"Cac phan tu trong tep la: \n";
    for(i=0;i<n;i++)
    {
        fin>>a[i];
        cout<<a[i]<<"  ";
    }

    //Nhap phan tu can tim
    cout<<"\nNhap phan tu can tim: "; cin>>x;

    int kq = binarySearch(a,n,x);

    if(kq)
        printf("\n\nTim thay %d trong day khoa tai vi tri %d: ",x,kq);
    else
        printf("\n\nKhong tim thay %d trong day khoa",x);

    //Huy mang dong
    delete [] a;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
int binarySearch(int *a, int n, int x)
{
    //1.Khoi tao
    int L=0, R=n-1, m;

    //2.Tim kiem
    while(L<=R)
    {
        //3.Tinh chi so m
        m = (L+R)/2;
        if(x<a[m])
            R=m-1;
        else
            if(x>a[m])
                L=m+1;
            else return m+1;
    }
    return -1;
}

















