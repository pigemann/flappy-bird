#include "header.hpp"
#include "pipeManager.hpp"
/*                    
make a score system 
implement collision
make a file with the best score
better jump:_bird rotaion
            _velocity(need to see the other way to do it )  
nice to have (optional):_camera sheck
                        _make bird ghost after death 
                        _make a main menu
                        _make a death menu
                        _implement bird rotaion when it s falling or jumping 
                        _make paralex effect
*/                  
bool overlap(int x1, int w1, int x2, int w2) {
    return (x1 <= x2 && x1 >= x2 + w2) || (x1 + w1 <= x2 && x1 + w1 >= x2 + w2) || (x1 < x2 && x2 + 2 < x1 + w1);
}           
bool overlap(FloatRect rect1, FloatRect rect2) {
    return overlap(rect1.left, rect1.width, rect2.left, rect2.width) && overlap(rect1.top, rect1.height, rect2.top, rect2.height);
}           
Sprite pipe1;
int main()
{           
    Clock DeltaTime;
    Clock GameClock;
    float JumpCoolDown = 0; 
    float couldown1 = 0;
    int gravity = 600;
    float velocity = 0 ;
    pipeManager manager;
    srand(time(nullptr));
    font.loadFromFile("ressource/TheFontIAmUsing.ttf");
    txtBird.loadFromFile("ressource/bird.png");
    txtPipe.loadFromFile("ressource/pipe.png");
    RenderWindow window(VideoMode(windowWidth, windowHight), "SFML works!");
    window.setFramerateLimit(60);
    Sprite bird;
    bird.setTexture(txtBird);
    bird.setScale(0.15f, 0.15f);
    bird.setPosition(200, 200);
    pipe1.setTexture(txtPipe);
    pipe1.setScale(0.4f,1);
    pipe1.setPosition(900, -55 - (rand() % 295 + 1));
    Text txt ("why is this so hard " , font , textSize);
    setText(txt);
    bird.setColor(Color(bird.getColor().r, bird.getColor().g,bird.getColor().b,255));
    float DT;
    while (window.isOpen())
    {
        DT = DeltaTime.restart().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    window.close();
                }
            }
        }
        //if (pipe1.getPosition().x <= 0 && pipe1.getPosition().x >= 0 && bird.getPosition().y <= 0 && bird.getPosition().y >= 0) {
            //std::cout << "collision detected " << std::endl; 
        //}
        //std::cout << pipe1.getPosition().x << std::endl;    
        if (Keyboard::isKeyPressed(Keyboard::Space) && GameClock.getElapsedTime().asSeconds() > JumpCoolDown){
            JumpCoolDown = 1+GameClock.getElapsedTime().asSeconds();
            velocity = -420 ;
        }
        if (pipe1.getPosition().x < -450) {
            pipe1.setPosition(900, -55 - (rand() % 295 + 1));
        }
        velocity += gravity  * DT;
        if (velocity > 500) {
            velocity = 500;
        }
        bird.move(0, velocity  * DT);
        window.clear(Color::Blue);
        manager.update(DT);
        manager.render(window);
        window.draw(bird);
        window.display();
    } 
    return 0;
}       
void setText(Text& text) {
    text.setFillColor(Color::Green);
    text.setStyle(Text::Bold);
    text.setPosition(windowWidth / 2 - 218, windowHight / 2 - 50);
}           