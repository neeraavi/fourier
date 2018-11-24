#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <complex>

template <class T>
void print(const std::vector<T>& v)
{
    for(auto i=0u; i<v.size(); ++i)
    {
    std::cout << v[i] << "  ";
    }
    std::cout << std::endl;
}

int main()
{
    using namespace std;
    constexpr auto N = 16u;
    constexpr auto f = 3u;
    constexpr auto pi = 3.14159265359;

    vector<double> x{}; 

    for(auto n=0u; n<N; ++n)
    {
        x.emplace_back(3*sin(2.0*pi*f*n/N)+ 1.5*cos(2.0*pi*2*f*n/N));
    }
    print(x);

    vector<complex<double>> X(N/2); 
    for(auto k=0u; k<N/2; ++k)
    {
        for(auto n=0u; n<N; ++n)
        {
            X[k] += complex<double>{x[n] * cos(2*pi*k/N*n), x[n] * sin(2*pi*k/N*n)};
        }
        X[k] *= 2.0/N;
    }
    print(X);
    for(const auto& item:X)
    {
       cout << fixed << setprecision(3) << "abs:" << abs(item) << "  arg:" << arg(item)*180/pi << endl;
    }

    return 0;
}
