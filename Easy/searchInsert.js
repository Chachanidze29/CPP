
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
let searchInsert = function(nums, target) {
    let ind = nums.indexOf(target);
    if(ind !== -1) return ind;

    let res = 0;
    for(let i=0;i<nums.length;i++) {
        if(target > nums[i]) {
            res = i + 1;
        }
    }
    return res;
};

let searchInsert2 = (nums,target)=> {
    return binarySearch(nums,0,nums.length - 1,target);
}

let binarySearch = (arr,start,end,search)=> {
    if(start > end) return start;

    let mid = start + Math.floor((end - start)/2);

    if(search === arr[mid]) {
        return mid;
    }
    else if(search > arr[mid]) {
        return binarySearch(arr,mid+1,end,search);
    }
    else {
        return binarySearch(arr,start,mid-1,search);
    }
}