//
// Created by Last Feremenga on 12/8/18.
//

#ifndef CPP_INVERSIONS_HPP
#define CPP_INVERSIONS_HPP

#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <iostream>
#include <cstddef>

class Invertor{

private:
    //members
    std::string filepath, output_filepath;
    int inversions;

public:
    Invertor(std::string, std::string);
    ~Invertor();

    std::vector<int> unsorted_vector;
    std::vector<int> sorted_vector;

    //methods
    void set_unsorted_vector();
    void set_sorted_vector(std::vector<int>);
    void set_inversions(int );
    void write_sorted_vector();
};

#endif //CPP_INVERSIONS_HPP
