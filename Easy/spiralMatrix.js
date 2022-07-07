const spiralMatrix = n => {
    const arr = Array.from({ length: n }, () => []);
    console.log(arr);
    let row = 0, col = 0;
    let rowEnd = n - 1, colEnd = n - 1;
    let counter = 1;
    while (col <= colEnd && row <= rowEnd) {

        // Top row & middle value (Where col === colEnd && row === rowEnd)
        for (let i = col; i <= colEnd; i++) {
            arr[row][i] = counter;
            counter++;
        }
        row++;

        // end column
        for (let i = row; i <= rowEnd; i++) {
            arr[i][colEnd] = counter;
            counter++;
        }
        colEnd--;

        // end row
        for (let i = colEnd; i >= col; i--) {
            arr[rowEnd][i] = counter;
            counter++;
        }
        rowEnd--;

        // First col from end
        for (let i = rowEnd; i >= row; i--) {
            arr[i][col] = counter;
            counter++;
        }
        col++;
    }
    return arr;
}

console.log(spiralMatrix(4));