#include <SFML/Graphics.hpp>
#include <iostream>
class pipe  {
public:
    sf::Vector2f pos;

    bool checkCollision(sf::Vector2f) const;
};
class pipeManager {
private:
    const static int PIPES = 3;
    pipe pipes[PIPES];
public:
    pipeManager();
    void update(float deltaTime);
    void render(sf::RenderWindow& window) const;
    bool checkCollision(sf::Vector2f) const;
};