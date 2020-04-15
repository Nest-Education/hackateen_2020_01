#include <iostream>
using namespace std;

int main() {
  int n, sum = 0;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i]; 
    sum += a[i];
  }  
  int left = 0, right = n-1, leftSum = 0, rightSum = 0;
  while(left <= right){
    if(leftSum == rightSum && left == right){
        cout << left << "\n";
        break;
    }
    if(leftSum < rightSum){
      leftSum += a[left++]; 
    }else if(leftSum > rightSum){
      rightSum += a[right--]; 
    }else{
      if(a[left] < a[right]) leftSum += a[left++];
      else rightSum += a[right--];
    }
  }
  if(left != right) cout << "invalid" << "\n";
  return 0;
}