/*
Projekt i implementacja programu obliczającego całkę złożoną metodą trapezów, Michał Żuk 87604 oddzielny plik z funkcjami programu
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "funkcje.cpp"

using namespace std;

void wprowadzanie_x(Funkcja *f);

void uzupelnij_wielomian(Funkcja *f);

void wprowadzanie_zmiennych_funkcyjnych(int w, Funkcja *f);

double sumowanie(int w, Funkcja *f);

void wpisanie_do_pliku_wzoru(int w, Funkcja *f);

int menu_glowne();

void wyniki(Funkcja *f);

void wprowadzanie_zmiennych_funkcyjnych(int w, Funkcja *f)
{
    switch (w)
    {
    case 1:
        cout << "Podaj a (a*sin(b*x)): ";
        cin >> f->a;
        cout << "Podaj b (a*sin(b*x)): ";
        cin >> f->b;
        break;
    case 2:
        cout << "Podaj a (a*cos(x)): ";
        cin >> f->a;
        cout << "Podaj b cos(b*x): ";
        cin >> f->b;
        break;
    case 3:
        cout << "Podaj a (a/b*x^c): ";
        cin >> f->a;
        cout << "Podaj b (a/b*x^c): ";
        cin >> f->b;
        cout << "Podaj c (a/b*x^c): ";
        cin >> f->c;
        break;
    case 4:
        cout << "Podaj stopień wielomianu: ";
        cin >> f->stopien;
        (f->stopien)++;
        break;
    case 5:
        cout << "Podaj a (a*(b^x)): ";
        cin >> f->a;
        cout << "Podaj b (a*(b^x)): ";
        cin >> f->b;
        break;
    case 6:
        do
        {
            cout << "Podaj rodzaj logarytmu.\n1.Logarytm naturalny.\n2.Logarytm o innej podstawie: ";
            cin >> f->d;
        } while (!(f->d == 1 || f->d == 2));
        cout << "Podaj a (a*log_";
        if (f->d == 1)
            cout << "e: ";
        else
            cout << "b";
        cout << "(c*x): ";
        cin >> f->a;
        if (f->d == 2)
        {
            cout << "Podaj b (a*log_b(c*x)): ";
            cin >> f->b;
        }
        cout << "Podaj c (a*log_";
        if (f->d == 1)
            cout << "e: ";
        else
            cout << "b";
        cout << "(c*x): ";
        cin >> f->c;
        break;
    case 7:
        cout << "Podaj a (a * e^(b*x)): ";
        cin >> f->a;
        cout << "Podaj b (a * e^(b*x)): ";
        cin >> f->b;
        break;
    case 8:
        cout << "Podaj a (a * sqrt c stopnia(b * x)): ";
        cin >> f->a;
        cout << "Podaj b (a * sqrt c stopnia(b * x)): ";
        cin >> f->b;
        cout << "Podaj stopień c (a * sqrt c stopnia(b * x)): ";
        cin >> f->c;
        break;
    case 9:
        cout << "Podaj a (a*|b*x|): ";
        cin >> f->a;
        cout << "Podaj b (a*|b*x|: ";
        cin >> f->b;
        break;
    case 10:
        cout << "Podaj a (a*tg(b*x): ";
        cin >> f->a;
        cout << "Podaj b (a*tg(b*x)): ";
        cin >> f->b;
        break;
    case 11:
        cout << "Podaj a (a*ctg(b*x)): ";
        cin >> f->a;
        cout << "Podaj a (a*ctg(b*x)): ";
        cin >> f->b;
        break;
    }
}

double sumowanie(int w, Funkcja *f)
{
    double wynik;
    double s = 0;
    for (int i = 1; i < f->N; i++)
    {
        wynik = 0;
        switch (w)
        {
        case 1:
            wynik = sin_f(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 2:
            wynik = cos_f(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 3:
            wynik = wykladnicza(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 4:
            wynik = wielomian(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 5:
            wynik = potegowa(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 6:
            wynik = logarytm(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 7:
            wynik = exp_f(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 8:
            wynik = sqrt_f(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 9:
            wynik = modul(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 10:
            wynik = tg(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        case 11:
            wynik = ctg(f->x_poczatkowe + (i * f->dx), f);
            s += wynik;
            break;
        }
    }

    switch (w)
    {
    case 1:
        s = (s + (sin_f(f->x_poczatkowe, f) + sin_f(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 2:
        s = (s + (cos_f(f->x_poczatkowe, f) + cos_f(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 3:
        s = (s + (wykladnicza(f->x_poczatkowe, f) + wykladnicza(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 4:
        s = (s + (wielomian(f->x_poczatkowe, f) + wielomian(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 5:
        s = (s + (potegowa(f->x_poczatkowe, f) + potegowa(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 6:
        s = (s + (logarytm(f->x_poczatkowe, f) + logarytm(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 7:
        s = (s + (exp_f(f->x_poczatkowe, f) + exp_f(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 8:
        s = (s + (sqrt_f(f->x_poczatkowe, f) + sqrt_f(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 9:
        s = (s + (modul(f->x_poczatkowe, f) + modul(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 10:
        s = (s + (tg(f->x_poczatkowe, f) + tg(f->x_koncowe, f)) / 2) * f->dx;
        break;
    case 11:
        s = (s + (ctg(f->x_poczatkowe, f) + ctg(f->x_koncowe, f)) / 2) * f->dx;
        break;
    }
    return s;
}

void wyniki(Funkcja *f)
{
    cout << "Wartość całki wynosi: " << f->suma;
    fstream plik;

    plik.open("wyniki.txt", ios::app);

    if (!plik.good())
    {
        cout << "Nie udało się otworzyć pliku.";
        exit(-1);
    }
    plik << "Wartość całki wynosi dla " << f->N << " trapezów oraz x początkowego: " << f->x_poczatkowe << " i x końcowego: " << f->x_koncowe << " wynosi: " << f->suma << '\n';
    plik.close();
}

int menu_glowne()
{
    cout << "\nProgram obliczjący całkę złożoną metodą trapezów.\n";
    int wybor = -1;
    do
    {
        cout << "\nMenu główne.\n1.Oblicz całkę.\n2.Wyświetl poprzednie wyniki.\n3.Koniec.\n";
        cin >> wybor;
    } while (wybor < 1 || wybor > 3);
    return wybor;
}

void wpisanie_do_pliku_wzoru(int w, Funkcja *f)
{
    fstream plik;

    plik.open("wyniki.txt", ios::app);

    if (!plik.good())
    {
        cout << "Nie udało się otworzyć pliku.";
        exit(-1);
    }

    plik << "Twój wzór funkcji: ";

    switch (w)
    {
    case 1:

        plik << f->a << " * sin( " << f->b << " * x )";
        break;
    case 2:
        plik << f->a << " * cos( " << f->b << " * x )";
        break;
    case 3:
        plik << f->a << " / " << f->b << " * x^" << f->c;
        break;
    case 4:
        for (int i = f->stopien - 1; i >= 0; i--)
        {
            plik << f->tab[i] << " * x^" << i;
            if (i != 0)
                plik << " + ";
        }
        break;
    case 5:
        plik << f->a << " * " << f->b << "^x";
        break;
    case 6:
        plik << f->a << " * log_";
        if (f->d == 1)
            plik << "e: ";
        else
            plik << f->b;
        plik << "( " << f->c << " * x )";
        break;
    case 7:
        plik << f->a << " * e^( " << f->b << " * x )";
        break;
    case 8:
        plik << f->a << " * sqrt " << f->c << " stopnia( " << f->b << " * x )";
        break;
    case 9:
        plik << f->a << "* | " << f->b << " * x |";
        break;
    case 10:
        plik << f->a << " * tg( " << f->b << " * x )";
        break;
    case 11:
        plik << f->a << " * ctg( " << f->b << " * x )";
        break;
    }
    plik << '\n';
    plik.close();
}

void wprowadzanie_x(Funkcja *f)
{
    cout << "Podaj ilość trapezów: ";
    cin >> f->N;
    while (f->N < 1)
    {
        cout << "Podałeś złą ilość trapezów, min 1, podaj nową ilość: ";
        cin >> f->N;
    }

    cout << "Podaj x początkowe: ";
    cin >> f->x_poczatkowe;

    cout << "Podaj x końcowe: ";
    cin >> f->x_koncowe;
}

void uzupelnij_wielomian(Funkcja *f)
{
    for (int i = f->stopien - 1; i >= 0; i--)
    {
        cout << "Podaj a" << i << ": ";
        cin >> f->tab[i];
    }
}

void tablica_wielomian(Funkcja *f, bool tworzenie)
{
    if (tworzenie)
    {
        if (f->stopien != -1)
        {
            f->tab = new double[f->stopien];
            uzupelnij_wielomian(f);
        }
    }
    else
    {
        if (f->stopien != -1)
            delete[] f->tab;
    }
}

void wypisanie_wynikow()
{
    fstream plik;
    plik.open("wyniki.txt", ios::in);
    if (!plik.good())
    {
        cout << "Nie udało się otworzyć pliku.";
        exit(-1);
    }
    string temp;
    cout << "Twoje poprzednie wyniki: \n";
    while (getline(plik, temp))
    {
        cout << temp << '\n';
    }
    plik.close();
}

void obliczanie_calki()
{
    int w = -1;
    do
    {
        cout << "Jaki rodzaj funkcji:\n1.a*Sin(b*x).\n2.a*Cos(b*x)\n3.Hiperboliczna: a/b*x^c.\n4.Wielomian.\n5.Potęgowa a*(b^x).\n6.Logarytm a*log_b(c*x).\n7.Potęgowa a*e^(b*x).\n8.Pierwiastek a*sqrt[c]stopnia(b*x).\n9.Funkcja moduł a*|b*x|.\n10.a*Tg(b*x).\n11.a*Ctg(b*x).\n";
        cin >> w;
    } while (w < 1 || w > 11);

    Funkcja f;
    f.N = 0;
    f.suma = 0;
    f.stopien = -1;

    wprowadzanie_zmiennych_funkcyjnych(w, &f);

    tablica_wielomian(&f, true);

    wprowadzanie_x(&f);

    sprawdzanie_dziedziny(w, &f);

    wpisanie_do_pliku_wzoru(w, &f);

    f.dx = (f.x_koncowe - f.x_poczatkowe) / f.N;

    f.suma = sumowanie(w, &f);

    tablica_wielomian(&f, false);

    wyniki(&f);
}