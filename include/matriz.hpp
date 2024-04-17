#ifndef AYP2_TEMPLATES_MATRIZ_HPP
#define AYP2_TEMPLATES_MATRIZ_HPP

#include <cstddef>
#include <iostream>

template<typename T>
class matriz {
private:
    T** matriz1;
    size_t fila;
    size_t columna;
public:
    matriz(size_t fila1, size_t columna1);

    void alta(T dato, size_t i, size_t j);

    void visualizar();

    ~matriz();
};

template<typename T>
matriz<T>::matriz(size_t fila, size_t columna) {
    this->fila = fila;
    this->columna = columna;
    matriz1 = new T* [fila];
    for (size_t i = 0; i < fila; i++) {
        matriz1[i] = new T[columna];
        for (size_t j = 0; j < columna; j++) {
            matriz1[i][j] = {};
        }
    }
}

template<typename T>
void matriz<T>::alta(T dato, size_t i, size_t j) {
    matriz1[i][j] = dato;
}

template<typename T>
void matriz<T>::visualizar() {
    for (size_t i = 0; i < fila; i++) {
        for (size_t j = 0; j < columna; j++) {
            std::cout << matriz1[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
matriz<T>::~matriz() {
    for (size_t i = 0; i < fila; i++) {
        delete[] matriz1[i];
    }
    delete[] matriz1;
}

#endif