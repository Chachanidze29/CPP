/**
 * @param {string} s
 * @return {number}
 */
let  lengthOfLastWord = function(s) {
    let arr = s.split(' ');
    arr = arr.filter(value => value !== '');
    return arr[arr.length - 1].length;
};
