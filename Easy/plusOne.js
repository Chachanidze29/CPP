let plusOne = digits => {
    let N = digits.length;
    if(digits[N-1] < 9) {
        digits[N-1]++;
        return digits;
    }
    else {
        let i = N-1;
        while(i >= 0) {
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }else {
                digits[i] = 0;
            }
            i--;
        }
        digits.unshift(1);
    }
    return digits;
}

let plusOne2 = digits => {
    let digs = digits.join('');
    let num = (BigInt(digs) + BigInt(1)).toString();
    for(let i=0;i<num.length;i++) {
        digits[i] = parseInt(num[i]);
    }
    return digits;
}


