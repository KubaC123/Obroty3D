#include "Prostopadloscian.hh"
#include <iostream>
#include <cmath>
#include <cstring>

/* Funkcja pozwala pobrac dowolna wspolrzedna prostokata */
Wektor3D Prostopadloscian::PobierzWspolrzedna(char Wsp)
{
    switch (Wsp)
    {
        case 'A':
        return A;
        break;

        case 'B':
        return B;
        break;

        case 'C':
        return C;
        break;

        case 'D':
        return D;
        break;

        case 'E':
        return E;
        break;

        case 'F':
        return F;
        break;

        case 'G':
        return G;
        break;
         
        case 'H':
        return H;
        break;
        
        default:
        std::cerr << "Blad. Nie ma takiej wspolrzednej (A, B, C, D, E, F, G, H)" << std::endl;
        return Wektor3D(0, 0, 0);
        break;
    }
}

/* Funkcja pozwala ustawic dowolna wspolrzedna figury */
void Prostopadloscian::UstawWspolrzedna(char Wsp, float x, float y, float z)
{
    switch (Wsp)
    {
        case 'A':
        A=Wektor3D(x, y, z);
        break;

        case 'B':
        B=Wektor3D(x, y, z);
        break;

        case 'C':
        C=Wektor3D(x, y, z);
        break;

        case 'D':
        D=Wektor3D(x, y, z);
        break;

        case 'E':
        E=Wektor3D(x, y, z);
        break;

        case 'F':
        F=Wektor3D(x, y, z);
        break;

        case 'G':
        G=Wektor3D(x, y, z);
        break;

        case 'H':
        H=Wektor3D(x, y, z);
        break;

        default:
        std::cerr << "Blad. Nie ma takiej wspolrzednej (A, B, C, D, E, F, G, H)" << std::endl;
        break;
    }
}

/* Funkcja obracajaca figure */
void Prostopadloscian::Obrot(Macierz3x3 Mac_Rotacji)
{
    A = Mac_Rotacji*A;
    B = Mac_Rotacji*B;
    C = Mac_Rotacji*C;
    D = Mac_Rotacji*D;
    E = Mac_Rotacji*E;
    F = Mac_Rotacji*F;
    G = Mac_Rotacji*G;
    H = Mac_Rotacji*H;
}

/* Funkcja przesuwajaca figue */
void Prostopadloscian::Przesuniecie(Wektor3D Wek_Przesuniecia)
{
    A=A+Wek_Przesuniecia;
    B=B+Wek_Przesuniecia;
    C=C+Wek_Przesuniecia;
    D=D+Wek_Przesuniecia;
    E=E+Wek_Przesuniecia;
    F=F+Wek_Przesuniecia;
    G=G+Wek_Przesuniecia;
    H=H+Wek_Przesuniecia;
}

/* Funkcja sprawdza dlugosc bokow */
void Prostopadloscian::Sprawdzboki()
{
    if(PobierzWspolrzedna('A')[0]-PobierzWspolrzedna('B')[0] == PobierzWspolrzedna('C')[0]-PobierzWspolrzedna('D')[0])
    {
        if(PobierzWspolrzedna('A')[1]-PobierzWspolrzedna('C')[1] == PobierzWspolrzedna('B')[1]-PobierzWspolrzedna('D')[1])
        {
            std::cout << "Wybrane przeciwlegle boki sa sobie rowne." << std::endl;
        }
    }
    else
    std::cout << "Wybrane przeciwlegle boki NIE sa sobie rowne." << std::endl;
}

Macierz3x3 Ustaw_Mac_Rotacji(double alfa, char Os)
{
    Macierz3x3 M;
    switch (Os)
    {
        case 'x':
        {
            M[0][0] = 1;
            M[0][1] = 0;
            M[0][2] = 0;

            M[1][0] = 0;
            M[1][1] = cos(alfa);
            M[1][2] = -sin(alfa);

            M[2][0] = 0;
            M[2][1] = sin(alfa);
            M[2][2] = cos(alfa);
            return M;
            break;
        }

        case 'y':
        {
            M[0][0] = cos(alfa);
            M[0][1] = 0;
            M[0][2] = sin(alfa);

            M[1][0] = 0;
            M[1][1] = 1;
            M[1][2] = 0;

            M[2][0] = -sin(alfa);
            M[2][1] = 0;
            M[2][2] = cos(alfa);
            return M;
            break;
        }

        case'z':
        {
            M[0][0] = cos(alfa);
            M[0][1] = -sin(alfa);
            M[0][2] = 0;

            M[1][0] = sin(alfa);
            M[1][1] = cos(alfa);
            M[1][2] = 0;

            M[2][0] = 0;
            M[2][1] = 0;
            M[2][2] = 1;
            return M;
            break;
        }

        default:
        {
            std::cerr << "Blad. Obrot mozliwy wokol osi x, y, z." << std::endl;
            return M;
            break;
        }
    }
}

Wektor3D Ustaw_Wek_Przesuniecia()
{
    Wektor3D Wek;
    std::cout << "Wprowadz wspolrzedne wektora translacji w postaci trzech liczb:" << std::endl;
    std::cin >> Wek[0];
    if(std::cin.fail())
    {
        std::cerr << "Blad. Wspolrzedna wektora musi byc liczba!" << std::endl;
        std::exit(1);
    }
    else
    {
    std::cin >> Wek[1];
    if(std::cin.fail())
    {
        std::cerr << "Blad. Wspolrzedna wektora musi byc liczba!" << std::endl;
        std::exit(1);
    }
    else
    {
    std::cin >> Wek[2];
    if(std::cin.fail())
    {
        std::cerr << "Blad. Wspolrzedna wektora musi byc liczba!" << std::endl;
        std::exit(1);
    }
    }
    }
    return Wek;
}

/* przeciazenie operatora pisania do strumienia wyjsciowego */
std::ostream& operator << (std::ostream &Strm, Prostopadloscian &Pr)
{
    std::cout << Pr.PobierzWspolrzedna('A')
    << Pr.PobierzWspolrzedna('B')
    << Pr.PobierzWspolrzedna('C')
    << Pr.PobierzWspolrzedna('D')
    << Pr.PobierzWspolrzedna('E')
    << Pr.PobierzWspolrzedna('F')
    << Pr.PobierzWspolrzedna('G')
    << Pr.PobierzWspolrzedna('H') << std::endl;
    return Strm;
}
