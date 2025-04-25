#include "Button.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>

void Button::drawButton(sf::RenderWindow& app) {
    onDraw(*this);

    app.draw(body_);
    app.draw(buttonText_);
    app.draw(buttonGlow_);
}

void Button::setColor(sf::Color color) {
    body_.setFillColor(color);
}

void Button::setBorderColor(sf::Color color) {
    body_.setOutlineColor(color);
}

void Button::setBorderSize(float borderSize) {
    body_.setOutlineThickness(borderSize);
}

void Button::setFillTexture(sf::Texture texture) {
    body_.setTexture(&texture);
}

void Button::setText(const std::string& s) {
    buttonText_.setString(s);
    buttonText_.setCharacterSize(25);
    buttonText_.setFillColor(sf::Color::Black);
    buttonText_.setFont(font_);
}

void Button::setPosition(float x, float y) {
    x_ = x;
    y_ = y;
    body_.setPosition(sf::Vector2f(x, y));
    buttonGlow_.setPosition(sf::Vector2f(x, y));
    buttonText_.setPosition(x_ + 20, y_ + 20);
}

void Button::setSize(float x, float y) {
    xSize_ = x;
    ySize_ = y;
    body_.setSize(sf::Vector2f(xSize_, ySize_));
    buttonGlow_.setSize(sf::Vector2f(xSize_, ySize_));
}

void Button::setAllOptions(float xPos, float yPos, float xSize, float ySize) {
    setPosition(xPos, yPos);
    setSize(xSize, ySize);
    setColor(sf::Color::White);
    setBorderSize(7);
    setBorderColor(sf::Color::Black);
}

sf::RectangleShape Button::getButton() {
    return body_;
}

bool Button::isPressed(sf::RenderWindow& app) {

    if (!isPress_ && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        mousePressPosition_ = sf::Mouse::getPosition(app);

        isPress_ = true;
        if (isMouseInButton(sf::Mouse::getPosition(app)) && isMouseInButton(mousePressPosition_))
            buttonGlow_.setFillColor(sf::Color(0, 0, 0, 40));
    }

    if (isPress_ && !(sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
        isPress_ = false;
        buttonGlow_.setFillColor(sf::Color(0, 0, 0, 0));

        if (isMouseInButton(sf::Mouse::getPosition(app)) && isMouseInButton(mousePressPosition_)) {
            onClick(*this);
            return true;
        }

    }

    return false;

}

bool Button::isMouseInButton(sf::Vector2i mousePosition) {

    return ((mousePosition.x >= x_) && (mousePosition.x <= x_+ xSize_
        && mousePosition.y >= y_) && (mousePosition.y <= y_ + ySize_));

}

void Button::startJumping() {
    if (!isJumping_) {
        isJumping_ = true;
        jumpVector_ = true;
        jumpY_ = 0;
        countOfJumps_ = -1;
        jumpCoolDown_ = 0;
    }
}

void Button::stopJumping() {
    isJumping_ = false;
}

void Button::processJumping() {
    if (countOfJumps_ == 3 && jumpY_ == 0)
        stopJumping();

    if (isJumping_) {
        if (jumpCoolDown_ == 0) {
            if (jumpY_ == upJumpBorder_) {
                jumpVector_ = false;
            }
            if (jumpY_ == lowJumpBorder_) {
                jumpVector_ = true;
                countOfJumps_++;
            }
            if (!(countOfJumps_ == 3)) {
                jumpY_ += (!jumpVector_ ? jumpYConst_ : -jumpYConst_);

                y_ += (!jumpVector_ ? jumpYConst_ : -jumpYConst_);
                x_ += jumpX_;

                setPosition(x_, y_);
                //jumpCoolDown_ = 60;
            }
        }
        else {
            jumpCoolDown_--;
        }
    }

}
