#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <random>
#include <string>
#include "Button.h"

Button *jumpingButton = nullptr;
double startJumpnigButton = 0;

void jumpDraw(Button &button) {
    if (button.getY() - 300 == 0) {
        button.jumpVector_ = false;
    }
    if (button.getY() == 500) {
        button.jumpVector_ = true;
    }
    int jumpVec = 10;
    if (button.jumpVector_)
        jumpVec *= -1;
    button.setPosition(button.getX(), button.getY() + jumpVec);

}

void onClick(Button& button) {
    if (jumpingButton == &button)
        return;

     if (jumpingButton != nullptr) {
        jumpingButton->onDraw = Button::DEFAULT;
        jumpingButton->setPosition(startJumpnigButton, 500);
     }

     jumpingButton = &button;
     startJumpnigButton = button.getX();
     button.onDraw = jumpDraw;


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> numsDist(0, 99);

    button.setText(std::to_string(numsDist(gen)));
}

int main() {

    sf::RenderWindow window(sf::VideoMode(1000, 700), "frame", sf::Style::Fullscreen);

    std::vector<Button> buttonVec(10, Button(180, 500, 100, 100));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> numsDist(0, 99);

    for (int i = 0; i < buttonVec.size(); ++i) {
        buttonVec[i].setPosition(buttonVec[i].getX() + 110 * i, buttonVec[i].getY());
        buttonVec[i].setText(std::to_string(i));
        buttonVec[i].onDraw = Button::DEFAULT;
        buttonVec[i].onClick = onClick;
    }
    
    sf::Time sleepTime = sf::seconds(0.02f);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

            for (int i = 0; i < buttonVec.size(); ++i)
                buttonVec[i].isPressed(window);
                
        }

        window.clear();
        sf::sleep(sleepTime);
   
        for (int i = 0; i < buttonVec.size(); ++i)
            buttonVec[i].drawButton(window);

        window.display();
    }

}
