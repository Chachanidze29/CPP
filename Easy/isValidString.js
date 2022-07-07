Object.defineProperty(Array.prototype,'last', {
    value: function () {
        return this[this.length - 1];
    }
})

Object.defineProperty(Array.prototype,'first', {
    value: function () {
        return this[0];
    }
})

let isValid = function (s) {
    const leftSymbols = [];
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(' || s[i] === '{' || s[i] === '[') {
            leftSymbols.push(s[i]);
        }
        else if (s[i] === ')' && leftSymbols.length !== 0 && leftSymbols.last() === '(') {
            leftSymbols.pop();
        } else if (s[i] === '}' && leftSymbols.length !== 0 && leftSymbols.last() === '{') {
            leftSymbols.pop();
        } else if (s[i] === ']' && leftSymbols.length !== 0 && leftSymbols.last() === '[') {
            leftSymbols.pop();
        }
        else {
            return false;
        }
    }
    return leftSymbols.length === 0;
};

let helper = {
    ")":"(",
    "}":"{",
    "]":"["
};

let isValid2 = str => {
    let arr = [];
    for (let s of str) {
        if(s in helper) {
            if(arr.length !== 0 && arr.last() === helper[s]) {
                arr.pop();
            } else {
                return false;
            }
        } else {
            arr.push(s);
        }
    }
    return arr.length === 0;
}

