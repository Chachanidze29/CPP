/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
let strStr = function(haystack, needle) {
    let hl = haystack.length;
    let nl = needle.length;

    if(nl === 0) return 0;
    if(haystack === needle) return 0;
    for(let i=0;i<hl;i++) {
        if(i + nl < hl) {
            if(haystack.substring(i,i+nl) === needle) return i;
        }
    }
    return -1;
};

