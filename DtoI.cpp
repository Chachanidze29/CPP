#include <iostream>
#include <string>
#include<chrono>
#include <fstream>
using namespace std;
int main()
{
    auto st = chrono::high_resolution_clock::now();
    string a = "-456.2e-1";
    int s = a.size();
    int n;
    static int m = 0;
    int wertili = 0;
    int e;
    double ee = 0;
    int uary = 1;
    for (size_t i = 1; i <= s; i++)
    {
        static int xa = 1, we = 1;

        if (a[s - i] != '.' && a[s - i] != 'e' && a[s - i] != '-')
        {
            n = a[s - i] - 48;//char-ის int-ად გადაქცევა 
            n = n * pow(10, (i - xa));//ინდექსის მიხედვით აგმრავლება
            m = m + n;//m-ში იწერება თვითონ ინტი
        }

        else if (s - i == 0 && a[s - i] == '-')uary = -1;//თავში თუ მინუსი უწერია უარყოფითია

        else if (a[s - i] == 'e')
        {
            e = i - 1;
            xa += 2;
            we += 2;//რატო მართლა ვერ გავიგე
            ee = m;//რა ხარისხშიც უნდა ავიდეს
            //cout << m << endl;
            m = 0;

            if (a[s - i + 1] == '-')//თუ e-ს მერე მინუსია
            {
                //cout << ee << endl;
                ee = -ee;
                //cout << ee << endl;
                //cout << "minusi  " << pow(10, ee) << endl;
                xa++;
                we++;
            }
        }
        else if (a[s - i] == '.')
        {
            wertili = i - we;
            //cout << " tviton wer  " << wertili << endl;
            xa++;
        }
    }
    //cout << " m " << m << endl;
    //cout << "wert  " << (m / pow(10, wertili)) << endl;
    //double pas = (m / pow(10, wertili)) * pow(10, ee) * uary;

    double asd = (m / pow(10, wertili)) * pow(10, ee) * uary;
    //fstream  asdd("Text.txt") ;
    //asdd << asd;
    auto diff = chrono::high_resolution_clock::now() - st;
    auto time = chrono::duration_cast<chrono::microseconds>(diff);
    cout << " time : " << time.count() << endl;
}