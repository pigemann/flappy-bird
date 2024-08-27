#include "pipeManager.hpp"
extern sf::Sprite pipe1; 
extern int score;
pipeManager::pipeManager() {
    for (int j = 0; j < PIPES; j++) {
        pipes[j].pos.y = -55 - (rand() % 295 + 1);
        pipes[j].pos.x = 900 + j * 400;
    }
}
void pipeManager::update(float deltaTime)
{
    for (int i = 0; i < PIPES; i++) {
        pipes[i].pos.x -= 250 * deltaTime;
        if (pipes[i].pos.x < -450) {
            pipes[i].pos.x = 900;
        }
        if (pipes[i].pos.x < 200 && pipes[i].pos.x>196.9) {
            score++;
        }
    }
}
void pipeManager::render(sf::RenderWindow& window) const
{
    for (int i = 0; i < PIPES; i++) {
        pipe1.setPosition(pipes[i].pos.x, pipes[i].pos.y);
        window.draw(pipe1);
    }
}

bool pipeManager::checkCollision(sf::Vector2f birdPosition) const
{
    for (int i = 0; i < PIPES; i++)
    {
        if (pipes[i].checkCollision(birdPosition))
        {
            return true;
        }
    }
                   
    return false;
}

bool overlap(int x1, int w1, int x2, int w2) {
     return (x1 >= x2 && x1 <= x2 + w2) || (x1 + w1 >= x2 && x1 + w1 <= x2 + w2) || (x1 < x2 && x2+w2 < x1 + w1);
}           
bool overlap(sf::FloatRect rect1, sf::FloatRect rect2) {
    return overlap(rect1.left, rect1.width, rect2.left, rect2.width) && overlap(rect1.top, rect1.height, rect2.top, rect2.height);
} 


bool pipe::checkCollision(sf::Vector2f birdPosition) const
{
    const float birdWidth = 90; 
    const float birdHeight = 60; 
    const float pipeWidth = 141.6; 
    const float totalPipeSpriteHeight = 980; 
    const float pipeMiddleSectionVerticalOpening = 254; 
    if (!overlap(birdPosition.x, birdWidth, pos.x, pipeWidth))
    {
        return false;
    }
    float heightOfASinglePipe = (totalPipeSpriteHeight-pipeMiddleSectionVerticalOpening) / 2;
        if (overlap(birdPosition.y, birdHeight, pos.y, heightOfASinglePipe))
    {
        return true;
    }
    if (overlap(birdPosition.y, birdHeight, pos.y + heightOfASinglePipe + pipeMiddleSectionVerticalOpening,
    heightOfASinglePipe))
    {
        return true;
    }
    return false;
}