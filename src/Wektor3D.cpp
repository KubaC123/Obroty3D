#include "Wektor3D.hh"

/* przeciazenie operator dodawania dla obiektu Wektor3D */
Wektor3D operator + (Wektor3D W1, Wektor3D W2)
{
    Wektor3D Wek;
    Wek[0]=W1[0]+W2[0];
    Wek[1]=W1[1]+W2[1];
    Wek[2]=W1[2]+W2[2];
    return Wek;
}

/* przeciazenie operatora czytania ze strumienia wejsciowego */
std::istream& operator >> (std::istream &Strm, Wektor3D &Wek)
{
    float x, y, z;
    Strm >> x;
    if(Strm.fail())
    {
        std::cerr << "Blad. Niepoprawna pierwsza wspolrzedna" << std::endl;
        return Strm;
    } 
    else Wek[0]=x;
    
    Strm >> y;
    if(Strm.fail())
    {
        std::cerr << "Blad. Niepoprawna druga wspolrzedna" << std::endl;
        return Strm;
    }
    else Wek[1]=y;
        
    Strm >> z;
    if(Strm.fail())
    {
        std::cerr << "Blad. Niepoprawna druga wspolrzedna" << std::endl;
        return Strm;
    }
    else Wek[2]=z;
    return Strm;
}

/* przeciazenie operatora pisania do strumienia wyjsciowego */
std::ostream& operator << (std::ostream &Strm, Wektor3D const& Wek)
{
    Strm << "[" << Wek[0] << "," << Wek[1] << "," << Wek[2] << "]";
    return Strm;
}
