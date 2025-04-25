#include "MainWindow.h"

Button* jumpingButton = nullptr;

void moveUpDown(Button& button) {
    float y = button.rect.getPosition().y;

    if (button.isMovingUp) {
        if (y > button.initialY - button.jumpDistance) { button.rect.move(0, -button.speed); }
        else { button.isMovingUp = false; }
    }
    else {
        if (y < button.initialY + button.jumpDistance) { button.rect.move(0, button.speed); }
        else { button.isMovingUp = true; }
    }
}

void MainWindow::onClick(Button& button) {
    if (jumpingButton == &button) return;

    if (jumpingButton != nullptr) {
        jumpingButton->onDraw = Button::IDLE;
        jumpingButton->resetPosition();
    }
    jumpingButton = &button;
    button.onDraw = moveUpDown;
}

MainWindow::MainWindow() {
    window.create(sf::VideoMode(800, 200), "Buttons");

    const float buttonSize = 50;
    const float buttonSpacing = 10;

    for (int i = 0; i < 10; ++i) {
        buttons.push_back({ 100 + (buttonSize + buttonSpacing) * i, 75, buttonSize, std::to_string(i + 1) });
        buttons[i].onClick = onClick;
    }

    srand(static_cast<unsigned int>(time(0)));
}

void MainWindow::run() {
    while (window.isOpen()) {
        window.setFramerateLimit(60);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { window.close(); }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                for (int i = 0; i < 10; ++i) {
                    buttons[i].isClicked(mousePos);
                }
            }
        }

        window.clear(sf::Color::White);
        for (int i = 0; i < 10; ++i) {
            buttons[i].draw(window);
        }

        window.display();
    }
}
