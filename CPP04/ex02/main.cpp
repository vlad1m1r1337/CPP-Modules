#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include <stdlib.h>

#include "WrongAnimal.h"
#include "WrongCat.h"

void deleting_arr(Animal **arr) {
    for (int i = 0; i < ARR_SIZE; i++) {
        delete arr[i];
    }
}

void run() {
	Animal *arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE / 2; i++) {
        arr[i] = new Dog();
    }
    for (int i = ARR_SIZE / 2; i < ARR_SIZE; i++) {
        arr[i] = new Cat();
    }
    cout << arr[4]->getType() << endl;
    cout << arr[8]->getType() << endl;
    deleting_arr(arr);
}

int main () {
    run();
//    system("leaks ex02");
    return 0;
}