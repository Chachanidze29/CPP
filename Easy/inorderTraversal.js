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
 * @return {number[]}
 */

let inorderTraversal = function(root) {
    let res = [];
    inorder(root,res)
    return res;
};

let inorder = (root,res) => {
    if(root) {
        inorderTraversal(root.left);
        res.push(root.val);
        inorderTraversal(root.right);
    }
}

