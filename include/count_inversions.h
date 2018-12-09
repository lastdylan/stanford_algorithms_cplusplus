//
// Created by Last Feremenga on 12/8/18.
//

#ifndef CPP_ALGOS_COUNT_INVERSIONS_H
#define CPP_ALGOS_COUNT_INVERSIONS_H

#include "inversions.hpp"

std::tuple<std::vector<int>, int> sort_countInv(Invertor*);
std::tuple<std::vector<int>, int> mysort(std::vector<int>);
std::tuple<std::vector<int>, std::vector<int> > split_vector(std::vector<int>);
std::tuple<std::vector<int>, int> count_merge(std::tuple<std::vector<int>, int>, std::tuple<std::vector<int>, int> );

#endif //CPP_ALGOS_COUNT_INVERSIONS_H
