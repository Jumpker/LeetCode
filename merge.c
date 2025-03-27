void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int arr[m+n], a=0, b=0;
    for(int i=0; i<m+n; i++){
        if(a < m && (b >= n || nums1[a] <= nums2[b])){
            arr[i]=nums1[a];
            a++;
        }
        else{
            arr[i]=nums2[b];
            b++;
        }
    }
    for(int i=0; i<m+n; i++){
        nums1[i] = arr[i];
    }
}