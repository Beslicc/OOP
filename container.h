#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
private:
    int* podaci;
    size_t velicina;
    size_t kapacitet;

public:
    Container(size_t pocetni_kapacitet = 0);
    Container(const Container& drugi);
    Container(Container&& drugi);
    ~Container();

    Container& operator=(const Container& drugi);
    Container& operator=(Container&& drugi);

    void push_back(int vrijednost);
    size_t size() const;
    size_t capacity() const;
    int& at(size_t index);
    const int& at(size_t index) const;
    void clear();
    void print() const;
};

#endif