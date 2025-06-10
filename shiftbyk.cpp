//temp[(i+k)%n] = arr[i];
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        vector<int> temp(n);
        for(int i=0;i<arr.size();i++){
            temp[i]=arr[(i+d)%n];
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=temp[i];
        }
    }
};
