/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
let isSameTree = function(p, q) {
    let stack = [[p,q]];
    while(stack.length !== 0) {
        [p,q] = stack.pop();
        if(p && q && p.val === q.val) {
            stack.push([[p.left,q.left],[p.right,q.right]]);
        }
        else if (p || q) return false;
    }

    return true;
};

let isSameTree2 = function(p, q) {
    if(!p && !q) return true;
    if(!q || !p) return false;
    if(p.val !== q.val) return false;
    return isSameTree(p.right,q.right) && isSameTree(p.left,q.left)
};