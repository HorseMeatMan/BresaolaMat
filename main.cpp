#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

sf::ConvexShape* buttons(float coords[3]) {

    float x = coords[0];
    float y = coords[1];
    float z = coords[2];

    sf::ConvexShape b1;
    b1.setPointCount(4);
    b1.setPoint(0, sf::Vector2f((x+0) * z, (y + 0) * z));
    b1.setPoint(1, sf::Vector2f((x + 0) * z, (y + 10) * z));
    b1.setPoint(2, sf::Vector2f((x + 25) * z, (y + 10) * z));
    b1.setPoint(3, sf::Vector2f((x + 25) * z, (y + 0) * z));
    b1.setOutlineColor(sf::Color::Red);
    b1.setOutlineThickness(5);
    b1.setPosition({ 10, 20 });

    static sf::ConvexShape arr[1] = { b1 };
    return arr;


}
int main() {
    
    sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "BresaolaMat 2.0.0");
    sf::Texture texture;
    
    if(!texture.loadFromFile("x64/Debug/sprite/texture.png"))
    {
        std::cerr << "Error loading texture" << std::endl;
    }
    
    sf::Sprite sprite(texture);
    
    float x = 10;
    float y = 500;
    float mult = 2;
    float coords[3] = { x, y, mult };

    sf::ConvexShape* arr = buttons(coords);
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.draw(arr[0]);
        window.display();
    }
    
    

}
