/**
*
*@author: [Satyam Koshta]
*@objctive: find out the median of two sorted array without merging them.
*used the concept of binary search
*@algorithm: Divide And Conquer
* 
**/

// this function returns the number of elements lesser than target value
int less_count(vector<int>& nums, int target){
    int st = 0, end = nums.size()-1, mid;
    int ans = 0;
    while(st <= end){
        mid = (st+ end)/2;
        if(nums[mid] >= target) end = mid-1;
        else if(nums[mid] < target){
            ans = mid+1;
            st = mid+ 1;
        }
    }
    return ans;
}

// this function returns the number of elements equal to the target value
int equal_count(vector<int>& nums, int target){
    int st = 0, end = nums.size()-1, mid;
    // next stores the index of element which is just greater than target value
    int next = nums.size();
    while(st <= end){
        mid = (st+ end)/2;
        if(nums[mid] > target){
            next = mid;
            end = mid-1;
        } 
        else if(nums[mid] <= target){
            st = mid+ 1;
        }
    }
    // prev stores the index of element which is just smaller than target value
    int prev =less_count(nums, target);

    // number of equal elements can't be -ve so take max with 0
    return max(0, next - prev );
}

//this function return the kth number after merging two sorted arrays
int k_num(vector<int>& nums1, vector<int>& nums2, int k){
    int st=min(nums1[0], nums2[0]), end = max(nums1.back(), nums2.back());
    int ans, mid, less_nums, equal_nums;
    while(st <= end){
        mid = (st+end)/2;
        less_nums = less_count(nums1, mid) + less_count(nums2, mid);
        // cout<< less_nums<<"\n";
        equal_nums = equal_count(nums1, mid) + equal_count(nums2, mid);
        // cout<< less_nums<<"\n";
        if( less_nums > k) end = mid-1;
        else if( less_nums + equal_nums < k) st = mid+1;
        else{
            ans = mid;
            st= mid+1;
        }   
    }
    return ans;
}
double getMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // if odd numbers then median is A[n/2] 
    // if even numbers in total then midean is (A[(n-1)/2 ] + A[n/2])/2.0
    int n = nums1.size(), m= nums2.size();
    double median;
    if(n==0 && m == 0){
        median =0.0;
    }
    else if(n==0){
        median = (nums2[(m/2)] + nums2[(m-1)/2])/2.00;
    }
    else if(m==0){
        median = (nums1[(n/2)] + nums1[(n-1)/2])/2.00;
    }
    else{
        int val1 = k_num(nums1, nums2, (n+m)/2);
        int val2 = k_num(nums1, nums2, (n+m-1)/2);
        // cout<< val1 <<" "<<val2<<"\n";
        median = (val1 + val2)/2.00;
    }
    return median;
}
