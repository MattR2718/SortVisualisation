#include <gtest/gtest.h>
#include <algorithm>

#include "bubbleSort.h"

TEST(TrueTest, AlwaysTrue){
    EXPECT_EQ(1, 1);
}

TEST(BubbleSort, Sort){
    std::vector<int> v = { 0, 5, 2, 6, 34, 68, 2, 5, 34, 8, 3, 56, 23, 685, 5 };
    std::vector<int> c = v;
    bubbleSort(v);
    std::sort(c.begin(), c.begin() + c.size());
    ASSERT_EQ(v.size(), c.size()) << "VECTORS UNEQUAL LENGTHS";
    for (int i = 0; i < v.size(); i++){
        EXPECT_EQ(v[i], c[i]) << "VECTORS DIFFER AT INDEX : " << i;
    }
}