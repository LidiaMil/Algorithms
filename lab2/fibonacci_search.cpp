#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> create_vec(int n) // заполнение массива числами от 1 до n(по возр.)
{
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = i;
    }
    return vec;
} 
int min(int x, int y) { return (x <= y) ? x : y; } //вспомогательная функция
int fibMonaccianSearch(vector<int> arr, int x, int n) //поиск Фибоначчиев
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);
        if (arr[i] < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        else return i;
    }
    if (fibMMm1 && arr[offset + 1] == x)return offset + 1;
    return -1;
}
int main()
{
    srand(time(NULL));
    int x = 500;
    int n1 = 1500, n2=3500, n3=6000;
    vector <int> vec1(n1), vec2(n2), vec3(n3);
    vec1 = create_vec(n1); vec2 = create_vec(n2); vec3 = create_vec(n3);

    auto start = chrono::high_resolution_clock::now();
    /*cout<<(fibMonaccianSearch(vec1, x, n1));*/
    fibMonaccianSearch(vec1, x, n1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << endl << n1 << " - " << duration.count() << "s";

    start = chrono::high_resolution_clock::now();
    /*cout << (fibMonaccianSearch(vec2, x, n2));*/
    fibMonaccianSearch(vec1, x, n1);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << endl << n2 << " - " << duration.count() << "s";

    start = chrono::high_resolution_clock::now();
    /*cout << (fibMonaccianSearch(vec3, x, n3));*/
    fibMonaccianSearch(vec1, x, n1);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << endl << n3 << " - " << duration.count() << "s" << endl << endl;

    for (int i = 1000; i <= 30000; i += 1000) { //для графика
        vector <int> vec(i);
        vec = create_vec(i);
        auto start = chrono::high_resolution_clock::now();
        fibMonaccianSearch(vec, x, i);
        /*cout << " Index " << fibMonaccianSearch(vec, x, vec.size()) << "  ";*/
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        cout << i << " - " << duration.count() << "s"<<endl;
        /*cout<< duration.count()<<"; ";*/
    }
    return 0;
}

