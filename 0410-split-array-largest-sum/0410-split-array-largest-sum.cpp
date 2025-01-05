class Solution {
public:
  int func(vector<int>& arr, int n, int pages){
     int stud =1;
     long long noOfPages =0;
     for(int i=0; i<n; i++){

         if(noOfPages + arr[i] <= pages){
             noOfPages += arr[i];
         }else{
             stud++;
             noOfPages = arr[i];
         }
     }
     return stud;
 }


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    int high = sum;

    while(low <= high){
        int mid = (low+high)/2;
        int noOfStud = func(arr, n, mid);
        if(noOfStud > m){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, nums.size(), k);
        
    }
};