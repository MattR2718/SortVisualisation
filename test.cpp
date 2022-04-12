#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>

#include "bubbleSort.h"
#include "insertionSort.h"

TEST(TrueTest, AlwaysTrue){
    EXPECT_EQ(1, 1);
}

TEST(BubbleSort, Sort){
    std::vector<int> v = { 0, 5, 2, 6, 34, 68, 2, 5, 34, 8, 3, 56, 23, 685, 5 };
    std::vector<int> c = v;
    testBubbleSort(v);
    std::sort(c.begin(), c.begin() + c.size());
    ASSERT_EQ(v.size(), c.size()) << "VECTORS UNEQUAL LENGTHS";
    for (int i = 0; i < v.size(); i++){
        EXPECT_EQ(v[i], c[i]) << "VECTORS DIFFER AT INDEX : " << i;
    }
}

TEST(InsertionSort, Sort){
    std::vector<int> v = { 10, 5, 2, 6, 6, 68, 2, 5, 34, 8, 3, 56, 23, 685, 5 };
    std::vector<int> c = v;
    testInsertionSort(v);
    std::sort(c.begin(), c.begin() + c.size());
    
    std::cout<<"Mine: ";
    for (auto& g : v){ std::cout<<g<<"' "; }
    std::cout<<"\nStd: ";
    for (auto& g : c){ std::cout<<g<<"' "; }
    std::cout<<'\n';
    
    ASSERT_EQ(v.size(), c.size()) << "VECTORS UNEQUAL LENGTHS";
    for (int i = 0; i < v.size(); i++){
        EXPECT_EQ(v[i], c[i]) << "VECTORS DIFFER AT INDEX : " << i;
    }
}
/*
int main(){
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    for (auto& g : v){ std::cout<<g<<"' "; }
    std::cout<<'\n';
    //std::ranges::rotate(start, newStart, end)
    std::ranges::rotate(v.begin() + 1, v.begin() + 3, v.begin() + 4);
    for (auto& g : v){ std::cout<<g<<"' "; }
    std::cout<<'\n';
}
*/