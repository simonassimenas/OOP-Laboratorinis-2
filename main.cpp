#include "library.h"

int main() {
    vector<Studentas> grupe;

    cout << "Skaitysite is failo(1) ar pildysite patys(0)?\n";
    bool skaitymas = getBoolInput();
    
    if (skaitymas) {
        failoGeneravimas();

        cout << "Skirstysime pagal vidurki(1) ar mediana(0)\n";
        bool rusiavimasChoice = getBoolInput();

        try {
            failoSkaitymas(grupe);
        }
        catch (const exception &e) { }

        cout << "Rusiuojama...\n";
        int partPoint = partitionIrSort(grupe, rusiavimasChoice);
        failoIrasymas(grupe, partPoint);
    }
    else {
        naudotojoIvestis(grupe);
        grupe.clear();
    }
}
