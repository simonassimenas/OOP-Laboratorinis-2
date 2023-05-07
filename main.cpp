#include "library.h"

/// @brief Pagrindinė funkcija kontroliuojanti programą ir pasirinkimus.
int main() {
    vector<Studentas> grupe;

    cout << "Skaitysite is failo(1) ar pildysite patys(0)?\n";
    bool skaitymas = getBoolInput();
    
    if (skaitymas) {
        failoGeneravimas();

        cout << "Skirstysime pagal vidurki(1) ar mediana(0)\n";
        bool rusiavimasChoice = getBoolInput();

        system("ls *.txt");
        cout << "Iveskite failo pavadinima(is saraso):\n";
        string filename = getStringInput();

        auto pradziaProg = high_resolution_clock::now();

        try {
            failoSkaitymas(grupe, filename);
        }
        catch (const exception &e) { }

        cout << "Rusiuojama...\n";
        int partPoint = partitionIrSort(grupe, rusiavimasChoice);
        failoIrasymas(grupe, partPoint);

        auto pabaigaProg = high_resolution_clock::now();
        std::chrono::duration<double> diffSkait = pabaigaProg - pradziaProg;
        cout << "\nPrograma truko " << diffSkait.count() << " sekundes.\n\n";
    }
    else {
        naudotojoIvestis(grupe);
        grupe.clear();
    }
}
