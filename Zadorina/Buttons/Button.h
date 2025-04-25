#include <SFML/Graphics.hpp>
#include <array>
#include <cstdlib>
#include <ctime>
#include <functional>

#ifndef BUTTON_H
#define BUTTON_H

class Button {
public:
    Button(float x, float y, float size, const std::string& label);

    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2i& mousePos);
    void moveUpDown();
    void setInitialPosition(float x, float y);
    void resetPosition();
    sf::Vector2f getPosition();

    static void IDLE(Button&) {}
    std::function<void(Button& button)> onDraw = IDLE;
    std::function<void(Button& button)> onClick = IDLE;

    sf::RectangleShape rect;
    std::string label;
    float initialX;
    float initialY;
    bool isMovingUp = true;
    static inline float speed = 2;
    static inline float jumpDistance = 10;
    
};

#endif // BUTTON_H
