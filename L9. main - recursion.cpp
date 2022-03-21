#include <iostream>
using namespace std;

// 1. დაწერეთ რეკურსიული ფუნქცია, რომელიც დაითვლის მასივის ელემენტების ჯამს
int Sum(int* arr, int curr_el, int el_count, int summ = 0)
{
     if (curr_el == el_count - 1)
          return summ + arr[curr_el];
     return arr[curr_el] + Sum(arr, curr_el + 1, el_count, summ);
}

// 2. დაწერეთ რეკურსიული ფუნქცია, რომელიც მასივში დაითვლის მითითებულ
//    მნიშვნელობის ტოლი მნიშვნელობის მქონე ელემენტების რაოდენობა
int Count(int arr[], int val, int curr_el, int el_count)
{
     if (curr_el == el_count)
          return 0;
     if (arr[curr_el] == val)
          return Count(arr, val, curr_el + 1, el_count) + 1;
     return Count(arr, val, curr_el + 1, el_count);
}

// 3. დაწერეთ რეკურსიული ფუნქცია, რომელიც დაითვლის რიცხვის ფაქტორიალს
int Fact1(int n, int i = 1)
{
     if (i == n)
          return i;     
     return i * Fact1(n, i + 1);
}

int Fact2(int n)
{
     if (n == 1)
          return 1;
     return n * Fact2(n - 1);
}

// 4. დაწერეთ რეკურსიული ფუნქცია, რომელიც რიცხვის ფიბონაჩის მნიშვნელობას
int Fib(int n)
{
     if (n <= 1)
          return n;
     return Fib(n - 1) + Fib(n - 2);
}

// 5. დაწერეთ რეკურსიული ფუნქცია, რომელიც იპოვის ორი რიცხვის უდიდეს საერთო გამყოფს
//
//           | n          , თუ  n = m
// f(n, m) = | f(n-m, m)  , თუ  n > m
//           | f(n, m-n)  , თუ  n < m
//
int USG(int n, int m)
{
     if (n == m)
          return n;
     if (n > m)
          return USG(n - m, m);
     return USG(n, m - n);
}

const int N = 10;
int main() {
     int arr[N];
     for (int i = 0; i < N; i++)
          arr[i] = rand() % 10;

     int ind = 0, val = 5;
     cout << "- - - - - - - - - - - - - - - - - - - - - - - \n\n";
     cout << "sum = " << Sum(arr, ind, N) << endl;
     cout << "sum = " << Sum(arr, ind, N, 10) << endl;

     cout << "- - - - - - - - - - - - - - - - - - - - - - - \n\n";
     cout << "el count " << Count(arr, val, ind, N) << endl;
	
     cout << "- - - - - - - - - - - - - - - - - - - - - - - \n\n";
     cout << "fact1(5) = " << Fact1(5) << endl << endl;
	 cout << "multiplication integers from range [5, 7] " << endl;
     cout << "fact1(7, 5) = " << Fact1(7, 5) << endl << endl;
     cout << "fact2(5) = " << Fact2(5) << endl;
	
     cout << "- - - - - - - - - - - - - - - - - - - - - - - \n\n";
     cout << "Fib(5) = " << Fib(5) << endl;

     cout << "- - - - - - - - - - - - - - - - - - - - - - - \n\n";
     cout << "USG(256, 1656) = " << USG(256, 1656) << endl;
	
     return 0;
}