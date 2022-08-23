#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
int LinearSearch(int a[], int n, int x);

int main()
{
    // Khoi tao va nhap kich thuoc cua mang
    int n;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &n);
    // Khoi tao, xuat, nhap mang
    int a[n];
    NhapMang(a, n);
    XuatMang(a, n);
    // Khoi tao va nhap so can tim
    int x;
    printf("\nNhap so can tim: ");
    scanf("%d", &x);
    // Tim so can tim bang thuat toan tim kiem tuyen tinh
    int k = LinearSearch(a, n, x);
    if(k == -1)
        printf("\nKhong tim thay");
    else
        printf("\nx = %d o vi tri %d", x, k);
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

int LinearSearch (int a[], int n, int x){
    for(int i = 0; i < n; i++)
        if(a[i] == x)
            return i;
    return -1;
}
