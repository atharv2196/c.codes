void selectionsort(int arr[],int n){
    
    for(int i=0;i<n-1;i++){
    int smallestindex=i;
    //unsorted partstarting
    
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[smallestindex]){
            smallestindex=j;
        }
    }
    swap(arr[i],arr[smallestindex]);
}}
//time complexity: O(n^2) in the worst case, O(n^2) in the best case
//space complexity: O(1) as it sorts in place
//working: The algorithm divides the input list into two parts: a sorted part and an unsorted part. It repeatedly selects the smallest (or largest) element from the unsorted part
//and moves it to the end of the sorted part. The process continues until the entire list is sorted.