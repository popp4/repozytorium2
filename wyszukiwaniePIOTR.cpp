#include <iostream>
#include <cmath>
using namespace std;

// Algorytm wyszukiwania liniowego
int linearSearch(int *tablica, int rozmiar, int klucz) {
    for (int i = 0; i < rozmiar; ++i) {
        if (tablica[i] == klucz) {
            return i;
        }
    }
    return -1; // Zwraca -1, gdy element nie został znaleziony
}

// Algorytm wyszukiwania liniowego z wartownikiem
int linearSearchWithSentinel(int *tablica, int rozmiar, int klucz) {
    int ostatni = tablica[rozmiar - 1]; // Zabezpieczenie ostatniego elementu
    tablica[rozmiar - 1] = klucz; // Ustawienie wartownika
    
    int i = 0;
    while (tablica[i] != klucz) {
        ++i;
    }
    
    tablica[rozmiar - 1] = ostatni; // Przywrócenie oryginalnego ostatniego elementu
    
    if (i < rozmiar - 1 || tablica[rozmiar - 1] == klucz) {
        return i;
    }
    return -1; // Zwraca -1, gdy element nie został znaleziony
}

// Algorytm wyszukiwania skokowego
int jumpSearch(int *tablica, int rozmiar, int klucz) {
    int krok = sqrt(rozmiar);
    int poprzedni = 0;
    
    while (tablica[min(krok, rozmiar) - 1] < klucz) {
        poprzedni = krok;
        krok += sqrt(rozmiar);
        if (poprzedni >= rozmiar) {
            return -1; // Wykracza poza granice
        }
    }
    
    while (tablica[poprzedni] < klucz) {
        ++poprzedni;
        
        if (poprzedni == min(krok, rozmiar)) {
            return -1; // Element nie został znaleziony
        }
    }
    
    if (tablica[poprzedni] == klucz) {
        return poprzedni;
    }
    
    return -1; // Element nie został znaleziony
}

// Algorytm wyszukiwania binarnego
int binarySearch(int *tablica, int lewy, int prawy, int klucz) {
    while (lewy <= prawy) {
        int srodek = lewy + (prawy - lewy) / 2;
        
        if (tablica[srodek] == klucz) {
            return srodek;
        }
        
        if (tablica[srodek] < klucz) {
            lewy = srodek + 1;
        } else {
            prawy = srodek - 1;
        }
    }
    return -1; // Element nie został znaleziony
}

// Algorytm wyszukiwania interpolacyjnego
int interpolationSearch(int *tablica, int rozmiar, int klucz) {
    int lewy = 0, prawy = (rozmiar - 1);
    
    while (lewy <= prawy && klucz >= tablica[lewy] && klucz <= tablica[prawy]) {
        if (lewy == prawy) {
            if (tablica[lewy] == klucz) {
                return lewy;
            }
            return -1; // Element nie został znaleziony
        }
        
        int pos = lewy + (((double)(prawy - lewy) / (tablica[prawy] - tablica[lewy])) * (klucz - tablica[lewy]));
        
        if (tablica[pos] == klucz) {
            return pos;
        }
        
        if (tablica[pos] < klucz) {
            lewy = pos + 1;
        } else {
            prawy = pos - 1;
        }
    }
    
    return -1; // Element nie został znaleziony
}

int main() {
    int tablica[] = {2, 3, 4, 10, 40};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    int klucz = 10;
    
    // Testowanie algorytmu wyszukiwania liniowego
    int wynik_linear = linearSearch(tablica, rozmiar, klucz);
    if (wynik_linear != -1) {
        cout << "Element znaleziony przy indeksie " << wynik_linear << " (Algorytm liniowy)" << endl;
   cout << "Element znaleziony przy indeksie " << wynik_linear << " (Algorytm liniowy)" << endl;
    } else {
        cout << "Element nie został znaleziony (Algorytm liniowy)" << endl;
    }

    // Testowanie algorytmu wyszukiwania liniowego z wartownikiem
    int wynik_linear_sentinel = linearSearchWithSentinel(tablica, rozmiar, klucz);
    if (wynik_linear_sentinel != -1) {
        cout << "Element znaleziony przy indeksie " << wynik_linear_sentinel << " (Algorytm liniowy z wartownikiem)" << endl;
    } else {
        cout << "Element nie został znaleziony (Algorytm liniowy z wartownikiem)" << endl;
    }

    // Testowanie algorytmu wyszukiwania skokowego
    int wynik_jump = jumpSearch(tablica, rozmiar, klucz);
    if (wynik_jump != -1) {
        cout << "Element znaleziony przy indeksie " << wynik_jump << " (Algorytm skokowy)" << endl;
    } else {
        cout << "Element nie został znaleziony (Algorytm skokowy)" << endl;
    }

    // Testowanie algorytmu wyszukiwania binarnego
    int wynik_binary = binarySearch(tablica, 0, rozmiar - 1, klucz);
    if (wynik_binary != -1) {
        cout << "Element znaleziony przy indeksie " << wynik_binary << " (Algorytm binarny)" << endl;
    } else {
        cout << "Element nie został znaleziony (Algorytm binarny)" << endl;
    }

    // Testowanie algorytmu wyszukiwania interpolacyjnego
    int wynik_interpolation = interpolationSearch(tablica, rozmiar, klucz);
    if (wynik_interpolation != -1) {
        cout << "Element znaleziony przy indeksie " << wynik_interpolation << " (Algorytm interpolacyjny)" << endl;
    } else {
        cout << "Element nie został znaleziony (Algorytm interpolacyjny)" << endl;
    }

    return 0;
}