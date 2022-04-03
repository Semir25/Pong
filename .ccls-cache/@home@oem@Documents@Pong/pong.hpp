#pragma once
#include<SFML/Graphics.hpp>

extern const int width;
extern const int height;
extern int leftScore;
extern int rightScore;

namespace pong{

    void draw_middle_line(sf::RenderWindow&); 
    void move_paddle(sf::RectangleShape&, bool, bool);
    void keys_pressed(sf::Event&, bool&, bool&, bool&, bool&);
    void move_ball(sf::CircleShape&, const sf::RectangleShape&, const sf::RectangleShape&);

}
