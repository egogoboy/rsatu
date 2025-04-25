#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>

class Button
{
    public:
        Button() : isJumping_{false} {
            x_ = 0.0;
            y_ = 0.0;
            xSize_ = 0.0;
            ySize_ = 0.0;
            buttonGlow_.setFillColor(sf::Color(0, 0, 0, 0));
            font_.loadFromFile("Monocraft.ttf");
        }

        Button(float x, float y, float xSize, float ySize) : isJumping_{false} {
            x_ = x;
            y_ = y;
            xSize_ = xSize;
            ySize_ = ySize;
            isPress_ = false;
            body_.setPosition(sf::Vector2f(x, y));
            body_.setSize(sf::Vector2f(xSize, ySize));
            buttonGlow_.setPosition(sf::Vector2f(x, y));
            buttonGlow_.setSize(sf::Vector2f(xSize, ySize));
            buttonGlow_.setFillColor(sf::Color(0, 0, 0, 0));
            font_.loadFromFile("Monocraft.ttf");
        }

        void startJumping();
        void stopJumping();

        void setColor(sf::Color color);
        void setBorderColor(sf::Color color);
        void setBorderSize(float borderSize);
        void setTexture(sf::Texture texture);
        void setFillTexture(sf::Texture texture);
        void setPosition(float x, float y);
        void setSize(float x, float y);
        void setAllOptions(float xPos, float yPos, float xSize, float ySize);
        void setText(const std::string& s);


        static void DEFAULT(Button&) {}

        std::function<void(Button&)> onDraw = DEFAULT;
        std::function<void(Button&)> onClick = DEFAULT;

        float getX() {
            return x_;
        }

        float getY() {
            return y_;
        }

        bool isPressed(sf::RenderWindow& app);
        bool isMouseInButton(sf::Vector2i mousePosition);

        void drawButton(sf::RenderWindow& app);

        sf::RectangleShape getButton();


        bool jumpVector_;
    protected:

    private:
        void processJumping();

        float x_,
              y_,
              xSize_,
              ySize_,
              jumpX_,
              jumpY_;

        const int jumpYConst_ = 10;
        const int upJumpBorder_ = -300;
        const int lowJumpBorder_ = 0;

        int countOfJumps_,
            jumpCoolDown_;

        sf::Vector2i mousePressPosition_;
        bool isPress_;
        bool isJumping_;

        sf::RectangleShape body_,
                           buttonGlow_;

        sf::Text buttonText_;

        sf::Font font_;

};
