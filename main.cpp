#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <vector>

using namespace std;

struct Adresat
{
    int id=0;
    string imie, nazwisko, email, adres, tel;
};

string wczytajLinie()
{
    string input;
    cin.sync();
    getline (cin, input);
    return input;
}

char wczytajZnak()
{
    string wejscie= "";
    char znak = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie."<<endl;
    }
    return znak;
}

void wczytajAdresatowZPliku(vector<Adresat>&adresaci)
{
    fstream plik;
    plik.open("ksiazka_adresowa.txt",ios::in);
    if (plik.good() != true)
    {
        cout << "Nie mozna otworzyc pliku" <<  endl;
    }

    string linia{};
    while (getline(plik, linia))
    {
        Adresat adresat;
        stringstream ss(linia);

        string idStr{};
        getline(ss, idStr, '|');
        adresat.id = stoi(idStr);

        getline(ss, adresat.imie, '|');
        getline(ss, adresat.nazwisko, '|');
        getline(ss, adresat.tel, '|');
        getline(ss, adresat.email, '|');
        getline(ss, adresat.adres, '|');

        adresaci.push_back(adresat);
    }
    plik.close();

}

void zapiszDaneDoPliku (vector <Adresat>&adresaci)
{
    fstream plik;
    plik.open("ksiazka_adresowa.txt", ios::out );

    if (plik.good() == true)
    {
        for (long long unsigned int i = 0; i < adresaci.size(); i++)
        {
            plik <<  adresaci[i].id << "|";
            plik << adresaci[i].imie << "|";
            plik <<  adresaci[i].nazwisko << "|";
            plik << adresaci[i].tel << "|";
            plik  << adresaci[i].email << "|";
            plik <<  adresaci[i].adres << "|" << endl;;
        }
    }

    else
    {
        cout << "Plik nie moze byc otwarty!"<< endl;
        system("pause");
    }
    plik.close();
}

void dodajAdresata (vector <Adresat>&adresaci, int& licznikID)
{
    Adresat adresat;

    cout << "Podaj imie adresata, ktorego chcesz dodac: ";
    adresat.imie = wczytajLinie();

    cout << "Podaj nazwisko: ";
    adresat.nazwisko = wczytajLinie();

    cout << "Podaj email: ";
    adresat.email = wczytajLinie();

    cout << "Podaj adres: ";
    adresat.adres = wczytajLinie();

    cout << "Podaj tel: ";
    adresat.tel = wczytajLinie();

    adresat.id = licznikID ++;
    adresaci.push_back(adresat);


    cout <<endl<< "Dodano adresata! " <<endl;
    system("pause");

    zapiszDaneDoPliku(adresaci);
}

void wyszukajPoImieniu(vector <Adresat>&adresaci)
{
    string imieDoWyszukania = "";
    cout <<"Podaj imie do wyszukania: ";
    imieDoWyszukania = wczytajLinie();

    for (Adresat adresat : adresaci)
    {
        if (adresat.imie == imieDoWyszukania)
        {
            cout << endl;
            cout <<"Id: "<< adresat.id<< endl;
            cout <<"Imie: "<< adresat.imie << endl;
            cout << "Nazwisko: "<<adresat.nazwisko << endl;
            cout <<"Email: "<< adresat.email << endl;
            cout << "Adres: "<<adresat.adres << endl;
            cout << "Tel: : "<<adresat.tel <<endl<< endl;
        }
    }
    system("pause");
}

void wyszukajPoNazwisku(vector <Adresat>&adresaci)
{
    string nazwiskoDoWyszukania = "";
    cout << "Podaj nazwisko do wyszukania: ";
    nazwiskoDoWyszukania = wczytajLinie();

    for (Adresat adresat : adresaci)
    {
        if (adresat.nazwisko  == nazwiskoDoWyszukania)
        {
            cout << endl;
            cout <<"Id: "<< adresat.id<< endl;
            cout <<"Imie: "<< adresat.imie << endl;
            cout << "Nazwisko: "<<adresat.nazwisko << endl;
            cout <<"Email: "<< adresat.email << endl;
            cout << "Adres: "<<adresat.adres << endl;
            cout << "Tel: : "<<adresat.tel <<endl<< endl;
        }
    }
    system ("pause");
}

void wyswietlWszystkichAdresatow (vector <Adresat>&adresaci)
{
    for (Adresat adresat:adresaci)
    {
        cout << endl;
        cout <<"Id: "<< adresat.id<< endl;
        cout <<"Imie: "<< adresat.imie << endl;
        cout << "Nazwisko: "<<adresat.nazwisko << endl;
        cout <<"Email: "<< adresat.email << endl;
        cout << "Adres: "<<adresat.adres << endl;
        cout << "Tel: : "<<adresat.tel <<endl<< endl;
    }
    system("pause");
}

void edytujAdresata (vector<Adresat>&adresaci)
{
    string idDoZmiany = "";
    cout <<"Podaj ID adresata, ktorego dane chcesz zmienic: ";
    idDoZmiany = wczytajLinie();
    string imie, nazwisko, tel, email, adres;
    char wybor;

    for (size_t i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].id  == stoi(idDoZmiany))
        {
            system("cls");
            cout <<"Jakie dane chcesz zmienic?"<<endl;
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Nr tel." <<endl;
            cout << "4. Email" << endl;
            cout << "5. Adres" << endl;
            cout << "6. Powrot do menu" << endl;
            wybor = wczytajZnak();

            if (wybor == '1')
            {
                imie = wczytajLinie();
                adresaci[i].imie = imie;
            }
            else if (wybor == '2')
            {
                nazwisko = wczytajLinie();
                adresaci[i].nazwisko = nazwisko;
            }
            else if (wybor == '3')
            {
                tel = wczytajLinie();
                adresaci[i].tel = tel;
            }
            else if (wybor == '4')
            {
                email = wczytajLinie();
                adresaci[i].email = email;
            }
            else if (wybor == '5')
            {
                adres = wczytajLinie();
                adresaci[i].adres = adres;
            }
            else if (wybor == '6')
            {
                break;
            }
        }
        zapiszDaneDoPliku(adresaci);
    }
    system ("pause");
}

void usunAdresata (vector<Adresat>&adresaci)
{
    string idOsobyDoUsuniecia = "";
    cout <<"Podaj ID adresata, ktorego chcesz usunac: ";
    idOsobyDoUsuniecia = wczytajLinie();
    char wybor;
    bool czyIstniejeAdresat = false;

    if (!adresaci.empty())
    {
        for (vector<Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if ((*itr).id  == stoi(idOsobyDoUsuniecia))
            {
                czyIstniejeAdresat = true;
                cout <<"Id: "<<(*itr).id << endl<< "Imie: "<< (*itr).imie <<endl<< "Nazwisko: "<< (*itr).nazwisko <<endl<< "Tel: "<< (*itr).tel<<endl<<"Email: "<<(*itr).email<<endl<< "Adres: "<< (*itr).adres<<endl;
                cout << "Czy napewno chcesz usunac tego adresata? Aby potwierdzic nacisnij 't'"<<endl;
                wybor = wczytajZnak();
                if (wybor == 't')
                {
                    adresaci.erase(itr);
                    cout << "Wybrany adresat zostal usuniety" << endl;
                    system ("pause");
                    break;
                }
                else
                {
                    cout << "Wybrany adresat NIE zostal usuniety!"<<endl;
                    system ("pause");
                }
            }
        }
        if (czyIstniejeAdresat==false)
        {
            cout << "Brak adresata w ksiazce adresowej."<<endl;
            system ("pause");
        }
        zapiszDaneDoPliku(adresaci);
    }
    else
    {
        cout << "Ksiazka adresowa jest pusta"<<endl;
        system ("pause");
    }
}


int main()
{
    vector <Adresat> adresaci ;
    wczytajAdresatowZPliku (adresaci);

    char wybor;

    int licznikID = adresaci.empty() ? 1 : adresaci.back().id+1;

    while(true)
    {
        system("cls");
        cout << "1. Dodaj adresata" << endl;
        cout << "2. Wyszukaj po imieniu" << endl;
        cout << "3. Wyszukaj po nazwisku" <<endl;
        cout << "4. Wyswietl wszystkich adresatow" << endl;
        cout << "5. Usun adresata" <<endl;
        cout << "6. Edytuj adresata" <<endl;
        cout << "9. Zakoncz program" << endl;
        wybor = wczytajZnak();
        if (wybor == '1')
        {
            dodajAdresata(adresaci, licznikID);
        }
        else if (wybor == '2')
        {
            wyszukajPoImieniu(adresaci) ;
        }
        else if (wybor == '3')
        {
            wyszukajPoNazwisku(adresaci);
        }
        else if (wybor == '4')
        {
            wyswietlWszystkichAdresatow(adresaci);
        }
        else if (wybor == '5')
        {
            usunAdresata(adresaci);
        }
        else if (wybor == '6')
        {
            edytujAdresata(adresaci);
        }
        else if (wybor == '9')
        {
            exit(0);
        }
    }
    return 0;
}



