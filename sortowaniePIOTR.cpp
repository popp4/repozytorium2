#include <iostream>

using namespace std;

// Sortowanie bąbelkowe
void bubbleSort(int *tablica, int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = 0; j < rozmiar - i - 1; ++j) {
            if (tablica[j] > tablica[j + 1]) {
                swap(tablica[j], tablica[j + 1]);
            }
        }
    }
}

// Sortowanie przez wstrząsanie (koktajlowe)
void cocktailSort(int *tablica, int rozmiar) {
    bool zamienione = true;
    int poczatek = 0;
    int koniec = rozmiar - 1;
    
    while (zamienione) {
        zamienione = false;
        
        // Sortowanie od lewej do prawej
        for (int i = poczatek; i < koniec; ++i) {
            if (tablica[i] > tablica[i + 1]) {
                swap(tablica[i], tablica[i + 1]);
                zamienione = true;
            }
        }
        
        if (!zamienione)
            break;
        
        zamienione = false;
        --koniec;
        
        // Sortowanie od prawej do lewej
        for (int i = koniec - 1; i >= poczatek; --i) {
            if (tablica[i] > tablica[i + 1]) {
                swap(tablica[i], tablica[i + 1]);
                zamienione = true;
            }
        }
        
        ++poczatek;
    }
}

// Sortowanie przez scalanie
void merge(int *tablica, int lewy, int srodek, int prawy) {
    int n1 = srodek - lewy + 1;
    int n2 = prawy - srodek;
    
    int lewa[n1], prawa[n2];
    
    for (int i = 0; i < n1; ++i) {
        lewa[i] = tablica[lewy + i];
    }
    for (int j = 0; j < n2; ++j) {
        prawa[j] = tablica[srodek + 1 + j];
    }
    
    int i = 0, j = 0, k = lewy;
    
    while (i < n1 && j < n2) {
        if (lewa[i] <= prawa[j]) {
            tablica[k] = lewa[i];
            ++i;
        } else {
            tablica[k] = prawa[j];
            ++j;
        }
        ++k;
    }
    
    while (i < n1) {
        tablica[k] = lewa[i];
        ++i;
        ++k;
    }
    
    while (j < n2) {
        tablica[k] = prawa[j];
        ++j;
        ++k;
    }
}

void mergeSort(int *tablica, int lewy, int prawy) {
    if (lewy >= prawy)
        return;
    
    int srodek = lewy + (prawy - lewy) / 2;
    
    mergeSort(tablica, lewy, srodek);
    mergeSort(tablica, srodek + 1, prawy);
    
    merge(tablica, lewy, srodek, prawy);
}

// Sortowanie szybkie (quicksort)
int podzial(int *tablica, int dolny, int gorny) {
    int os = tablica[gorny];
    int i = dolny - 1;
    
    for (int j = dolny; j < gorny; ++j) {
        if (tablica[j] < os) {
            ++i;
            swap(tablica[i], tablica[j]);
        }
    }
    
    swap(tablica[i + 1], tablica[gorny]);
    return i + 1;
}

void quickSort(int *tablica, int dolny, int gorny) {
    if (dolny < gorny) {
        int pi = podzial(tablica, dolny, gorny);
        
        quickSort(tablica, dolny, pi - 1);
        quickSort(tablica, pi + 1, gorny);
    }
}

// Sortowanie przez wstawianie
void insertionSort(int *tablica, int rozmiar) {
    for (int i = 1; i < rozmiar; ++i) {
        int klucz = tablica[i];
        int j = i - 1;
        
        while (j >= 0 && tablica[j] > klucz) {
            tablica[j + 1] = tablica[j];
            --j;
        }
        
        tablica[j + 1] = klucz;
    }
}

int main() {
    int tablica[] = {12, 11, 13, 5, 6};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    cout << "Tablica przed sortowaniem: ";
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    bubbleSort(tablica, rozmiar);
    cout << "Po sortowaniu bąbelkowym: ";
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    cocktailSort(tablica, rozmiar);
    cout << "Po sortowaniu przez wstrząsanie: ";
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    mergeSort(tablica, 0, rozmiar - 1);
    cout << "Po sortowaniu przez scalanie: ";
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    quickSort(tablica, 0, rozmiar - 1);
    cout << "Po sortowaniu szybkim: ";
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    insertionSort(tablica, rozmiar);
    cout << "Po sortowaniu przez wstawianie: ";
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    return 0;
}