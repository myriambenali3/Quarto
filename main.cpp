// include controller
#include "SFMLGame.h"

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>

int main() {

    constexpr int width = 800;
    constexpr int height = 400;

    sf::RenderWindow window(sf::VideoMode(width, height), "Quarto Game",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    Game *model = new Game();
    SFMLGame *controller = new SFMLGame(&window,model);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    controller->onClick(&event);
                    break;

                default:
                    break;
            }
        }

        window.clear();

        controller->displayView();

        window.display();
    }
}
