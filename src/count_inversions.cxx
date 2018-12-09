//
// Created by Last Feremenga on 12/8/18.
//
#include "count_inversions.h"

int main(int argc, char** argv){

    std::string filepath = argv[1];
    std::string outputpath = argv[2];

    Invertor *invertor = new Invertor(filepath, outputpath); //numbers may be too many, so put it on heap

    std::tuple<std::vector<int>, int> sorted_tuple = mysort(invertor->unsorted_vector);
    invertor->set_sorted_vector(std::get<0>(sorted_tuple));
    invertor->set_inversions(std::get<1>(sorted_tuple));
    invertor->write_sorted_vector();
}

std::tuple<std::vector<int>, int> mysort(std::vector<int> numbers){

    if (numbers.size() == 1){
        return std::make_tuple(numbers, 0);
    }
    else{
        std::tuple<std::vector<int>, std::vector<int> > half_splits = split_vector(numbers);
        std::vector<int> fhalf = std::get<0>(half_splits), shalf = std::get<1>(half_splits);

        std::tuple<std::vector<int>, int> fhalf_sort = mysort(fhalf), shalf_sort = mysort(shalf);
        return count_merge(fhalf_sort, shalf_sort);
    }
}

std::tuple<std::vector<int>, std::vector<int> > split_vector(std::vector<int> my_vec){

    std::size_t const half_size = my_vec.size() / 2;
    std::vector<int> fhalf(my_vec.begin(), my_vec.begin() + half_size);
    std::vector<int> shalf(my_vec.begin() + half_size, my_vec.end());

    return std::make_tuple(fhalf, shalf);

}

std::tuple<std::vector<int>, int> count_merge(std::tuple<std::vector<int>, int> fhalf_tup, std::tuple<std::vector<int>, int> shalf_tup) {

    std::vector<int> fhalf = std::get<0>(fhalf_tup), shalf = std::get<0>(shalf_tup);
    int inv = std::get<1>(fhalf_tup) + std::get<1>(shalf_tup), merge_inv = 0;

    int f = 0, s = 0;
    int F = fhalf.size(), S = shalf.size();
    std::vector<int> merged_vec;

    while ((f < F) && (s < S)) {
        int f_elem = fhalf[f], s_elem = shalf[s];
        if (f_elem < s_elem) {
            merged_vec.push_back(f_elem);
            f++;
        } else {
            merged_vec.push_back(s_elem);
            s++;
            merge_inv++;
        }
    }

    while (f < F) {
        merged_vec.push_back(fhalf[f]);
        f++;
    }

    while (s < S) {
        merged_vec.push_back(shalf[s]);
        s++;
    }

    return std::make_tuple(merged_vec, inv + merge_inv);
}