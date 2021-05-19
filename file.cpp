#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
using namespace std;

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int getAverage(int sum, int count) {
    return sum / count;
}

int mapSum(map<int, int> map) {
    int sum;
    for (const auto& item : map) {
        sum += item.second;
    }
    return sum;
}

map<int, int> weatherFilling(int days) {
    map<int, int> weather;
    for (int i = 0; i < days; i++)
        weather[i + 1] = getRandomNumber(2, 18);
    return weather;
}

void mapInFile(map<int, int> map, int average) {
    ofstream out("weather.txt");
    for(const auto& item : map) {
        if(item.second > average)
            out << item.first << " мая температура превышала среднее значение на "
                << item.second - average << " градусов."
                << endl;
    }
    out.close();
}

int main() {
    map<int, int> weather = weatherFilling(31);
    int sum = mapSum(weather);
    int average = getAverage(sum, weather.size());
    mapInFile(weather, average);
}
