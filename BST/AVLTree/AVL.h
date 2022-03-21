#pragma once
#include<iostream>
using namespace std;

class sNode
{
public:
     int data;
     sNode* left;
     sNode* right;
     sNode() : right(nullptr), left(nullptr) {}
     sNode(int d) : data(d) { sNode(); }
} *avl_root;

class AVL {
     using pNode = sNode*;
     
     // ფუნქცია ახდენს მიმდინარე კვანძისთვის სიმაღლის
     // გამოთვლას და აბრუნებს მიღებულ შედეგს
     int height(pNode node) {          
          if (node == nullptr)
               return 0;  // თუ კვანძი ცარიელია სიმაღლე 0-ის ტოლია
          
          // დავითვალოთ მარცხენა და მარჯვენა კვანძების სიმაღლე
          int l_height = height(node->left);  
          int r_height = height(node->right);
          return max(l_height, r_height) + 1;
     }

     // ფუნქცია მიმდინარე კვანძისთვის პოულობს სხვაობას მარცხენა
     // და მარჯვენა კვანძს შორის და აბრუნებს მიღებულ შედეგს 
     int difference(pNode node) {
          return height(node->left) - height(node->right);
     }

     // მარჯვენა მარჯვენა მობრუნება
     pNode rr_rotat(pNode parent) {
          pNode tmp_node = parent->right;  
          parent->right = tmp_node->left;
          tmp_node->left = parent;
          return tmp_node;
     }

     // მარცხენა მარცხენა მობრუნება
     pNode ll_rotat(pNode parent) {
          pNode tmp_node = parent->left;
          parent->left = tmp_node->right;
          tmp_node->right = parent;
          return tmp_node;
     }

     // მარცხენა მარჯვენა მობრუნება
     pNode lr_rotat(pNode parent) {
          pNode tmp_node = parent->left;
          parent->left = rr_rotat(tmp_node);  
          return ll_rotat(parent);
     }
     
     // მარჯვენა მარცხენა მობრუნება
     pNode rl_rotat(pNode parent) {
          pNode tmp_node = parent->right;
          parent->right = ll_rotat(tmp_node);
          return rr_rotat(parent);
     }

     pNode balance(pNode node) {
          int node_diff = difference(node);
          if (node_diff > 1) {
               if (difference(node->left) > 0)
                    node = ll_rotat(node);
               else
                    node = lr_rotat(node);
          } else if (node_diff < -1) {
               if (difference(node->right) > 0)
                    node = rl_rotat(node);
               else
                    node = rr_rotat(node);
          }
          return node;
     } 
public:

     AVL() = default;

     // ფუნქცია ამოწმებს ელემენტის არსებობას სტრუქტურაში
     bool check(const int& item) const {
          pNode curr = avl_root;
          bool found = false;

          while (!found && curr != 0) {
               if (item < curr->data)
                    curr = curr->left;
               else if (item > curr->data)
                    curr = curr->right;
               else
                    found = true;
          }
          return found;
     }
          
     pNode push(pNode node, int value) {
          if (node == nullptr)
               return new sNode(value);

          if (value < node->data) {
               node->left = push(node->left, value);
               node = balance(node);
          }
          else if (value >= node->data) {
               node->right = push(node->right, value);
               node = balance(node);
          }
          return node;
     }

     // ფუნქცია ახდენს სტრუქტურის ბეჭდვას ერთიდაიმავე სიმაღლეზე
     // განთავსებული კვანძების ვერტიკალური მითითებით
     void show(pNode node, int l = 1) {
          int i;
          if (node != nullptr)  {
               show(node->right, l + 1);
               cout << " ";
               if (node == avl_root)
                    cout << "Root -> ";
               for (i = 0; i < l && node != avl_root; i++)
                    cout << "\t";
               cout << node->data;
               show(node->left, l + 1);
          }
          cout << endl;
     }

     // სიმრავლის შემოვლა პრინციპით: left, root, right
     void inorder(pNode node) {
          if (node == nullptr)
               return;
          inorder(node->left);
          cout << node->data << " ";
          inorder(node->right);
     }

     // სიმრავლის შემოვლა პრინციპით: root, left, right
     void preorder(pNode node) {
          if (node == nullptr)
               return;
          cout << node->data << " ";
          preorder(node->left);
          preorder(node->right);
     }
     
     // სიმრავლის შემოვლა პრინციპით: left, right, root
     void postorder(pNode node) {
          if (node == nullptr)
               return;
          postorder(node->left);
          postorder(node->right);
          cout << node->data << " ";
     }
};