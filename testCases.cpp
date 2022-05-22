#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
using std::cout, std::cin, std::endl;
using std::string, std::getline, std::stringstream, std::vector, std::map;

struct User{
    string username;
    string password;
};

void testValid(vector<User> &testCases) {
    // Rodrigo
    User test1;
    test1.username = "brayid_1978";
    test1.password = "ilovecats10";
    testCases.push_back(test1);

    //Person1, etc.
}
void testTautology(vector<User> &testCases) {
    // Rodrigo
    User test1;
    test1.username = "brayid_1978";
    test1.password = "ilovecats10' OR 'x' = 'x";
    testCases.push_back(test1);

    //testing
    User testing;
    testing.username = "john_doe1";
    testing.password = "doe12345";
    testCases.push_back(testing);

    //note you can also do "OR true; -- "
}
void testUnion(vector<User> &testCases) {
    // Rodrigo
    User test1;
    test1.username = "brayid_1978";
    test1.password = "ilovecats10' UNION SELECT name FROM location; -- ";
    testCases.push_back(test1);
}
void testAddState(vector<User> &testCases) {
    // Rodrigo
    User test1;
    test1.username = "brayid_1978";
    test1.password = "ilovecats10'; UPDATE userCredentials SET password = 'hacked' WHERE username = 'admin";
    testCases.push_back(test1);
}
void testComment(vector<User> &testCases) {
    // Rodrigo
    User test1;
    test1.username = "admin'; -- ";
    test1.password = "ilovecats10";
    testCases.push_back(test1);
}

