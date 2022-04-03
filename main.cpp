#include<SFML/Graphics.hpp>
#include "pong.hpp"

const int width = 800;
const int height = 600;
int leftScore;
int rightScore;
bool start;


int main () {
    srand(time(0));

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    //window
    sf::RenderWindow window(sf::VideoMode(width, height), "Pong", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    //paddles
    sf::RectangleShape leftPaddle(sf::Vector2f(20, 120));
    leftPaddle.setPosition(sf::Vector2f(50, height/2 - 60));
    
    sf::RectangleShape rightPaddle(sf::Vector2f(20, 120));
    rightPaddle.setPosition(sf::Vector2f(width -70, height/2 - 60));

    bool moveLP_up = 0, moveLP_down = 0, moveRP_up = 0, moveRP_down = 0;

    //ball
    sf::CircleShape ball(7.5);
    ball.setPosition(sf::Vector2f(width/2 - 7.5, height/2 - 7.5));

    //score
    sf::Font font;
    font.loadFromFile("res/OpenSans-Regular.ttf");

    sf::Text scoreLeft, scoreRight;

    scoreLeft.setFont(font);
    scoreLeft.setCharacterSize(50);
    scoreLeft.setPosition(sf::Vector2f(width*0.25, 20));

    scoreRight.setFont(font);
    scoreRight.setCharacterSize(50);
    scoreRight.setPosition(sf::Vector2f(width*0.75 - 25, 20));

    //text for winning and starting games
    sf::Text text;

    text.setFont(font);
    text.setCharacterSize(55);
    text.setPosition(sf::Vector2f(10, 100)); 
    
    while(window.isOpen()) { 

        sf::Event event; 
        while(window.pollEvent(event)) { 
            if(event.type == sf::Event::Closed)
                window.close();

            pong::keys_pressed(event, moveLP_up, moveLP_down, moveRP_up, moveRP_down);
        }

        window.clear();

        if(start){
            
            //properly center text
            if(leftScore == 7){
                text.setString("\t\t\tLeft Player wins!\n\tPress space to Play again");
                window.draw(text);
            }
            else if(rightScore == 7){
                text.setString("\t\t\tRight Player wins!\n\tPress space to Play again");
                window.draw(text);
            }
            else {
                pong::move_paddle(leftPaddle, moveLP_up, moveLP_down);
                pong::move_paddle(rightPaddle, moveRP_up, moveRP_down);

                window.draw(leftPaddle);
                window.draw(rightPaddle);
                pong::draw_middle_line(window);
                pong::move_ball(ball, leftPaddle, rightPaddle);
                window.draw(ball);

                scoreRight.setString(std::to_string(rightScore));
                scoreLeft.setString(std::to_string(leftScore));
                window.draw(scoreRight);
                window.draw(scoreLeft);
            }
        }
        else {
            text.setString("Press Space to start the game");
            window.draw(text);
        }

        window.display();
    }

    return 0;
}

