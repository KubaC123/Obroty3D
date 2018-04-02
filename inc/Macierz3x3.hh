#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>
#include "Wektor3D.hh"


/*!
 * \brief Klasa modeluje macierz rozmiaru 3x3.
 * Klasa modeluje macierz rozmiaru 3x3.
 * Obiekt tego typu tworzy dwuelementowa tablica stworzona z dwoch obiektow typu Wektor3D. 
 * Pozwala to przechowywac 9 liczby typu float, odpowiadajace elementom macierzy.
 */
class Macierz3x3
{
    Wektor3D Wiersz[3];
public:
    const Wektor3D& operator[] (int Wie) const {return Wiersz[Wie];}
    Wektor3D& operator[] (int Wie) {return Wiersz[Wie];}
    Macierz3x3(void) {Wiersz[0]=Wektor3D(); Wiersz[1]=Wektor3D(); Wiersz[2]=Wektor3D();} /* konstruktor bezargumentowy */
    Wektor3D operator * (Wektor3D W);
};


/*!
 * /brief Przeciazenie operatora pisania do strumienia wyjsciowego dla obiektu typu Macierz3x3.
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla obiektu typu Macierz3x3.
 * Pozwala wypisac wartosci typu float elementow macierzy.
 * Korzysta z przeciazenia operatora indeksowania.
 * Pierwszym parametrem jest referencja do strumiena wyjsciowego.
 * Drugim parametrem referencja do obiektu klasy Macierz3x3.
 * Slowo kluczowe const chroni przed niepozadana zmiana wartosci elementow.
 */
std::ostream& operator << (std::ostream &Strm, const Macierz3x3 &Mac);

#endif
