const spiralOrder = matrix => {
    let row = 0;
    let col = 0;
    let rowEnd = matrix.length - 1;
    let colEnd = matrix[0].length - 1;
    let res = [];

    while (col <= colEnd && row <= rowEnd) {
        // start row
        for (let i = col; i <= colEnd; i++) {
            res.push(matrix[row][i]);
        }
        row++;

        // end column
        for (let i = row; i <= rowEnd; i++) {
             res.push(matrix[i][colEnd]);
        }
        colEnd--;

        // end row
        if (row <= rowEnd) {
            for (let i = colEnd; i >= col; i--) {
                res.push(matrix[rowEnd][i]);
            }
            rowEnd--;
        }

        // First col from end
        if (col <= colEnd) {
            for (let i = rowEnd; i >= row; i--) {
                res.push(matrix[i][col]);
            }
            col++;
        }
    }

    return res;
}
