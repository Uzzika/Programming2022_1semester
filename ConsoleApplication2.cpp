#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
void swap_unit(T &tmp1, T &tmp2) {
    //tmp1 = tmp1 + tmp2 - (tmp2 = tmp1);
    tmp1 ^= tmp2 ^= tmp1 ^= tmp2;
}

template <typename T>
T search_max(T tmp1, T tmp2) {
    bool tmp = tmp1 > tmp2;
    return tmp1 * tmp + tmp2 * (!tmp);
}

enum Status { FAILED, PASSED};

template <typename T>
class Test{
public:
    string name;
    T par1, par2;
    T expected;
    T real;
    Status status;
    time_t timer;
    T(*function_test)(T, T);
public:
    Test():name("default"), status(FAILED), timer(0), function_test(nullptr), par1(NULL), par2(NULL), expected(NULL), real(NULL) {};
    Test(string _name, T _par1, T _par2, T _expected, T(*_function_test)(T, T)) :name("default"), status(FAILED), timer(0), function_test(nullptr) {
        function_test = _function_test;
        name = _name;
        par1 = _par1;
        par2 = _par2;
        expected = _expected;
    };
    Test(Test& tmp) {
        function_test = tmp.function_test;
        name = tmp.name;
        par1 = tmp.par1;
        par2 = tmp.par2;
        expected = tmp.expected;
    }
    ~Test() {};
    ostream& operator<<(ostream& out) {
        out << "--------------------" << endl;
        out << "\tName: " << name << endl;
        out << "\tFirst parametr: " << par1 << endl;
        out << "\tSecond parametr: " << par2 << endl;
        out << "\tExpected: " << expected << endl;
        out << "\tReal: " << real << endl;
        out << "\tTimer: " << timer << " ms" << endl;
        out << "\tStatus: " << status << endl;
        out << "---------------------" << endl;
        return out;
    }
    void run() {
        unsigned int start_time = clock();
        real = function_test(par1, par2);
        unsigned int end_time = clock();
        timer = end_time - start_time;
        if (real == expected) { status = PASSED; }
    }
};

template <typename T>
class Tests {
    string name;
    Test<T>** all;
    size_t size;
    size_t count;
public:
    Tests() : name("default"), size(0), count(0) {
        all = nullptr;
    };
    Tests(Tests&tmp) {
        name = tmp.name;
        size = tmp.size;
        count = tmp.count;
        all = new Test[count];
        for (int i = 0; i < count; i++) {
            all[i] = tmp.all[i];
        }
 
    };
    Tests(string _name) {
        name = _name;
    };
    ~Tests() {
        delete [] all;
    }
    void create_test(string name, T(*_function_test)(T, T), T tmp1, T tmp2, T answer) {

        Test<T>* tmp = new Test<T>(name, tmp1, tmp2, answer, _function_test);
        Test<T>** tmp_mass = new Test<T>*[count+1];
        for (int i = 0; i < count; i++) {
            tmp_mass[i] = all[i];
        }
        tmp_mass[count] = tmp;
        delete all;
        all = tmp_mass;
        count++;
    }
    void run_all() {
        for (int i = 0; i < count; i++) {
            cout << "[   RUN      ]" << all[i]->name << endl;
            all[i]->run();
            if (all[i]->status == PASSED) {
                cout << "[       OK   ]" << all[i]->name << " (" << all[i]->timer << " ms)" << endl;
            }
            else if (all[i]->status == FAILED) {
                cout << "[   FAILED   ]" << endl;
            }
        }
    }

};
int main()
{
    string tmp1 = "First test maximum";
    Test<int> tmp(tmp1, 45, 26, 45, search_max);
    Tests<int> tests("test_name");
    tmp.operator<<(cout); 
    tmp.run();
    tmp.operator<<(cout);

    tests.create_test("ok_then_first_is_bigger", search_max, 15, 8, 15);
    tests.create_test("ok_then_second_is_bigger", search_max, -56, 180, 180);
    tests.create_test("ok_then_are_equal", search_max, 0, 0, 0);
    tests.create_test("ok_with_negative_values", search_max, -234, -4782, 234);
    tests.run_all();
  
};
