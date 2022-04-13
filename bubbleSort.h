#ifndef BUBBLESORT
#define BUBBLESORT

/*
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <thread>
#include <X11/Xlib.h>
*/

void bubbleSort(std::vector<int>& v, std::chrono::milliseconds time){
    int doneC = 1;
    int swap = false;
    do{
        swap = false;
        for (int i = 0; i < v.size() - doneC; i++){
            if (v[i] > v[i + 1]){
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swap = true;
            }
        }
        doneC++;
        std::this_thread::sleep_for(time);
    }
    while (swap);
}

void bubbleView(std::vector<int>& v, const int& width, const int& height){
    std::chrono::milliseconds time(200);
    std::thread bsThread = std::thread(bubbleSort, std::ref(v), time);
    bsThread.detach();

    int w = width/v.size();
    sf::RectangleShape bar(sf::Vector2f(10, 10));
    bar.setFillColor(sf::Color::Green);
    sf::RenderWindow window(sf::VideoMode(width, height), "Bubble Sort");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
                return;
            }
        }
        window.clear();
        for (int i = 0; i < v.size(); i++){
            bar.setSize(sf::Vector2f(w, v[i]));
            bar.setPosition(sf::Vector2f(w * i, height - v[i]));
            window.draw(bar);
        }
        window.display();
    }
}


void testBubbleSort(std::vector<int>& v){
    int doneC = 1;
    int swap = false;
    do{
        swap = false;
        for (int i = 0; i < v.size() - doneC; i++){
            if (v[i] > v[i + 1]){
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swap = true;
            }
        }
        doneC++;
    }
    while (swap);
}

#endif