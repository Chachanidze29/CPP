// Min Heap -ის იმპლემენტაცია ვექტორის მეშვეობით
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

template <typename dType>
class Heap
{
     vector <dType> heap;      // დინამიური ვექტორი მონაცემების შესანახად
     unsigned size;            // ელემენტების რაოდენობა

     void heapify_up(int cIndex) {
          // ფუნქცია ახდენს ქვემოდან ზემოთ მიმართულებით Min Heap -ის 
          // პრინციპის გათვალისწინებით ელმენტების დალაგებას ბინარულ ხეზე
          int pIndex = cIndex / 2; // განვსაზღვროთ მშობელი კვანძის ინდექსი
          if (cIndex >= 0 && pIndex >= 0 && heap[pIndex] > heap[cIndex]) {
               swap(heap[cIndex], heap[pIndex]);
               heapify_up(pIndex); // რეკურსიულად გამოვიძახოთ ფუნქცია მშობლის ინდექსით
          }
     }
     void heapify_down(int pIndex) {
          // ფუნქცია ახდენს ზემოდან ქვემოთ მიმართულებით Min Heap -ის 
          // პრინციპის გათვალისწინებით ელმენტების დალაგებას ბინარულ ხეზე
          int p = 2 * pIndex;
          int      // განვსაზღვროთ მარცხენა და მარჯვენა შვილობილი კვანძის ინდექსი
               left = p < size ? p : -1,
               right = p + 1 < size ? p + 1 : -1;

          if (left >= 0 && right >= 0 && heap[left] > heap[right])
               left = right;

          if (left > 0) {
               swap(heap[pIndex], heap[left]);
               heapify_down(left); // რეკურსიულად გამოვიძახოთ ფუნქცია შვილის ინდექსით
          }
     }

     dType getMin() const {
          return size == 0 ? -1 : heap.front();
     }

public:
     Heap() : size(0) {}

     void Insert(dType element) {
          // ფუნქცია Min Heap -ში ამატებს ახალი ელემენტს
          heap.push_back(element);
          // ელემენტი ემატება სიმრავლის ბოლოში და შემდეგ 
          // ხდება მისთვის შესაბამის ადგილას გადატანა
          heapify_up(size++); // გავზარდოთ ელემენტების რაოდენობა
     }

     void popMin() {
          // ფუნქცია შლის Min Heap -ის წვეროს
          if (size == 0) {
               cout << "Heap is Empty" << endl;
               return;
          }

          // Heap -ის წვეროს წაშლის მიზნით მოვახდინოთ ბოლო
          // ელემენტის თავში გადმოტანა			
          heap[0] = heap[--size];
          heap.pop_back();   // წავშალოთ სიმრავლის ბოლო ელემენტი
          // მოვახდინოთ პირველი ელემენტის შესაბამის ადგილას გადატანა
          heapify_down(0);
     }

     friend ostream& operator<<(ostream& out, const Heap<dType>& obj) {
          if (obj.size > 0) {

               out << "Number of elements in Heap: "
                    << obj.size << endl;
               out << "Root of Heap: " << obj.getMin() << endl;
               out << "Elements of Heap: \n    ";
               for (int pos : obj.heap)
                    out << pos << " ";
          }
          else {
               out << "Heap is empty!\n";
          }
          out << endl;
          return out;
     }
};
void fill(Heap<int>& obj, unsigned size = 15) {
     for (int i = 0; i < size; i++)
          obj.Insert(rand() % 100 + 1);
}

int main() {
     // main ფუნქციაში იქმნება Heap კლასის რამდენიმე ეგზემპლარი, რომელიც ივსება 
     // შემთხვევითი პრინციპით მიღებული მნიშვნელობებისგან. ეგზემპლარიდან ხდება 
     // ორი მნიშვნელობის ამოშლა. იბეჭდება ეგზემპლარი ელემენტის ამოშლამდე და მის შემდეგ

     srand(time(nullptr));

     for (int i = 0; i < 5; i++) {
          Heap<int>h;
          fill(h);
          cout << "* * * * * * * * * * * * * * * * * * * * * * * * \n\n";
          cout << "Before Deleting:\n" << h;
          cout << "\n- - - - - - - - - - - - - - - - - - - - - - -\n\n";
          h.popMin();
          h.popMin();
          cout << " After Deleting:\n" << h <<"\n\n";
     }

     return 0;
}
