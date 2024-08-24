#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;
const int windowHight = 680;
const int windowWidth = 900;
const int textSize = 50;
Font font;
Texture txtBird;
Texture txtPipe;
extern Sprite pipe1;
void setText(Text&);
void setSprite(Sprite& );

