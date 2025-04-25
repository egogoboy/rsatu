#include <SFML/Graphics.hpp>
#include "Button.h"

#include <iostream>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow {
public:
    MainWindow();

    void run();

    static void onClick(Button& button);

private:
    sf::RenderWindow window;
    std::vector<Button> buttons;
    static inline int jumpingButtonIndex;
    
    void handleButtonClick(int buttonIndex);
};

#endif // MAINWINDOW_H
