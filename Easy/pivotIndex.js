let pivotIndex = function(nums) {
    const sum = nums.reduce((acc,el)=>acc + el,0)
    let prefix = 0;
    for(let i=0;i<nums.length;i++) {
        if(prefix === sum - (prefix + nums[i])) {
            return i;
        }
        prefix += nums[i];
    }
    return -1;
};

