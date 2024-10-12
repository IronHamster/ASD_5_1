#include <iostream>
#include <vector>
using namespace std;

void scal(vector<int>& dane, int lewy, int srodek, int prawy) {
    int n1 = srodek - lewy + 1;
    int n2 = prawy - srodek;

    vector<int> L(n1), P(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = dane[lewy + i];
    }
    for (int j = 0; j < n2; j++) {
        P[j] = dane[srodek + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = lewy;

    while (i < n1 && j < n2) {
        if (L[i] <= P[j]) {
            dane[k] = L[i];
            i++;
        } else {
            dane[k] = P[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        dane[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        dane[k] = P[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& dane, int lewy, int prawy) {
    if (lewy >= prawy) {
        return;
    }
    int srodek = lewy + (prawy - lewy) / 2;
    mergeSort(dane, lewy, srodek);
    mergeSort(dane, srodek + 1, prawy);
    scal(dane, lewy, srodek, prawy);
}

int main() {
    vector<int> elementy;
    int element;

    while (cin >> element) {
        elementy.push_back(element);
    }

    mergeSort(elementy, 0, elementy.size() - 1);

    for (int i = 0; i < elementy.size(); i++) {
        cout << elementy[i] << " ";
    }

    return 0;
}
