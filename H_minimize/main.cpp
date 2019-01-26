#include <iostream>
#include <vector>
#include <cstdio>

const int MAX_SEG = 20;
const int MAX_IT = 20;
const double INF = 1e18;

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<double> x(n, 0);
    std::cout.precision(5);
    std::cout << std::fixed;
    for (int i = 0; i < n; i++)
    {
        double minn = INF;
        double minx = -1;
        for (int j = 0; j < MAX_SEG; j++)
        {
            double l = (double)j / MAX_SEG,
                   r = (double)(j + 1) / MAX_SEG;
            for (int k = 0; k < MAX_IT; ++k)
            {
                double m1 = l + (r - l) / 3,
                       m2 = r - (r - l) / 3,
                       f1, f2;
                x[i] = m1;

                for (auto x_i : x)
                    std::cout << x_i << ' ';
                std::cout << std::endl;
                std::cout.flush();

                std::cin >> f1;
                x[i] = m2;

                for (auto x_i : x)
                    std::cout << x_i << ' ';
                std::cout << std::endl;
                std::cout.flush();

                std::cin >> f2;
                if (f1 > f2)
                    l = m1;
                else
                    r = m2;
                if (f1 < minn)
                    minn = f1, minx = m1;
                if (f2 < minn)
                    minn = f2, minx = m2;
            }
        }
        x[i] = minx;
    }
    double ans;

    for (auto x_i : x)
        std::cout << x_i << ' ';
    std::cout << std::endl;
    std::cout.flush();

    std::cin >> ans;
    std::cout.flush();
    std::cout << "minimum " << ans << std::endl;
    std::cout.flush();

    return 0;
}

