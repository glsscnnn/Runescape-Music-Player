#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    // Circle Shape
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    // Sprite
    sf::Texture texture;
    if (!texture.loadFromFile("../image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Load in some Music
    std::string filename = "";
    sf::Music sound;
    srand(time(NULL));
    int x = rand() % 3;

    std::cout << x << std::endl;

    switch (x) {
        case 0:
            filename = "../audio/music0.ogg";
            break;
        case 1:
            filename = "../audio/music1.ogg";
            break;
        case 2:
            filename = "../audio/music2.ogg";
            break;
        case 3:
            filename = "../audio/music3.ogg";
            break;
        default:
            filename = "../audio/music0.ogg";
    }

    if (sound.openFromFile(filename) == sf::Event::Closed) {
        return EXIT_FAILURE;
    }
    sound.play();

    // Window
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }
}
