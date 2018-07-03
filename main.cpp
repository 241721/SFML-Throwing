#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Przycisk.h"
#include <vector>
using namespace sf;
using namespace std;

int main()
{
    //OKNA APLIKACJI:
    RenderWindow oknoGry( VideoMode( 1920, 1080, 32 ), "Throwing", Style::Fullscreen );
    oknoGry.setFramerateLimit(120);
    sf::Font czcionka;
    czcionka.loadFromFile("WorkSans.otf");
    Text adres;
    adres.setFont(czcionka);
    adres.setCharacterSize(50);
    adres.setColor(Color::White);
    Text adres2;
    adres2.setFont(czcionka);
    adres2.setCharacterSize(50);
    adres2.setColor(Color::White);
    adres2.move(0,200);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector < Przycisk > przyciski;
    Przycisk* nowy=new Przycisk(Vector2f(1000,0),"",czcionka);
    Przycisk* nowy2=new Przycisk(Vector2f(1300,0),"",czcionka);
    przyciski.push_back(*nowy);
    przyciski.push_back(*nowy2);
    delete nowy;
    delete nowy2;
    int licznik=2;
    sf::Vector2i pozycjaMyszki = sf::Mouse::getPosition();
    sf::Vector2i pozycjaMyszki2 = sf::Mouse::getPosition();
    sf::Vector2i predkosc;
    int badanie=0;
    while(oknoGry.isOpen())
    {

        Event zdarzenie;
        while( oknoGry.pollEvent( zdarzenie ) )
        {
            if( Keyboard::isKeyPressed(Keyboard::Enter) )
            {

            }
            if( Keyboard::isKeyPressed(Keyboard::Q) )
            {

            }
            if( Keyboard::isKeyPressed(Keyboard::Escape) )
            {
                oknoGry.close();
            }
        }
        pozycjaMyszki = sf::Mouse::getPosition();
        oknoGry.clear();

        for(int i=0;i<licznik;i++) oknoGry.draw(przyciski[i]);
        oknoGry.draw(adres);
        oknoGry.draw(adres2);
        oknoGry.display();
        pozycjaMyszki2 = sf::Mouse::getPosition();
        predkosc=pozycjaMyszki2-pozycjaMyszki;
        for(int i=0;i<licznik;i++)
        {
            if(przyciski[i].sprawdzPrzycisk(predkosc)==1);

        }
            adres.setString(to_string(przyciski[0].wek.x));
            adres2.setString(to_string(przyciski[0].wek.y));
        przyciski[0].ruch();
        przyciski[1].ruch();


    }
    return 0;
}
