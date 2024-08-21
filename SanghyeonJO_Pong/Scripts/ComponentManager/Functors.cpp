#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

// Helper functions
int randomRange(int min, int max) {
    return std::rand() % (max - min) + min;
}

void PrintVec(const std::vector<int>& v) {
    for (int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

void PrintVec(const std::vector<std::pair<int, std::string>>& v) {
    for (const std::pair<int, std::string>& i : v)
        std::cout << "[" << i.first << " " << i.second << "] ";
    std::cout << std::endl;
}

// Sorting functions
bool SortFn(int a, int b) {
    return a > b;
}

bool oddFirst(int a, int b) {
    if (a % 2 == b % 2) {
        return a < b;
    }
    else {
        return (a % 2) == 1;
    }
}

// Functor class
class Functor {
    int n;
public:
    Functor(int i) : n(i) {}

    bool operator()(int a, int b) {
        return SortFn(a, b);
    }

    int operator()() { return n; }
};

// Sorts 2 pairs
bool SortPair(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return a.first < b.first;
}

// Check a pair and an int. This is NOT a find function as the parameters are not equal
bool IsPairIntEqual(const std::pair<int, std::string>& a, int b) {
    return a.first == b;
}

// Functor to find a pair with an int value
class FunctorFind {
    int b;
public:
    FunctorFind(int B) : b(B) {}

    bool operator()(const std::pair<int, std::string>& a) {
        return IsPairIntEqual(a, b);
    }
};

void test1() {
    std::vector<int> numbers;
    Functor f(6);

    for (int i = 0; i < 10; i++) {
        numbers.push_back(randomRange(0, 10));
    }

    PrintVec(numbers);
    std::sort(numbers.begin(), numbers.end(), SortFn);
    PrintVec(numbers);
    std::sort(numbers.begin(), numbers.end(), oddFirst);
    PrintVec(numbers);
    std::sort(numbers.begin(), numbers.end(), f);
    PrintVec(numbers);
    std::sort(numbers.begin(), numbers.end(), Functor(3));
    PrintVec(numbers);
}

void test2() {
    std::vector<std::pair<int, std::string>> pairVec;

    for (int i = 0; i < 10; i++)
        pairVec.push_back(std::pair<int, std::string>(randomRange(0, 10), std::string(1, 'a' + i)));

    PrintVec(pairVec);
    std::sort(pairVec.begin(), pairVec.end(), SortPair);
    PrintVec(pairVec);
    auto res = std::find_if(pairVec.begin(), pairVec.end(), FunctorFind(2));
}
