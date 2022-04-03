#include "pong.hpp"
extern bool start;


namespace pong{

    //middle line
    void draw_middle_line (sf::RenderWindow& window) {
        for(int i = 0; i < height/30; ++i) {
            sf::RectangleShape dot(sf::Vector2f(20, 20)); 
            dot.setPosition(sf::Vector2f(width/2 - 10, i*30));
            dot.setFillColor(sf::Color(200, 200, 200));
            window.draw(dot);
        }
    }

    void move_paddle(sf::RectangleShape& paddle, bool up, bool down){
        if(up && paddle.getPosition().y > 0) paddle.move(sf::Vector2f(0, -3));
        if(down && paddle.getPosition().y < height - 120) paddle.move(sf::Vector2f(0, 3));
    }

    void keys_pressed(sf::Event& event, bool& moveLP_up, bool& moveLP_down, bool& moveRP_up, bool& moveRP_down){
        //pressing keys
        
        if(event.type == sf::Event::KeyPressed) {

                if(event.key.code == sf::Keyboard::W){
                    moveLP_up = true;
                }

                if(event.key.code == sf::Keyboard::S){
                    moveLP_down = true;
                }
                
                if(event.key.code == sf::Keyboard::Up){
                    moveRP_up = true;
                }

                if(event.key.code == sf::Keyboard::Down){
                    moveRP_down = true;
                }

                if(event.key.code == sf::Keyboard::Space && (leftScore == 7 || rightScore == 7)){
                    leftScore = 0;
                    rightScore = 0;
                }

                if(event.key.code == sf::Keyboard::Space && (start == false)){
                    start = true;
                }
        }
            
        //releasing keys
        if(event.type == sf::Event::KeyReleased) {
                if(event.key.code == sf::Keyboard::W){
                    moveLP_up = false;
                }

                if(event.key.code == sf::Keyboard::S){
                    moveLP_down = false;
                }

                if(event.key.code == sf::Keyboard::Up){
                    moveRP_up = false;
                }

                if(event.key.code == sf::Keyboard::Down){
                    moveRP_down = false;
                }
        }
        

    }

    void move_ball(sf::CircleShape& ball, const sf::RectangleShape& r1, const sf::RectangleShape& r2){
        
        static short x = rand()%2 ? (-2):2, y = rand()%2 ? (-2):2; 
        sf::FloatRect paddle1 = r1.getGlobalBounds();
        sf::FloatRect paddle2 = r2.getGlobalBounds();
        sf::FloatRect b = ball.getGlobalBounds();

        if(ball.getPosition().y >= height - 15 || ball.getPosition().y <= 0) y *= (-1);

        if((paddle1.intersects(b) || paddle2.intersects(b)) && 
                ball.getPosition().x > 68 && ball.getPosition().x < width - 83) 
            x *= (-1);

        if(ball.getPosition().x > width) {
            leftScore++;
            ball.setPosition(sf::Vector2f(width/2 - 7.5, height/2 - 7.5));
            x = -2;
            y = rand()%2 ? (-2):2;
        }
        else if(ball.getPosition().x < -15) {
            rightScore++;
            ball.setPosition(sf::Vector2f(width/2 - 7.5, height/2 - 7.5));
            x = 2;
            y = rand()%2 ? (-2):2;
        }

        ball.move(x, y);

    }
    
}
