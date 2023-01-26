#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <vector>

using namespace std;

/*
 *  This project will use ASCII art:
 *                                                                  _
 *  A box represents reserved memory (to hold a variable's value): | |
 *                                                                 |_|
 *                                                                              ?_
 *  A box with a question mark in the upper left corner represents an optional: | |
 *                                                                              |_|
 *                                                      _ _ _ _ _ _
 *  A series of consecutive boxes represents a vector: | | | | | | |
 *                                                     |_|_|_|_|_|_|
 *
 *  An arrow represents a pointer: ---->
 *
 *  An arrow with a bar represents a nullptr: -->|
 */


int main() {
    /* 1. Create the following three optional integers:
     *      ?__
     *      |  |
     *      |__|
     *      ?__
     *      |42|
     *      |__|
     *      ?__?__?__?__?__?__?__?__
     *      |  |90|44|  |79|  |-5|17|
     *      |__|__|__|__|__|__|__|__|
     */
    optional<int> optInt1 = nullopt;
    optional<int> optInt2 = make_optional<int>(42);
    vector<optional<int>> optVec;

    // Adding 8 int optionals to optVec
    optVec.push_back(nullopt);
    optVec.push_back(make_optional<int>(90));
    optVec.push_back(make_optional<int>(44));
    optVec.push_back(nullopt);
    optVec.push_back(make_optional<int>(79));
    optVec.push_back(nullopt);
    optVec.push_back(make_optional<int>(-5));
    optVec.push_back(make_optional<int>(17));

    /* 2. Create the following smart pointers,
     *    where each one points to a different data type:
     *      Stack           Heap
     *       __              __
     *      |  | ---------> |11|
     *      |__|            |__|
     *       __              ___
     *      |  | ---------> |0.3|
     *      |__|            |___|
     *       __              __
     *      |  | ---------> |d |
     *      |__|            |__|
     *       __              __
     *      |  | ---------> |yo|
     *      |__|            |__|
     */
    unique_ptr<int> smartIntPtr = make_unique<int>(11);
    unique_ptr<double> smartDoublePtr = make_unique<double>(0.3);
    unique_ptr<char> smartCharPtr = make_unique<char>('d');
    unique_ptr<string> smartStringPtr = make_unique<string>("yo");

    /* 3. Use ASCII art to draw in the comments what the following code looks like in memory:
     *      Stack           Heap
     *       __              __  __  __  __  __  __  __  __  __
     *      |  | ---------> |11||22||33||44||55||66||77||88||99|
     *      |__|            |__||__||__||__||__||__||__||__||__|
     *
     */
    unique_ptr<vector<int>> heapVec = make_unique<vector<int>>();
    for (int n = 11; n <= 88; n += 11) {
        heapVec->push_back(n);
    }

    /* 4. Use ASCII art to draw in the comments what the following code looks like in memory:
     *      Stack           Heap
     *       __              __              __
     *      |  | ---------> |  | ---------> |m |
     *      |__|            |__|            |__|
     *                                       ^
     * (in class we may have put the pointer arrow down here rather than off to the side, but this is still heap memory)
     */
    unique_ptr<unique_ptr<char>> heapPtrChar = make_unique<unique_ptr<char>>();
    *heapPtrChar = make_unique<char>('m');

    /* 5. Create the following smart pointers to your choice of data type:
     *      Stack      Heap
     *       __         __
     *      |  | ----> |  |
     *      |__|    >  |__|
     *             /
     *       __   /
     *      |  | /
     *      |__|
     */
    shared_ptr<int> sharedIntPtr = make_shared<int>();
    shared_ptr<int> sharedIntPtrCopy = sharedIntPtr;

    /* 6. Use ASCII art to draw in the comments what the following code looks like in memory:
     *      Stack      Heap
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     *
     */
    optional<unique_ptr<int>> opIntPtr1 = nullopt;
    optional<unique_ptr<int>> opIntPtr2 = make_optional<unique_ptr<int>>(nullptr);
    optional<unique_ptr<int>> opIntPtr3 = make_optional<unique_ptr<int>>(make_unique<int>(98));


    /* 7. Create the following smart pointers to optionals:
     *      Stack      Heap
     *       __
     *      |  | --->|
     *      |__|
     *
     *       __        ?__
     *      |  | ----> |  |
     *      |__|       |__|
     *
     *       __        ?__
     *      |  | ----> |hi|
     *      |__|       |__|
     */




    return 0;
}