#include "MutantStack.hpp"

typedef std::vector<int> container_type;

int main() {
    {
        container_type a;
        MutantStack<int> mstack;

        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);

        MutantStack<int>::iterator itb = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        while (itb != ite) {
            cout << *itb << endl;
            ++itb;
        }
    }
    cout << endl;
    {
        MutantStack<int> mstack;

        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);

        MutantStack<int>::reverse_iterator itrb = mstack.rbegin();
        MutantStack<int>::reverse_iterator itre = mstack.rend();

        while (itrb != itre) {
            cout << *itrb << endl;
            ++itrb;
        }
    }
    return 0;
}
