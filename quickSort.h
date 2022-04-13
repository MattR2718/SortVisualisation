#ifndef QUICKSORT
#define QUICKSORT

int partition(std::vector<int>& v, int l, int r, int p){
    int lp = l - 1;
    int rp = r;
    bool done = false;
    while (!done){
        while (v[++lp] < p){}
        while ((rp > 0) && (v[--rp] > p)){}
        if (lp >= rp){done = true;}
        else{
            int temp = v[lp];
            v[lp] = v[rp];
            v[rp] = temp;
        }
    }
    int temp = v[lp];
    v[lp] = v[r];
    v[r] = temp;
    return lp;
}

int partitionTime(std::vector<int>& v, int l, int r, int p, std::chrono::milliseconds time){
    int lp = l - 1;
    int rp = r;
    bool done = false;
    while (!done){
        while (v[++lp] < p){}
        while ((rp > 0) && (v[--rp] > p)){}
        if (lp >= rp){done = true;}
        else{
            int temp = v[lp];
            v[lp] = v[rp];
            v[rp] = temp;
        }
        std::this_thread::sleep_for(time);
    }
    int temp = v[lp];
    v[lp] = v[r];
    v[r] = temp;
    return lp;
}

void quickSort(std::vector<int>& v, int l, int r, std::chrono::milliseconds time){
    if ((r - l) <= 0){ return; }
    else {
        int pivot = v[r];
        int nv = partitionTime(v, l, r, pivot, time);
        quickSort(v, l, nv - 1, time);
        //std::this_thread::sleep_for(time);
        quickSort(v, nv + 1, r, time);
        //std::this_thread::sleep_for(time);
    }
}

void quickView(std::vector<int>& v, const int& width, const int& height){
    std::chrono::milliseconds time(50);
    std::thread qsThread = std::thread(quickSort, std::ref(v), 0, v.size() - 1, time);
    qsThread.detach();

    int w = width/v.size();
    sf::RectangleShape bar(sf::Vector2f(10, 10));
    bar.setFillColor(sf::Color::Red);
    sf::RenderWindow window(sf::VideoMode(width, height), "Quick Sort");
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

void testQuickSort(std::vector<int>& v, int l, int r){
    if ((r - l) <= 0){ return; }
    else {
        int pivot = v[r];
        int nv = partition(v, l, r, pivot);
        testQuickSort(v, l, nv - 1);
        testQuickSort(v, nv + 1, r);
    }
}

#endif