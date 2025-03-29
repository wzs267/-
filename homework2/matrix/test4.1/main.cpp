#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
#include <chrono>   // for timing the execution

using namespace std;
using namespace std::chrono;

void ordinaryMethod(int n) {
    double** B = new double*[n];
    for (int i = 0; i < n; ++i) {
        B[i] = new double[n];
    }
    double* a = new double[n];
    // ʹ������������� B ������ a
    for (int i = 0; i < n; ++i) {
        a[i] = i % 99;  // ������� [0, 99] ��Χ�ڵ�ֵ
        for (int j = 0; j < n; ++j) {
            B[i][j] = (i + j) % 99;  // ������� [0, 99] ��Χ�ڵ�ֵ
        }
    }

    double* sum = new double[n];
    for (int row = 0; row < n; ++row) {
        sum[row] = 0.0;
        for (int col = 0; col < n; ++col) {
            sum[row] += B[col][row] * a[col];
        }
    }
        for (int i = 0; i < n; ++i) {
        delete[] B[i];
    }
    delete[] B;
    delete[] a;
    delete[] sum;
}

int main() {  // ���ݹ�ģ����Ϊ 10000
    auto start = high_resolution_clock::now();

    // ������ͨ���������ڻ�
    ordinaryMethod(5000);
ordinaryMethod(6000);
ordinaryMethod(7000);
ordinaryMethod(8000);
ordinaryMethod(9000);

    // ��¼����ʱ��
    auto end = high_resolution_clock::now();

    // ���ִ��ʱ��
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    // �ͷ��ڴ�


    return 0;
}
