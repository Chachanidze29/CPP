let isPalindrome = num => {
    let strNum = num.toString();
    const len = strNum.length;
    for(let i=0;i<Math.floor(len/2);i++) {
        if(strNum[i] !== strNum[len-1-i]) return false;
    }
    return true;
}

let reverseNum = num => {
    let reversed = 0,remainder;
    while(num!==0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = Math.floor(num/10);
    }
    return reversed;
}

let isPalindrome2 = num => {
    let reversed = reverseNum(num);
    return num === reversed;
}

console.log(isPalindrome2(121));