#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PhatSinhMang(int a[], int n);
void XuatMang(int a[], int n);
float Sort(int a[], int n);
float LinearSearch(int a[], int n, int x);
float BinarySearch(int a[], int x, int left, int right);
void HoanVi(int x, int y);

int main()
{
    int n = 100000;

    int a[n];
    PhatSinhMang(a, n);
    XuatMang(a, n);

    int x;
    printf("\nNhap so can tim: ");
    scanf("%d", &x);

    float LinearTime = LinearSearch(a, n, x);
    printf("%f", LinearTime);
    printf("\n");
    float BinaryTime = BinarySearch(a, x, 0, n-1) + Sort(a, n);
    printf("%f", BinaryTime);
    return 0;
}

void PhatSinhMang(int a[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        a[i] = rand();
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

float Sort(int a[], int n){
    clock_t start, end;
    start = clock();
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(a[i] > a[j])
                HoanVi(a[i], a[j]);
    end = clock();
    double t = end - start;
    return t;
}

float BinarySearch(int a[], int x, int left, int right){
    clock_t start, end;
    start = clock();
    if(left <= right){
        int mid = (left + right) / 2;
        if(a[mid] == x){
            end = clock();
            double t = end - start;
            return t;
        }
        if(a[mid] < x)
            return BinarySearch(a, x, mid + 1, right);
        if(a[mid] > x)
            return BinarySearch(a, x, left, mid - 1);
    }
    end = clock();
    double t = end - start;
    return t;
}

float LinearSearch (int a[], int n, int x){
    clock_t start, end;
    start = clock();
    for(int i = 0; i < n; i++)
        if(a[i] == x){
            end = clock();
            double t = end - start;
            return t;
        }
    end = clock();
    double t = end - start;
    return t;
}
