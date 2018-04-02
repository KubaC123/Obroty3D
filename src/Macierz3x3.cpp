#include "Macierz3x3.hh"

/* przeciazenie operatora mnozenia wektora przez macierz */
Wektor3D Macierz3x3::operator*(Wektor3D Wek)
{
    Wektor3D W;
    W[0]=Wek[0]*Wiersz[0][0] + Wek[1]*Wiersz[0][1] + Wek[2]*Wiersz[0][2];
    W[1]=Wek[0]*Wiersz[1][0] + Wek[1]*Wiersz[1][1] + Wek[2]*Wiersz[1][2];
    W[2]=Wek[0]*Wiersz[2][0] + Wek[1]*Wiersz[2][1] + Wek[2]*Wiersz[2][2];
    return W;
}

/* przeciazenie operatora pisania do strumienia wyjsciowego */
std::ostream& operator << (std::ostream &Strm, Macierz3x3 const& Mac)
{
    std::cout << Mac[0] << std::endl;
    std::cout << Mac[1] << std::endl;
    std::cout << Mac[2] << std::endl;
    return Strm;
}
