#include <iostream>
#include <vector>
// Primera version
/*void swap(int& a, int& b) {
    int aux = a;
    a = b;
    b = aux;
}

void sort(std::vector<int>& vector) {
    for (size_t i = 0; i < vector.size() - 1; i++) {
        size_t minimo = i;
        for (size_t j = i + 1; j < vector.size(); j++) {
            if (vector[j] < vector[minimo])
                minimo = j;
        }
        swap(vector[minimo], vector[i]);
    }
}*/

// Segunda version
template<typename Tipo>
void swap(Tipo& a, Tipo& b) {
    Tipo aux = a;
    a = b;
    b = aux;
}

/*template<typename Tipo>
void sort(std::vector<Tipo>& vector) {
    for (size_t i = 0; i < vector.size() - 1; i++) {
        size_t minimo = i;
        for (size_t j = i + 1; j < vector.size(); j++) {
            if (vector[j] < vector[minimo])
                minimo = j;
        }
        swap(vector[minimo], vector[i]);
    }
}*/

// Tercera version
/*template<typename Tipo, bool esMenor(Tipo, Tipo)>
void sort(std::vector<Tipo>& vector) {
    for (size_t i = 0; i < vector.size() - 1; i++) {
        size_t minimo = i;
        for (size_t j = i + 1; j < vector.size(); j++) {
            if (esMenor(vector[j], vector[minimo]))
                minimo = j;
        }
        swap(vector[minimo], vector[i]);
    }
}*/

// Cuarta version
template<typename Tipo, bool esMenor(Tipo, Tipo)>
void sort(std::vector<Tipo>& vector, bool ascendente) {
    size_t minimo, i, j;
    bool comparacion;
    for (i = 0; i < vector.size() - 1; i++) {
        minimo = i;
        for (j = i + 1; j < vector.size(); j++) {
            comparacion = esMenor(vector[j], vector[minimo]);
            if (!ascendente) {
                comparacion = !comparacion;
            }
            if (comparacion)
                minimo = j;
        }
        swap(vector[minimo], vector[i]);
    }
}

// Jugar con estas funciones
bool intMenor(int n1, int n2) {
    return n1 < n2;
}

bool intMayor(int n1, int n2) {
    return n1 > n2;
}

int main() {
    std::vector<int> vector = {3, 5, 7, 10, 9, 2, 1};
    sort<int, intMenor>(vector, false);
    std::cout << "Vector ordenado: ";
    for (auto it = vector.begin(); it < vector.end(); it++) {
        if (it == vector.end() - 1) {
            std::cout << *it << "." << std::endl;
        } else {
            std::cout << *it << ", ";
        }
    }
    return 0;
}