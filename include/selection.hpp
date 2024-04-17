#ifndef AYP2_TEMPLATES_SELECTION_HPP
#define AYP2_TEMPLATES_SELECTION_HPP

#include <vector>
#include <cstddef>

template<typename T>
class selection {
private:
    // Pre: -
    // Post: Intercambia el valor de las variables.
    static void swap(T& a, T& b);

public:
    // Pre: T debe implementar operator<()
    // Post: Ordena el vector.
    static void sort(std::vector<T>& vector);

    // Pre: T debe implementar operator<()
    // Post: Ordena el vector.
    static void sort(std::vector<T>& vector, bool ascendente);

    // Pre: -
    // Post: Ordena el vector.
    static void sort(std::vector<T>& vector, bool(* comparacion)(T, T));

    // Pre: -
    // Post: Ordena el vector.
    static void sort(std::vector<T>& vector, bool(* comparacion)(T, T), bool ascendente);
};

template<typename T>
void selection<T>::swap(T& a, T& b) {
    T aux = a;
    a = b;
    b = aux;
}

template<typename T>
void selection<T>::sort(std::vector<T>& vector) {
    size_t minimo, i, j;
    for (i = 0; i < vector.size() - 1; i++) {
        minimo = i;
        for (j = i + 1; j < vector.size(); j++) {
            if (vector[j] < vector[minimo])
                minimo = j;
        }
        swap(vector[minimo], vector[i]);
    }
}

template<typename T>
void selection<T>::sort(std::vector<T>& vector, bool ascendente) {
    size_t minimo, i, j;
    bool comp;
    for (i = 0; i < vector.size() - 1; i++) {
        minimo = i;
        for (j = i + 1; j < vector.size(); j++) {
            comp = vector[j] < vector[minimo];
            if (!ascendente) {
                comp = !comp;
            }
            if (comp)
                minimo = j;
        }
        swap(vector[minimo], vector[i]);
    }
}

template<typename T>
void selection<T>::sort(std::vector<T>& vector, bool(* comparacion)(T, T)) {
    size_t minimo, i, j;
    for (i = 0; i < vector.size() - 1; i++) {
        minimo = i;
        for (j = i + 1; j < vector.size(); j++) {
            if (comparacion(vector[j], vector[minimo]))
                minimo = j;
        }
        swap(vector[minimo], vector[i]);
    }
}

template<typename T>
void selection<T>::sort(std::vector<T>& vector, bool(* comparacion)(T, T), bool ascendente) {
    size_t minimo, i, j;
    bool comp;
    for (i = 0; i < vector.size() - 1; i++) {
        minimo = i;
        for (j = i + 1; j < vector.size(); j++) {
            comp = comparacion(vector[j], vector[minimo]);
            if (!ascendente) {
                comp = !comp;
            }
            if (comp)
                minimo = j;
        }
        swap(vector[minimo], vector[i]);
    }
}

#endif