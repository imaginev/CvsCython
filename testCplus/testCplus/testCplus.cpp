#include <iostream>
// # define M_PI           3.14159265358979323846
#include <chrono>
#include "cmath"

float normal_distribution(float x, float nx = 0, float o = 1)
{
    const float two_pi = 2.0f * M_PI;
    const float denominator = o * sqrt(two_pi);
    const float z = (x - nx) / o;
    const float exponent = -0.5 * pow(z, 2.0);
    return (1.0 / denominator) * exp(exponent);
    // return (1 / (o * sqrt(2 * M_PI))) * exp(-0.5 * pow(((x - nx) / o), 2));
}

float F(float b, int n = 10000) {
    const int a = 0;
    const float dx = (b - a) / static_cast<float>(n);
    float sum = 0;

    for (int i = 0; i < n; i++) {
        const float xi = a + i * dx;
        sum += normal_distribution(xi) * dx;
    }

    return sum;
}

void calculate(float ei, float es, float nx, float o, int n) {
    const float t2 = (es - nx) / o;
    const float t1 = (ei - nx) / o;
    const float p_suitable_parts = (F(t2, n) - F(t1, n)) * 100;

    const float t2_ = (ei - nx) / o;
    const float t1_ = (nx - 3 * o - nx) / o;
    const float p_incorrigible_marriage = (F(t2_, n) - F(t1_, n)) * 100;

    const float t2__ = (nx + 3 * o - nx) / o;
    const float t1__ = (es - nx) / o;
    const float p_fixable_marriage = (F(t2__, n) - F(t1__, n)) * 100;
}

double test_normal_dist(int cycles)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (float i = 0; i < cycles; i++) {
        const float increment = i / 10000;
        calculate(0.006f+increment, 0.055f+increment, 0.026f+increment, 0.012f+increment, 10000);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time: " << duration.count() << " seconds" << std::endl;
    return duration.count();
}

int main()
{
    int cycles = 1000;
    int countTests = 10;
    double sum = 0;

    for (int i = 0; i < countTests; i++) {
        sum += test_normal_dist(cycles);
    }
    std::cout << "Current time: " << sum / countTests << std::endl;
}
