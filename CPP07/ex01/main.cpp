#include "whatever.hpp"

using std::cout;
using std::endl;
using std::string;

void f(int &el) {
    el = el * 2;
}

void print_int(int el) {
    cout << el << endl;
}

void print_char(char el) {
    cout << el << endl;
}

int main( void ) {

    int arr_num[4] = {1, 2 ,3, 4};
    char arr_char[4] = {'a', 'b', 'c', 'd'};
    iter(arr_num, 4, f);
    iter(arr_num, 4, print_int);
    iter(arr_char, 4, print_char);
    return 0;
}
