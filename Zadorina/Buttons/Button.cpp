#include "Button.h"

Button::Button(float x, float y, float size, const std::string& label)
    : rect(sf::Vector2f(size, size)), label(label), initialX{ x }, initialY{ y } {
    rect.setPosition(x, y);
    rect.setFillColor(sf::Color::Black);
}

void Button::draw(sf::RenderWindow& window) { 
    onDraw(*this);
    window.draw(rect); 
}

bool Button::isClicked(const sf::Vector2i& mousePos) {
    if (rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        onClick(*this);
        return true;
    }
    return false;
}

void Button::moveUpDown() {
    float y = rect.getPosition().y;

    if (isMovingUp) {
        if (y > initialY - jumpDistance) { rect.move(0, -speed); }
        else { isMovingUp = false; }
    } else {
        if (y < initialY + jumpDistance) { rect.move(0, speed); }
        else { isMovingUp = true; }
    }
}

void Button::setInitialPosition(float x, float y) {
    initialX = x;
    initialY = y;
    rect.setPosition(x, y);
}

void Button::resetPosition() { rect.setPosition(initialX, initialY); }

sf::Vector2f Button::getPosition() { return rect.getPosition(); }
