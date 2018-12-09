//
// Created by Last Feremenga on 12/8/18.
//
#include "inversions.hpp"

Invertor::Invertor(std::string path, std::string output_path){
    filepath = path;
    output_filepath = output_path;
    set_unsorted_vector();
}

void Invertor::set_unsorted_vector() {
    std::ifstream file(filepath);

    std::vector<int> numbers;
    std::string str_number;

    if (file.is_open()) {
        while (std::getline(file, str_number)) {
            int number = std::stoi(str_number);
            numbers.push_back(number);
        }
        file.close();
    }
    else{
        std::cout << "Could not open file!" << std::endl;
    }

    unsorted_vector = numbers;
}

void Invertor::set_sorted_vector(std::vector<int> vector) {
    sorted_vector = vector;
}

void Invertor::set_inversions(int inv) {
    inversions = inv;
}

void Invertor::write_sorted_vector() {

    std::ofstream outfile(output_filepath);
    if(outfile.is_open()){

        outfile << "It took " << inversions << " inversions to sort this file!" << std::endl;
        outfile << "-------" << std::endl;
        outfile << "" << std::endl;

        for(int number: sorted_vector){
            outfile << number << std::endl;
        }
        outfile.close();
    }
    else{
        std::cout << "Unable to open file" << std::endl;
    }
}

Invertor::~Invertor() {}