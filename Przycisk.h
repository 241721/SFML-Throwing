#ifndef PRZYCISK_H
#define PRZYCISK_H
#include <SFML/Graphics.hpp>
#include <string>

class Przycisk: public sf::Drawable, sf::Transformable
{
    public:
        sf::Text tekst;
        sf::Font czcionka;
        sf::Vector2f pozycja;
        sf::RectangleShape ksztalt;
        int licznik;
        sf::Vector2f wek;
        sf::Vector2f tarcie;
    public:
        Przycisk(sf::Vector2f poz, std::string teks, sf::Font & czcion);
        bool sprawdzPrzycisk(sf::Vector2i wektor1);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateWek(sf::Vector2i wektor);
        void ruch();
        void hamowanie();
        void sprawdzBoki();
};

#endif // PRZYCISK_H
