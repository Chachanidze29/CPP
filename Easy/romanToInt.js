const helper = {
    "I":             1,
    "V":             5,
    "X":             10,
    "L":             50,
    "C":             100,
    "D":             500,
    "M":             1000,
};

let romanToInt = roman => {
    let res = 0;
    for(let i=0;i<roman.length;i++) {
        if(roman[i] === 'X' && (roman[i+1] === "L" || roman[i+1] === "C") || roman[i] === 'C' && (roman[i+1] === "D" || roman[i+1] === "M") || roman[i] === 'I' && (roman[i+1] === "V" || roman[i+1] === "X")) res-=helper[roman[i]];
        else res+=helper[roman[i]];
    }
    return res;
}
