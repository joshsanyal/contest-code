 #include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

long numInv[100100];
int arr[100100];
int a;

void merge(int arr[], int temp[], int left, int mid, int right) {
   int i, j, k;
   i = left;
   j = mid;
   k = left;
   while ((i <= mid - 1) && (j <= right)) {
      if (arr[i] <= arr[j]){
      temp[k++] = arr[i++];
      } else {
         temp[k++] = arr[j++];
         numInv[arr[j-1]] += (mid - i);
      }
   }
   while (i <= mid - 1) temp[k++] = arr[i++];
   while (j <= right) temp[k++] = arr[j++];
   for (i=left; i <= right; i++) arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int left, int right){
   int mid, count = 0;
   if (right > left) {
      mid = (right + left)/2; 
      mergeSort(arr, temp, left, mid); 
      mergeSort(arr, temp, mid+1, right); 
      merge(arr, temp, left, mid+1, right);
   }
}

void arrInversion(int arr[], int n) {
   int temp[n];
   mergeSort(arr, temp, 0, n - 1);
}

int main() {

    ifstream cin("haircut.in");
    ofstream cout("haircut.out");
    
    cin >> a;
    for (int i = 0; i < a; i++) {
    	cin >> arr[i];
    }
    arrInversion(arr, a);

    long long ans = 0;
    for (int i = 0; i < a; i++) {
    	cout << ans << endl;
    	ans += numInv[i];
    }
    
}