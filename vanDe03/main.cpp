#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
void Sort(int a[], int n);
int BinarySearch(int a[], int x, int left, int right);
void HoanVi(int x, int y);

int main()
{
    //Khai bao va nhap kich thuoc mang
    int n;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &n);
    //Khai bao, xuat, nhap mang
    int a[n];
    NhapMang(a, n);
    XuatMang(a, n);
    //Khai bao va nhap so can tim
    int x;
    printf("\nNhap so can tim: ");
    scanf("%d", &x);
    //Sap xep mang tang dan va xuat mang
    Sort(a, n);
    XuatMang(a, n);
    //Tim so can tim bang thuat toan tim kiem nhi phan
    int k = BinarySearch(a, x, 0, n-1);
    if(k == -1)
        printf("\nKhong tim thay");
    else
        printf("\nx = %d nam o vi tri %d", x, k);
    return 0;
}

void NhapMang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void XuatMang(int a[], int n){
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void HoanVi(int x, int y){
    int tg = x;
    x = y;
    y = tg;
}

void Sort(int a[], int n){
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(a[i] > a[j])
                HoanVi(a[i], a[j]);
}

int BinarySearch(int a[], int x, int left, int right){
    if(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == x)
            return mid;
        if(a[mid] < x)
            return BinarySearch(a, x, mid + 1, right);
        if(a[mid] > x)
            return BinarySearch(a, x, left, mid - 1);
    }
    return -1;
}

