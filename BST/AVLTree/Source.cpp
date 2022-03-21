#include "AVL.h"
#include <ctime>
#include <vector>
#include <iostream>

void print(vector<int>& vec) {
     for (auto el : vec)
          cout << el << " ";
     cout << endl;
}

int main()
{
     srand(time(nullptr));         
     int 
          elNumber,     // ცვლადი ხეში ჩასამატებელი ელემენტების რაოდენობის მისათითებლად
          elCount = 0;  // ცვლადი, რომელიც დაითვლით ხეში ჩამატებული ელემენტების რაოდენობას

     // შემოვიტანოთ ვექტორი, რომელსაც გამოვიყენებთ ელემენტების შეტანის მიმდევრობის შესანახად 
     vector<int> vec_numb;
     
     while (true) {
          cout << "How many random number insert into AVL Structure: \n";
          cout << "elNumber = ";
          cin >> elNumber;

          // მოვახდინოთ სტრუქტურის შევსება ელემენტების მითითებული რაოდენობით
          int tmp_numb;
          AVL avl_tree;
          while (elNumber != elCount) {
               tmp_numb = rand() % 100 + 1;   // დავაგენერიროთ შემთხვევითი რიცხვი

               if (!avl_tree.check(tmp_numb)) {                     // თუ ელემენტი არ იძებნება სტრუქტურაში
                    avl_root = avl_tree.push(avl_root, tmp_numb);   // ჩავამატოთ ელემენტი სტრუქტურაში
                    // დაგენერირებული რიცხვების თანმიმდევრობის განსაზღვრის მიზნით ისინი შევინახოთ ვექტორში
                    vec_numb.push_back(tmp_numb);  
                    elCount++;
               }
          }

          // მოვახდინოთ სხვადასხვა ფუნქციების დატესტვა მიმდინარე სტრუქტურაზე
          do  {
               cout << "1. show Balanced AVL Tree" << endl;
               cout << "2. InOrder traversal" << endl;
               cout << "3. PreOrder traversal" << endl;
               cout << "4. PostOrder traversal" << endl;
               cout << "5. Exit" << endl;
               cout << "Enter your Choice: ";
               cin >> elNumber;
               switch (elNumber)  {
               case 1:                   
                    if (avl_root == NULL) {
                         cout << "Tree is Empty" << endl;
                         continue;
                    }

                    cout << "Numbers was entered in order: \n\t";
                    print(vec_numb);

                    cout << "\nBalanced AVL Tree:" << endl;
                    avl_tree.show(avl_root);
                    cout << endl;
                    break;
               case 2:
                    cout << "Inorder Traversal:" << endl;
                    avl_tree.inorder(avl_root);
                    cout << endl;
                    break;
               case 3:
                    cout << "Preorder Traversal:" << endl;
                    avl_tree.preorder(avl_root);
                    cout << endl;
                    break;
               case 4:
                    cout << "Postorder Traversal:" << endl;
                    avl_tree.postorder(avl_root);
                    cout << endl;
                    break;
               case 5:
                    break;
               default:
                    cout << "Enteres value not valid!" << endl;
               }
          } while (elNumber != 5);

          // განვსაზღვროთ ციკლის გაჩერების პირობა
          cout << "Enter -1 to Exit: ";
          cin >> elNumber;
          if (elNumber == -1)
               break;

          elCount = 0;       // გავანულოთ ხეში ელემენტების რაოდენობის მთვლელი
          vec_numb.clear();  // გავასუფთაით ვექტორი
     }

     return 0;
}

