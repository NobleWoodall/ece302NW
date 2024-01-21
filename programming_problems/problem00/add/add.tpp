#include "add.hpp"

template <typename T> Add<T>::Add() {}

template <typename T> Add<T>::~Add() {}

template <typename T> T Add<T>::call(T one,T two) const { 

    return one+two;

}
