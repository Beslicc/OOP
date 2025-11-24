#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>

using namespace std;

class Container {

private:
	int* podaci;
	size_t velicina;
	size_t kapacitet;

public:
	Container(size_t initial_capacity = 0);
	Container(const Container& drugi);
	Container(Container&& drugi) noexcept;
	~Container();
	void push_back(int vrijednost);
	size_t size() const;
	size_t capacity() const;
	int at(size_t indeks) const;
	void clear();
};

#endif
