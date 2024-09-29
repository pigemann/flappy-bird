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
          
Sprite pipe1;
int score = 0;
int main()
{           
    int bestScore = 0;
    srand(time(nullptr));
    float radius = 0;
    float raduisSpeed = 1500;
    CircleShape dead(radius);
    dead.setFillColor(Color::Black);
    dead.setPosition(windowWidth / 2 - 50, windowHight / 2 - 50);
    Clock DeltaTime;
    Clock GameClock;
    float JumpCoolDown = 0; 
    float couldown1 = 0;
    int gravity = 600;
    float velocity = 0 ;
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
    //Text txt2( (String) score , font, textSize);
    Text txt ("YOU LOST " , font , textSize);
    setText(txt);
    txt.setPosition(300,-150);
    Text txt1("YOUR SCORE IS : ", font, textSize);
    setText(txt1);
    txt1.setPosition(-500, 250);
    Text txt2("YOUR BEST SCORE IS : ", font, textSize);
    setText(txt2);
    txt2.setPosition(-700, 400);
    bird.setColor(Color(bird.getColor().r, bird.getColor().g,bird.getColor().b,255));
    float DT;
    float dt;
    bool play = true;
    pipeManager manager;
    while (window.isOpen())
    {
        dt = DeltaTime.restart().asSeconds();
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
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::R) {
                    play = true;
                    txt1.setPosition(-500, 250);
                    txt.setPosition(300, -150);
                    txt2.setPosition(-700, 400);
                    radius = 0;
                    bird.setPosition(200, 200);
                    manager.~pipeManager();
                }
            }
        }
        while (play) {
            DT = DeltaTime.restart().asSeconds();
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed) {
                    window.close();
                }
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Escape) {
                        //...
                    }
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Space) && GameClock.getElapsedTime().asSeconds() > JumpCoolDown) {
                JumpCoolDown = 1 + GameClock.getElapsedTime().asSeconds();
                velocity = -420;
            }
            velocity += gravity * DT;
            if (velocity > 500) {
                velocity = 500;
            }
            if (bird.getPosition().y <= -70) {
                bird.setPosition(200, 670);
            }
            if (bird.getPosition().y >= 680) {
                bird.setPosition(200, -40);
            }
            bird.move(0, velocity * DT);
            if (manager.checkCollision(bird.getPosition()))
            {
                play = false;
                bestScore = score;
                score = 0; 
                //std::cout << "collision detected" << std::endl;
            }


            window.clear(Color::Blue);
            manager.update(DT);
            manager.render(window);
            window.draw(bird);
            window.display();
            std::cout << score << std::endl;
        }
        bird.move(0, velocity*dt);
        velocity += gravity * dt;
        if (bird.getPosition().y >= 700 && radius < 2100)
        {
            dead.setRadius(radius);
            radius += raduisSpeed * dt;
            dead.setOrigin(radius / 2, radius / 2);
            
        }
        if (radius >= 2100 && txt.getPosition().y<=100)
        {
            txt.move(0, 400*dt);
        }
        if (txt.getPosition().y >= 100 && txt1.getPosition().x <= 50)
        {
            txt1.move(400*dt, 0);
        }
        if ( txt1.getPosition().x >= 50 && txt2.getPosition().x <= 50)
        {
            txt2 .move(400 * dt, 0);
        }
        window.clear(Color::Blue);
        manager.render(window);
        window.draw(bird);
        window.draw(dead);
        window.draw(txt);
        window.draw(txt1);
        window.draw(txt2);
        window.display();
    }
    return 0;
}      
void setText(Text& text) {
    text.setFillColor(Color::Green);
    text.setStyle(Text::Bold);
    text.setPosition(windowWidth / 2 - 218, windowHight / 2 - 50);
}           
        
        