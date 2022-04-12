#ifndef INSERTIONSORT
#define INSERTIONSORT

#include <algorithm>
#include <vector>
#include <chrono>
#include <SFML/Graphics.hpp>

void insertionSort(std::vector<int>& v, std::chrono::milliseconds time){
    int sortedIndex = 0;
    while (sortedIndex < v.size() - 1){
        if (v[sortedIndex] < v[sortedIndex + 1]) { sortedIndex++; }
        else{
            int i = sortedIndex;
            bool found = false;
            while ((!found)){
                i--;
                if ((i == -1) || (v[i] < v[sortedIndex + 1])){ found = true;}
            }
            std::ranges::rotate(v.begin() + i + 1, v.begin() + sortedIndex + 1, v.begin() + sortedIndex + 2);
            sortedIndex++;
        }
        std::this_thread::sleep_for(time);
    }
}

void insertionView(std::vector<int>& v, const int& width, const int& height){
    std::chrono::milliseconds time(150);
    std::thread isThread = std::thread(insertionSort, std::ref(v), time);
    isThread.detach();

    int w = width/v.size();
    sf::RectangleShape bar(sf::Vector2f(10, 10));
    bar.setFillColor(sf::Color::Blue);
    sf::RenderWindow window(sf::VideoMode(width, height), "Insertion Sort");
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


void testInsertionSort(std::vector<int>& v){
    int sortedIndex = 0;
    while (sortedIndex < v.size() - 1){
        if (v[sortedIndex] < v[sortedIndex + 1]) { sortedIndex++; }
        else{
            int i = sortedIndex;
            bool found = false;
            while ((!found)){
                i--;
                if ((i == -1) || (v[i] < v[sortedIndex + 1])){ found = true;}
            }
            std::ranges::rotate(v.begin() + i + 1, v.begin() + sortedIndex + 1, v.begin() + sortedIndex + 2);
            sortedIndex++;
        }
    }
}

#endif