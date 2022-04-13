#include <iostream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <X11/Xlib.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <chrono>

#include "bubbleSort.h"
#include "insertionSort.h"
#include "quickSort.h"

int main()
{
    XInitThreads();

    const int WIDTH = 900;
    const int HEIGHT = 500;

    std::vector<int> v(90);

    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_int_distribution<int> dist {1, HEIGHT};
    auto gen = [&dist, &mersenne_engine](){ return dist(mersenne_engine); };
    generate(begin(v), end(v), gen);

    /*
    for (int i = 0; i < v.size(); i++){
        std::cout<<v[i]<<'\n';
    }
    */

    std::vector<int> bubbleVec = v;
    std::vector<int> insertVec = v;
    std::vector<int> quickVec = v;

    std::thread bubbleThread = std::thread(bubbleView, std::ref(bubbleVec), std::ref(WIDTH), std::ref(HEIGHT));
    bubbleThread.detach();
    std::thread insertionThread = std::thread(insertionView, std::ref(insertVec), std::ref(WIDTH), std::ref(HEIGHT));
    insertionThread.detach();
    std::thread quickThread = std::thread(quickView, std::ref(quickVec), std::ref(WIDTH), std::ref(HEIGHT));
    quickThread.detach();

    //bubbleThread.detach();
    
    sf::RenderWindow window(sf::VideoMode(100, 100), "MAIN");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.display();
    }
    
}