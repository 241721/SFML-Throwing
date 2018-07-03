#include "Przycisk.h"

Przycisk::Przycisk(sf::Vector2f poz, std::string teks, sf::Font & czcion)
{

    int dlugosc=teks.size();
    ksztalt.setFillColor(sf::Color::Red);
    ksztalt.setPosition(poz);
    ksztalt.setSize(sf::Vector2f(50,50));
    tekst.setString(teks);
    tekst.setColor(sf::Color::White);
    tekst.setCharacterSize(20);
    tekst.setFont(czcion);
    //sf::Vector2f ksztaltOrigin((ksztalt.getOrigin().x+ksztalt.getSize().x)/2,ksztalt.getOrigin().y);
    tekst.setPosition(poz);
    czcionka=czcion;
    licznik=0;
    tarcie.x=0.1;
    tarcie.y=0.1;

}
void Przycisk::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(ksztalt, states);
    target.draw(tekst, states);
}

bool Przycisk::sprawdzPrzycisk(sf::Vector2i wektor1)
{
    sf::Vector2i pozycjaMyszki = sf::Mouse::getPosition();

    if(pozycjaMyszki.x>=ksztalt.getPosition().x&&pozycjaMyszki.x<=ksztalt.getPosition().x+ksztalt.getSize().x&&pozycjaMyszki.y>=ksztalt.getPosition().y&&pozycjaMyszki.y<=ksztalt.getPosition().y+ksztalt.getSize().y)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&licznik==0)
        {
            licznik++;

        }
        else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)) licznik=0;

    }
    if (licznik>0)
    {
        ksztalt.setPosition(pozycjaMyszki.x-ksztalt.getSize().x/2,pozycjaMyszki.y-ksztalt.getSize().y/2);
        tekst.setPosition(pozycjaMyszki.x-ksztalt.getSize().x/2,pozycjaMyszki.y-ksztalt.getSize().y/2);
        updateWek(wektor1);
    }
}
void Przycisk::updateWek(sf::Vector2i wektor)
{
    wek=(sf::Vector2f)wektor;
}
void Przycisk::ruch()
{
    ksztalt.move((sf::Vector2f)wek);
    tekst.move((sf::Vector2f)wek);
    sprawdzBoki();
    hamowanie();
}
void Przycisk::hamowanie()
{
    tarcie.x=wek.x/10;
    tarcie.y=wek.y/10;
    wek.x-=tarcie.x;
    wek.y-=tarcie.y;
}
void Przycisk::sprawdzBoki()
{
    if(ksztalt.getPosition().x<0) wek.x=-wek.x;
    else if(ksztalt.getPosition().x+ksztalt.getSize().x>1920) wek.x=-wek.x;
    if(ksztalt.getPosition().y<0) wek.y=-wek.y;
    else if (ksztalt.getPosition().y+ksztalt.getSize().y>1080) wek.y=-wek.y;
}
