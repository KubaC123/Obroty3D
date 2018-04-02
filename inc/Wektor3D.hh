#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include <iostream>


/*! 
 * \brief Klasa Wektor3D modeluje wektor w ukladzie wspolrzednych.
 * Klasa modeluje wektor w ukladzie trojwymiarowym (x, y, z). 
 * Obiekt tego typu tworza wartosci elementow tablicy Wspolrzedne[3],
 * ktora przechowuje wartosci trzech skladowych wektora.
 */
class Wektor3D 
{
float Wspolrzedne[3];
public:
float operator[] (int Indeks) const {return Wspolrzedne[Indeks];}
float& operator[] (int Indeks) {return Wspolrzedne[Indeks];}
Wektor3D(void) {Wspolrzedne[0]=0, Wspolrzedne[1]=0, Wspolrzedne[2]=0;}
Wektor3D(float x, float y, float z) {Wspolrzedne[0]=x, Wspolrzedne[1]=y, Wspolrzedne[2]=z;}
};

Wektor3D operator + (Wektor3D W1, Wektor3D W2);

/*! 
 * \brief Przeciazenie operatora czytania ze strumienia wejsciowego dla klasy Wektor3D
 * Przeciazenie operatora czytania ze stumienia wejsciowego dla klasy Wektor3D.
 * Pozwala przypisac wartosci typu float wspolrzednym wektora zapisanym w tablicy Wspolrzedne[3].
 * Korzysta z przeciazenia operatora indeksowania.
 * Pierwszym parametrem jest referencja do strumiena wejsciowego.
 * Drugim parametrem referencja do obiektu klasy Wektor3D.
 */
std::istream& operator >> (std::istream &Strm, Wektor3D &Wek);

/*! 
 * \brief Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Wektor3D.
 * Przeciazenie operatora pisania do strumienia wyjsciowego dla klasy Wektor3D.
 * Pozwala wypisac wartosci typu float wspolrzednych wektora.
 * Korzysta z przeciazenia operatora indeksowania.
 * Pierwszym parametrem jest referencja do strumiena wyjsciowego.
 * Drugim parametrem referencja do obiektu klasy Wektor3D.
 * Slowo kluczowe const chroni przed niepozadana zmiana wartosci wspolrzednych.
 */
std::ostream& operator << (std::ostream &Strm, const Wektor3D &Wek);

#endif
