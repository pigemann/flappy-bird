#include "pipeManager.hpp"
extern sf::Sprite pipe1; 
pipeManager::pipeManager() {
    for (int j = 0; j < PIPES; j++) {
        pipes[j].pos.y = -55 - (rand() % 295 + 1);
        pipes[j].pos.x = 900 + j * 400;
    }
}
void pipeManager::update(float deltaTime)
{
    for (int i = 0; i < 3; i++) {
        pipes[i].pos.x -= 250 * deltaTime;
        if (pipes[i].pos.x < -450) {
            pipes[i].pos.x = 900;
        }
    }
}
void pipeManager::render(sf::RenderWindow& window) const
{
    for (int i = 0; i < 3; i++) {
        pipe1.setPosition(pipes[i].pos.x, pipes[i].pos.y);
        std::cout << pipe1.getPosition().x << " thins is the xpos of pipe" << i << std::endl;
        window.draw(pipe1);
    }
}