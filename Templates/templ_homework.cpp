#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

bool f1(const vector<int>& v, int elem) {
    return find(v.begin(), v.end(), elem) != v.end();
}

bool f1(const map<int, string>& m, int key) {
    return m.find(key) != m.end();
}

bool f2(const vector<int>& v, int) {
    return v.size() % 2 == 0;
}

bool f2(const map<int, string>& m, int) {
    return m.size() % 2 == 0;
}

class checker {
public:
    int counter = 0;

    template<typename Func, typename Container, typename Element>
    void check(Func func, const vector<Container>& containers, const Element& elem) {
        for (const auto& cont : containers) {
            if (func(cont, elem)) {
                ++counter;
            }
        }
    }

    ~checker() {
        cout << "Counter: " << counter << endl;
    }
};

int main() {
    checker c;

    vector<vector<int>> vec_of_vecs = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9},
        {10}
    };

    vector<map<int, string>> vec_of_maps = {
        {{1, "a"}, {2, "b"}},
        {{3, "c"}},
        {{4, "d"}, {5, "e"}, {6, "f"}},
        {{7, "g"}, {8, "h"}}
    };

    c.check(static_cast<bool(*)(const vector<int>&, int)>(f1), vec_of_vecs, 3);
    c.check(static_cast<bool(*)(const map<int,string>&, int)>(f1), vec_of_maps, 2);
    c.check(static_cast<bool(*)(const vector<int>&, int)>(f2), vec_of_vecs, 0);
    c.check(static_cast<bool(*)(const map<int,string>&, int)>(f2), vec_of_maps, 0);

    return 0;
}