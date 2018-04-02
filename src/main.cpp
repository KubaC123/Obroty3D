#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"

/* Funkcja do wypisywania opcji menu */
void menu()
{
  std::cout << "o - obroty bryly o zadana sekwencje katow" << std::endl;
  std::cout << "t - powtorzenie poprzedniego obrotu" << std::endl;
  std::cout << "r - wyswietlenie macierzy rotacji" << std::endl;
  std::cout << "p - przesuniecie bryly o zadany wektor" << std::endl;
  std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
  std::cout << "s - sprawdzenie dlugosci przeciwleglych bokow" << std::endl;
  std::cout << "m - wyswietl menu" << std::endl;
  std::cout << "k - koniec dzialana programu" << std::endl;
}

#define DL_BOKU   50


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
void ZapisWspolrzednychDoStrumienia(std::ostream& StrmWy, Prostopadloscian Pr)
{


  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('A')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('A')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('A')[2]
         << std::endl;

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('B')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('B')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('B')[2]
         << std::endl;

  StrmWy << std::endl;

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('C')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('C')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('C')[2]
         << std::endl;

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('D')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('D')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('D')[2]
         << std::endl;

  StrmWy << std::endl;

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('E')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('E')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('E')[2]
         << std::endl;

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('F')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('F')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('F')[2]
         << std::endl;

  StrmWy << std::endl;

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('G')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('G')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('G')[2] 
         << std::endl;

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('H')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('H')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('H')[2]
         << std::endl;

  StrmWy << std::endl;
 
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('A')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('A')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('A')[2]
         << std::endl;

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('B')[0]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('B')[1]
         << std::setw(16) << std::fixed << std::setprecision(10) << Pr.PobierzWspolrzedna('B')[2]
         << std::endl;
                             // Jeszcze raz zapisujemy pierwsze dwa wierzcholki,
                             // aby gnuplot narysowal zamkniętą powierzchnie.
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian Pr)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  ZapisWspolrzednychDoStrumienia(StrmPlikowy,Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}



int main()
{
  Prostopadloscian Pr;
  Pr.UstawWspolrzedna('A',20, 20, 20);
  Pr.UstawWspolrzedna('B',10, 20, 20);
  Pr.UstawWspolrzedna('C',20, 40, 20);
  Pr.UstawWspolrzedna('D',10, 40, 20);
  Pr.UstawWspolrzedna('E',20, 40, 30);
  Pr.UstawWspolrzedna('F',10, 40, 30);
  Pr.UstawWspolrzedna('G',20, 20, 30);
  Pr.UstawWspolrzedna('H',10, 20, 30);

  char os;
  double alfa;
  Macierz3x3 M;
  Wektor3D W;
  
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostopadloscian.dat",PzG::RR_Ciagly,2);
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-155,155);
  Lacze.UstawZakresX(-155,155);
  Lacze.UstawZakresZ(-155,155);

  
  ZapisWspolrzednychDoStrumienia(std::cout, Pr);
  if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", Pr)) return 1;
  Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

/* MENU */

 std::cout << std::endl <<"*** ROTACJE 3D ***" << std::endl << std::endl;
  char wybor = 'a';
  menu();
  std::cin >> wybor;
  while (wybor != 'k')
  {
    switch (wybor)
    {
      /* Obrot o kat */
      case 'o':
      { 
        std::vector < Macierz3x3 > Tab_Rotacji;
        int blad=0; /* sprawdzamy czy wystapil blad przy podawaniu osi lub kata */
        std::cout << "Podaj sekwencje osi i katow." << std::endl;
        while(1)
        {
          std::cin >> os;
          if(os == '.') break; /* czy znak konca danych */
          if(!strchr("xyz", os)) 
          {
            std::cerr << "Blad. Wybierz os sposrod x, y, z" << std::endl;
            blad++;
            break;
          }
          else 
          {
            std::cin >> alfa;
            if(std::cin.fail())
            {
              std::cerr << "Niepoprawnie podany kat." << std::endl;
              blad++;
              break;
            }
            M = Ustaw_Mac_Rotacji(alfa, os);
            Tab_Rotacji.push_back(M);
          }
        }

        if(blad!=0)
        {
          std::cout << "Wystapil blad sprobuj jeszcze raz." << std::endl;
          Tab_Rotacji.clear();
          break;
        }

        int n=1, i, j; /* n - ile razy obrocic */
        std::cout << "Ile razy operacja obrotu ma byc powtorzona?:" << std::endl;
        std::cin >> n;
        if(std::cin.fail())
        {
          std::cerr << "Blad. Ilosc obrotow musi byc liczba!" << std::endl;
          exit(1);
        }
        else
        {
          for (j=0; j < Tab_Rotacji.size(); j++)
          {
            for (i=0; i<n; i++) Pr.Obrot(Tab_Rotacji[j]); /* obracamy n razy */
          }
          if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", Pr)) return 1;
          Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        }

        M = Tab_Rotacji.back();
        Tab_Rotacji.clear();
        break;
      }

      case 't':
      {
        Pr.Obrot(M);
        if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", Pr)) return 1;
        Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        break;
      }

      case 'r':
      {
        std::cout << "Macierz rotacji:" << std::endl << M << std::endl;
        break;
      }

      /* Przesuniecie o wektor */
      case 'p':
      {
        W = Ustaw_Wek_Przesuniecia();
        Pr.Przesuniecie(W);
        if (!ZapisWspolrzednychDoPliku("prostopadloscian.dat", Pr)) return 1;
        Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        break;
      }
      /* Wyswietlenie wspolrzednych wierzcholkow */
      case 'w':
      {
        std::cout << Pr;
        break;
      }
      /* Sprawdzenie dlugosci bokow */
      case 's':
      {
        Pr.Sprawdzboki();
        break;
      }

      case 'm':
      {
        menu();
        break;
      }
      
      case 'k':
      {
        return 0;
        break;
      }
      
      default:
      {
        std::cerr << "Blad. Wybierz jedna z opcji!" << std::endl;
        break;
      }
    }
    std::cout << "Twoj wybor ? (m - menu)" << std::endl;
    std::cin >> wybor;
  }
  return 0;
}

