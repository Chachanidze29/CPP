/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
let isSymmetric = function(root) {
    let left = root.left;
    let right = root.right;
    let stack = [[left,right]];
    while(stack.length !== 0) {
        [left,right] = stack.pop();
        if(left && right && left.val === right.val) {
            stack.push([left.left,right.left],[left.right,right.right]);
        } else if(left || right) {
            return false;
        }
    }

    return true;
};