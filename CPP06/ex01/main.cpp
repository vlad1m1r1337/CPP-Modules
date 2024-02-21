#include "Data.hpp"
#include "Serializer.hpp"

//
//int main() {
//	Data data;
//	Serializer serializer;
//	uintptr_t raw = serializer.serialize(&data);
//	Data* deserialized = serializer.deserialize(raw);
//	cout << *deserialized << endl;
//	delete deserialized;
//	return 0;
//}

int main() {
	Data *data = new Data("vova", 100, false);
	Data *new_data = new Data();
	cout << *data << endl;
	uintptr_t temp = Serializer::serialize(data);
	new_data = Serializer::deserialize(temp);
	cout << *new_data << endl;
	delete data;
	delete new_data;
	return 0;
}