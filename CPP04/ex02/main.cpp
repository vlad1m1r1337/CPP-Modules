#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include <stdlib.h>

#include "WrongAnimal.h"
#include "WrongCat.h"

void deleting_arr(Animal *arr[ARR_SIZE]) {
    for (int i = 0; i < ARR_SIZE / 2; i++) {
        delete arr[i];
    }
    for (int i = ARR_SIZE / 2; i < ARR_SIZE; i++) {
        delete arr[i];
    }
}

int main() {
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
    int *ptr = new int;
    cout << ptr << endl;
    return 0;
}

//int main() {
//    Brain brain;
//
//    cout << brain.getIdea(88) << endl;
//}
