#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main() {
    
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "BresaolaMat 2.0.0");
    sf::Texture texture;
    
    if(!texture.loadFromFile("x64/Debug/sprite/texture.png"))
    {
        std::cerr << "Error loading texture" << std::endl;
    }
    
    sf::Sprite sprite(texture);

    sf::FloatRect b1 = sprite.sf::Sprite::getGlobalBounds();
   
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        sf::Vector2i mousepos = sf::Mouse::getPosition(window);
        if (b1.contains(static_cast<sf::Vector2f>(mousepos))) {
            std::cout << "in ";
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    
    

}
