/**
 * @param {number} x
 * @return {number}
 */
let mySqrt = function(x) {
    return binarySearch(x);
};

let binarySearch = num => {
    let start = 0;
    let end = num;
    let mid = start + Math.floor((end-start)/2);

    let res = -1;
    while(start <= end) {
        let square = mid * mid;
        if(square === num) {
            res = mid;
            break;
        }
        else if(square > num) {
            end = mid  - 1;
        }else {
            res = mid;
            start = mid + 1;
        }
        mid = start + Math.floor((end-start)/2);
    }
    return res;
}

