#include "Data.hpp"
#include "Serializer.hpp"


int main() {
	Data *data = new Data("vova", 100, false);
	cout << *data << endl;
	uintptr_t temp = Serializer::serialize(data);
	data = Serializer::deserialize(temp);
	cout << *data;
	delete data;
	return 0;
}