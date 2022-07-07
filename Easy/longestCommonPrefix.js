/**
 * @param {string[]} strs
 * @return {string}
 */
let longestCommonPrefix = function(strs) {
    let prefix = strs[0];
    for(let i=0;i<strs.length;i++) {
        while(strs[i].indexOf(prefix) !== 0) {
            prefix = prefix.substring(0,prefix.length - 1);
            if(!prefix) return "";
        }
    }
    return prefix;
};
