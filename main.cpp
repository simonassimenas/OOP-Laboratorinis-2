#include "addFunctions.h"

void failoGeneravimas();
void failoSkaitymas(vector<Studentas>& grupe);
void failoIrasymas(vector<Studentas>& grupe, int partPoint);
int partitionIrSort(vector<Studentas>& grupe, bool rusiavimasChoice);
bool varduPalyginimas(const Studentas& a, const Studentas& b);


int main() {
    vector<Studentas> grupe;
    
    int strategy;
    bool choice = true;

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

void failoSkaitymas(vector<Studentas>& grupe) {
    system("ls *.txt");
    cout << "Iveskite failo pavadinima(is saraso):\n";
    string filename = getStringInput();

    const int bufDydis = 1024 * 1024 * 100;
    char* buferis = new char[bufDydis];
    ifstream fin;
    fin.rdbuf()->pubsetbuf(buferis, bufDydis);
    fin.open(filename);

    try {
        if (!fin.is_open()) {
            throw runtime_error("Nepavyko atverti failo " + filename + " skaitymui.");
        }
        else {
            auto pradzia = high_resolution_clock::now();
            cout << "\nFailas skaitomas...\n";

            int talpa = 100000;
            grupe.reserve(talpa);

            fin.readsome(buferis, bufDydis);
            int bytesRead = fin.gcount();

            string vardas, pavarde, line;
            int pazymys, egzaminas;
            vector<int> pazVec;

            getline(fin, line);
            while (fin >> vardas >> pavarde) {
                if(grupe.size() == grupe.capacity()) grupe.reserve(talpa*10);

                while (fin >> pazymys) {
                    pazVec.push_back(pazymys);
                }
                egzaminas = pazVec.back();
                pazVec.pop_back();

                Studentas temp(vardas, pavarde, pazVec, egzaminas);

                grupe.push_back(temp);
            }

            grupe.shrink_to_fit();
            fin.close();
            delete [] buferis;
            auto pabaigaSkait = high_resolution_clock::now();

            cout << "Duomenys nuskaityti\n";

            std::chrono::duration<double> diffSkait = pabaigaSkait - pradzia;
            cout << "\nSkaitymas truko " << diffSkait.count() << " sekundes.\n\n";
        }
    }
    catch (const exception &e) {
        cout << "Klaida: " << e.what() << "\n";
        throw e;
    }
}

void failoIrasymas(vector<Studentas>& grupe, int partPoint) {
    const string filename_v = "vargsai.txt";
    const string filename_s = "saunuoliai.txt";
    ofstream fout_v(filename_v);
    ofstream fout_s(filename_s);

    try {
        if (!fout_v.is_open()) {
            throw runtime_error("Nepavyko sukurti failo " + filename_v + " irasymui.");
        }
        if (!fout_s.is_open()) {
            throw runtime_error("Nepavyko sukurti failo " + filename_s + " irasymui.");
        }
        else {
            cout << "\nRasoma i failus...\n";
            auto pradzia = high_resolution_clock::now();

            fout_v << left << setw(15) << "Vardas" << setw(20) << "Pavarde" 
                << setw(18) << "Galutinis (Vid.) / " << setw(16) << "Galutinis (Med.)\n";

            fout_v << string(70, '-') << "\n";
            fout_s << left << setw(15) << "Vardas" << setw(20) << "Pavarde" 
                << setw(18) << "Galutinis (Vid.) / " << setw(16) << "Galutinis (Med.)\n";

            fout_s << string(70, '-') << "\n";

            for (int i = 0; i < partPoint; i++) {
                fout_v << grupe[i];
            }
            for (int i = partPoint; i < grupe.size(); i++) {
                fout_s << grupe[i];
            }

            fout_v.close();
            fout_s.close();

            auto pabaiga = high_resolution_clock::now();

            duration<double> diff = pabaiga - pradzia;
            cout << "Rasymas i failus truko " << diff.count() << " sekundes.\n";

            grupe.clear();
        }
    }
    catch (const exception &e) {
        cout << "Klaida: " << e.what() << "\n";
    }
}

int partitionIrSort(vector<Studentas>& grupe, bool rusiavimasChoice) {
    auto it = grupe.begin();

    auto pradzia_part = high_resolution_clock::now();
    if (rusiavimasChoice) {
        it = partition(grupe.begin(), grupe.end(), [](const Studentas& s) { return s.getGalutinisVid() < 5; });
    }
    else {
        it = partition(grupe.begin(), grupe.end(), [](const Studentas& s) { return s.getGalutinisMed() < 5; });
    }
    auto pabaiga_part = high_resolution_clock::now();

    auto pradzia_sort = high_resolution_clock::now();
    sort(grupe.begin(), it, Studentas::varduPalyginimas);
    sort(it, grupe.end(), Studentas::varduPalyginimas);
    auto pabaiga_sort = high_resolution_clock::now();

    duration<double> diff_part = pabaiga_part - pradzia_part;
    duration<double> diff_sort = pabaiga_sort - pradzia_sort;
    
    cout << "\nAtskyrimas truko " << diff_part.count() << " sekundes.\n";
    cout << "Rusiavimas pagal vardus truko " << diff_sort.count() << " sekundes.\n";

    return static_cast<int>(it - grupe.begin());
}