#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <iostream>


/*!
 * \brief Klasa modeluje prostopadloscian w trojwymiarowym ukladzie wspolrzednych.
 * Klasa modeluje prostopadloscian w trojwymiarowym ukladzie wspolrzednych. 
 * Klase tworza wspolrzedne osmiu punktow reprezentujacych wierzcholki prostopadloscianu.
 */
class Prostopadloscian 
{
    Wektor3D A, B, C, D, E, F, G, H; /* wierzcholki do narysowania */
public:
    Prostopadloscian(void) { A=Wektor3D();
                             B=Wektor3D();
                             C=Wektor3D();
                             D=Wektor3D();
                             E=Wektor3D();
                             F=Wektor3D();
                             G=Wektor3D();
                             H=Wektor3D(); } /* konstruktor bezargumentowy */
    Wektor3D PobierzWspolrzedna(char Wsp); /* getter */
    void UstawWspolrzedna(char Wsp, float x, float y, float z); /* setter */
    void Obrot(Macierz3x3 Mac_Rotacji);
    void Przesuniecie(Wektor3D Wek_Przesuniecia);
    void Sprawdzboki();
};

    Macierz3x3 Ustaw_Mac_Rotacji(double alfa, char Os);
    Wektor3D Ustaw_Wek_Przesuniecia(void);

/*!
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Prostopadloscian.
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Prostopadloscian.
 * Pozwala wypisac wartosci typu float wspolrzednych wierzcholkow.
 * Korzysta z przeciazenia operatora pisania dla klasy Wektor2D.
 * Pierwszym parametrem jest referencja do strumiena wyjsciowego.
 * Drugim parametrem referencja do obiektu klasy Prostokat.
 * Slowo kluczowe const chroni przed niepozadana zmiana wartosci wspolrzednych wierzcholkow.
 */
std::ostream& operator << (std::ostream &Strm, Prostopadloscian &Pr);


#endif
