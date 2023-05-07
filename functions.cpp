#include "library.h"

void failoSkaitymas(vector<Studentas>& grupe, string filename) {
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

            string line;
            int talpa = 100000;

            grupe.reserve(talpa);
            getline(fin, line);

            while (fin >> grupe) {
                if (grupe.size() == grupe.capacity())
                    grupe.reserve(talpa*100);
            }
            grupe.shrink_to_fit();

            fin.close();
            delete [] buferis;

            auto pabaigaSkait = high_resolution_clock::now();
            cout << "Duomenys nuskaityti\n";

            duration<double> diffSkait = pabaigaSkait - pradzia;
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
                   << setw(18) << "Galutinis (Vid.) / " << setw(16) << "Galutinis (Med.)\n"
                   << string(70, '-') << "\n";

            fout_s << left << setw(15) << "Vardas" << setw(20) << "Pavarde"
                   << setw(18) << "Galutinis (Vid.) / " << setw(16) << "Galutinis (Med.)\n"
                   << string(70, '-') << "\n";

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
    sort(grupe.begin(), it, varduPalyginimas);
    sort(it, grupe.end(), varduPalyginimas);
    auto pabaiga_sort = high_resolution_clock::now();

    duration<double> diff_part = pabaiga_part - pradzia_part;
    duration<double> diff_sort = pabaiga_sort - pradzia_sort;

    cout << "\nAtskyrimas truko " << diff_part.count() << " sekundes.\n";
    cout << "Rusiavimas pagal vardus truko " << diff_sort.count() << " sekundes.\n";

    return static_cast<int>(it - grupe.begin());
}

bool varduPalyginimas(const Studentas& a, const Studentas& b) {
    if (a.getPavarde() == b.getPavarde())
        return a.getVardas() < b.getVardas();
    else
        return a.getPavarde() < b.getPavarde();
}

int randomSkaicius() {
    random_device rd;
    mt19937_64 mt(static_cast<long unsigned int> (rd()));
    uniform_int_distribution<int> dist(0, 10);

    return int(dist(mt));
}

void failoGeneravimas() {
    bool generuoti;
    cout << "Ar norite generuoti faila? (1 - Taip, 0 - Ne)\n";
    generuoti = getBoolInput();

    while (generuoti) {
        cout << "Kiek studentu irasu turetu buti faile?\n";
        int studSk = autoGradeInput();
        cout << "Kiek namu darbu pazymiu turi kiekvienas studentas?\n";
        int ndSk = autoGradeInput();

        auto pradzia = high_resolution_clock::now();

        string filename = "studentai" + to_string(studSk) + ".txt";


        const int bufDydis = 1024 * 1024 * 100;
        char* buferis = new char[bufDydis];
        ofstream fout;
        fout.rdbuf()->pubsetbuf(buferis, bufDydis);
        fout.open(filename);

        random_device rd;
        mt19937_64 gen(rd());
        uniform_int_distribution<int> dis(1, 10);

        try {
            if (!fout.is_open()) {
                throw runtime_error("Nepavyko sukurti failo " + filename + " irasymui.");
            }
            else {
                fout << left << setw(19) << "Vardas" << setw(20) << "Pavarde";
                for (int i = 1; i <= ndSk; i++) {
                    fout << setw(10) << "ND" + to_string(i);
                }
                fout << setw(10) << "Egz.";

                stringstream ss;
                #pragma omp parallel for
                for (int i = 1; i <= studSk; i++) {
                    ss << left << setw(20) << "\nVardas" + to_string(i)
                       << setw(20) << "Pavarde" + to_string(i);

                    for (int j = 0; j <= ndSk; j++) {
                        int ndGrade = dis(gen);
                        ss << setw(10) << ndGrade;
                    }
                }
                #pragma omp critical
                fout << ss.str();

                fout.close();
                delete [] buferis;

                auto pabaiga = high_resolution_clock::now();
                duration<double> diff = pabaiga - pradzia;
                cout << "Failo sukūrimas truko " << diff.count() << " sekundes.\n";

                cout << "Ar norite generuoti dar viena faila? (1 - Taip, 0 - Ne)\n";
                generuoti = getBoolInput();
            }
        }
        catch (const exception &e) {
            cout << "Klaida: " << e.what() << "\n";
            throw e;
        }
    }
}

void naudotojoIvestis(vector<Studentas> &grupe) {
    Studentas laikinas;
    
    string outputPasirinkimas;
    bool pildyti;
    int talpa = 16;

    grupe.reserve(talpa);

    cout << "Skaiciuosime vidurki(v), mediana(m) ar abu(a)?\n";
    outputPasirinkimas = getChoiceInput();

    cout << "Ar norite pildyti irasa? (1 - Taip, 0 - Ne)\n";
    pildyti = getBoolInput();

    while(pildyti) {
        if(grupe.size() == grupe.capacity()) grupe.reserve(talpa*2);

        pildymas(laikinas);
        grupe.push_back(laikinas);

        cout << "Ar norite pildyti dar viena irasa? (1 - Taip, 0 - Ne)\n";
        pildyti = getBoolInput();
    }
    grupe.shrink_to_fit();

    output_template();
    for(int i=0; i<grupe.size(); i++) spausdinimas(grupe[i], outputPasirinkimas);
}

void pildymas(Studentas &temp) {
    string vardas, pavarde;

    cout << "Iveskite varda:\n";
    vardas = getStringInput();

    cout << "Iveskite pavarde:\n";
    pavarde = getStringInput();

    cout << "Rankinis pazymiu ivedimas(1) arba automatinis generavimas(0)?\n";
    bool rankinis = getBoolInput();

    vector<int> pazVec;
    int resSpace = 16;
    pazVec.reserve(resSpace);
    int inputOrNum;
    int egz;

    if(rankinis) {
        cout << "Iveskite pazymius. Tam kad sustabdyti ivedima parasykite 33:\n";
        do {
            inputOrNum = gradeInput();
            if(inputOrNum == 33) break;

            if(pazVec.size() == pazVec.capacity()) pazVec.reserve(resSpace*2);

            pazVec.push_back(inputOrNum);

        } while(cin.eofbit);

        pazVec.shrink_to_fit();

        cout << "Iveskite egzamino paz.:\n";
        egz = gradeInput();
    }

    else {
        cout << "Iveskite pazymiu skaiciu (egzamino pazymys neieina i nurodyta skaiciu):\n";
        inputOrNum = autoGradeInput();

        int tempNum;
        for(int i=0; i<inputOrNum; i++) {
            tempNum = randomSkaicius();
            pazVec.push_back(tempNum);
        }
        egz = randomSkaicius();
    }

    Studentas(vardas, pavarde, pazVec, egz);

    cout << "---Duomenys irasyti---\n";
}

void output_template() {
    cout << setw(15) << left << "\nVardas" << setw(20) << left << "Pavarde" <<
    setw(34) << left << "Galutinis(Vid.) / Galutinis (Med.)\n";
    cout << "---------------------------------------------------------------------\n";
}

void spausdinimas(Studentas &temp, const string outputPasirinkimas) {
    cout << setw(15) << left << temp.getVardas() << setw(20) << left << temp.getPavarde();

    if(outputPasirinkimas == "a" || outputPasirinkimas == "A") {
        cout << setw(4) << setprecision(3) << temp.getGalutinisVid() << "              "
        << setw(4) << setprecision(3) << temp.getGalutinisMed() << "\n";
    }
    else if (outputPasirinkimas == "v" || outputPasirinkimas == "V") {
        cout << setw(4) << setprecision(3) << temp.getGalutinisVid() << "\n";
    }
    else
        cout << "                   " << setw(4) << setprecision(3) << temp.getGalutinisMed() << "\n";
}

bool getBoolInput() {
    bool input;

    while(!(cin >> input)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Iveskite 1 arba 0:\n";
    }
    return input;
}

bool isNumber(const string& str) {
    for (char const& c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}

string getChoiceInput() {
    string input;

    while (true) {
        cin >> input;
        if (!isNumber(input) 
        && (input == "v" || input == "V" 
        || input == "m" || input == "M" 
        || input == "a" || input == "A")) {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Netinkama ivestis. Iveskite v, m arba a:\n";
    }
    return input;
}

string getStringInput() {
    string input;

    while (true) {
        cin >> input;
        if (!isNumber(input)) {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Netinkama ivestis. Iveskite dar karta:\n";
    }
    return input;
}

int gradeInput() {
    int input;
    cin >> input;

    if(input == 33) {
        return input;
    }
    while (true) {
        try {
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Netinkama ivestis.");
            }
            if (input < 0 || input > 10) {
                throw out_of_range("Iveskite skaiciu esanti 10-baleje sistemoje.");
            }
            break;
        } 
        catch (const exception& e) {
            cout << e.what() << "\n";
            cout << "Iveskite tinkama skaiciu:\n";
            cin >> input;
        }
    }
    return input;
}

int autoGradeInput() {
    int input;

    while(true) {
        try {
            cin >> input;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Netinkama ivestis.");
            }
            if (input < 1) {
                throw out_of_range("Namu darbu skaicius turetu buti naturalusis.");
            }
            break;
        }
        catch (const exception& e) {
            cout << e.what() << "\n";
            cout << "Iveskite tinkama skaiciu:\n";
        }
    }
    return input;
}

int threeInput() {
    int input;

    while(true) {
        try {
            cin >> input;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Netinkama ivestis.");
            }
            if (input < 1 || input > 3) {
                throw out_of_range("Pasirinkite 1, 2 arba 3 strategija.");
            }
            break;
        }
        catch (const exception& e) {
            cout << e.what() << "\n";
            cout << "Iveskite tinkama skaiciu:\n";
        }
    }
    return input;
}