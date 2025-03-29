// simple_sum_test.cpp
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <cmath>

const int n = 2000000;
const int iterations = 1000;

// ƽ���㷨ʵ��
double simple_sum(const double* a, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += a[i];
    }
    return sum;
}

// ���ɲ�������
void generate_data(double* data) {
    for (int i = 0; i < n; ++i) {
        data[i] = i % 100;
    }
}

int main() {
    double* data = new double[n];
    generate_data(data);

    // Ԥ�Ȼ���
    volatile double warmup = simple_sum(data, n);

    // ��ʽ����
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        volatile double result = simple_sum(data, n);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "ƽ���㷨���Խ��:\n";
    std::cout << "������: " << n << " ��Ԫ��\n";
    std::cout << "��������: " << iterations << " ��\n";
    std::cout << "ƽ����ʱ: " << duration.count()/iterations << " ����\n";

    delete[] data;
    return 0;
}
