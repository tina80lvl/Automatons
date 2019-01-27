#include <iostream>
#include <vector>
#include <cstdio>

int main() {
    freopen("artificial.in", "r", stdin);
    freopen("artificial.out", "w", stdout);

    int n;
    std::cin >> n;

    switch (n){
        case 1:{
            std::cout << "2 1 R M\n"
                      << "3 3 M M\n"
                      << "3 4 R M\n"
                      << "2 2 L M\n";
            break;
        }

        case 2:{
            std::cout << "1 1 R M\n";
            break;
        }

        case 3:{
            std::cout << "2 2 R M\n"
                      << "3 1 M M\n"
                      << "2 2 L M\n";
            break;
        }

        case 4:{
            std::cout << "2 2 R M\n"
                      << "3 2 M M\n"
                      << "1 4 M M\n"
                      << "2 4 L M\n";
            break;
        }

        case 5:{
            std::cout << "2 3 M M\n"
                      << "3 2 M L\n"
                      << "1 1 R M\n";
            break;
        }

        case 6:{
            std::cout << "2 3 M M\n"
                      << "3 1 R M\n"
                      << "4 5 M M\n"
                      << "5 1 L M\n"
                      << "4 1 M M\n";
            break;
        }

        case 7:{
            std::cout << "2 2 L M\n"
                      << "2 3 R M\n"
                      << "1 4 M M\n"
                      << "2 3 M M\n";
            break;
        }

        case 8:{
            std::cout << "2 3 M M\n"
                      << "1 1 R M\n"
                      << "4 3 M M\n"
                      << "5 5 R M\n"
                      << "2 3 R M\n";
            break;
        }

        case 9:{
            std::cout << "2 3 R M\n"
                      << "4 4 L M\n"
                      << "5 4 M M\n"
                      << "5 6 L M\n"
                      << "6 1 R M\n"
                      << "1 3 M M\n";
            break;
        }

        default:{
            std::cout << "2 3 R M\n"
                      << "4 5 R M\n"
                      << "5 1 R M\n"
                      << "6 1 R M\n"
                      << "6 4 L M\n"
                      << "1 1 M M\n";
            break;
        }
    }

    return 0;
}