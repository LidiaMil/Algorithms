#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> create_vec(int n) //заполнение массива рандомными числами
{
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		vec[i] = rand() % 100 + 0;
	}
	return vec;
}

void sort(int n, vector<int> &vec) //сортировка
{
	for (int s = n / 2; s > 0; s /= 2) {
		for (int i = s; i < n; ++i) {
			for (int j = i - s; j >= 0 && vec[j] > vec[j + s]; j -= s) {
				swap(vec[j], vec[j + s]);
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	int n1 = 2000, n2 = 5000, n3 = 6800; 
	vector <int> vec1(n1); vector <int> vec2(n2); vector <int> vec3(n3);
	vec1 = create_vec(n1); vec2 = create_vec(n2); vec3 = create_vec(n3);

	auto start = chrono::high_resolution_clock::now();
	sort(n1, vec1);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << endl << n1 << " - " << duration.count() << "s";

	start = chrono::high_resolution_clock::now();
	sort(n2, vec2);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << endl << n2 << " - " << duration.count() << "s";

	start = chrono::high_resolution_clock::now();
	sort(n3, vec3);
	end = chrono::high_resolution_clock::now();
	duration = end - start;
	cout << endl << n3 << " - " << duration.count() << "s"<<endl<<endl;

	for (int i = 1000; i <= 30000; i += 1000) {  //для графика
		vector <int> vec(i);
		vec = create_vec(i);
		auto start = chrono::high_resolution_clock::now();
		sort(i, vec);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> duration = end - start;
		cout << endl << i<<" - "<<duration.count()<< "s";
		/*cout<< duration.count()<<"; ";*/
	}
	return 0;
}
