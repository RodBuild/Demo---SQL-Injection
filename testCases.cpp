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

    // Milan
    User test2;
    test2.username = "Max";
    test2.password = "A8hnu&!123";
    testCases.push_back(test2);

    // Kyle
    User test3;
    test3.username = "admin";
    test3.password = "password123";
    testCases.push_back(test3);

    // Trevor
    User test4;
    test4.username = "john";
    test4.password = "asdf123";
    testCases.push_back(test4);
}
void testTautology(vector<User> &testCases) {
    // Rodrigo
    User test1;
    test1.username = "brayid_1978";
    test1.password = "ilovecats10' ;OR 'x' = 'x";
    testCases.push_back(test1);

    //Milan
    User test2;
    test2.username = "Max";
    test2.password = "x' OR 'x' = 'x";
    testCases.push_back(test2);

    //Kyle
    User test3;
    test3.username = "admin";
    test3.password = "nothing' OR '1'='1";
    testCases.push_back(test3);

    // Trevor
    User test4;
    test4.username = "john";
    test4.password = "x OR 1==1"; 
    testCases.push_back(test4);  

    // Michael
    User test5;
    test5.username = "randomUser";
    test5.password = "loc123 OR 'x'='1'";
    testCases.push_back(test5);
}
void testUnion(vector<User> &testCases) {
    // Rodrigo
    User test1;
    test1.username = "brayid_1978";
    test1.password = "ilovecats10' UNION SELECT name FROM location; -- ";
    testCases.push_back(test1);

    //Kyle
    User test2;
    test2.username = "admin";
    test2.password = "nothing' UNION SELECT authenticate FROM usercredentials;";
    testCases.push_back(test2);
    
    //Milan
    User test3;
    test3.username = "Max";
    test3.password = "x' UNION SELECT * FROM usercreedenntials";
    testCases.push_back(test3);

    // Trevor
    User test4;
    test4.username = "john";
    test4.password = "x' UNION SELECT * FROM users WHERE";
    testCases.push_back(test4);
    
    // Michael
    User test5;
    test5.username = "randomUser";
    test5.username = "loco123' UNION SELECT password FROM usercredentials";
    testCases.push_back(test5);
}
void testAddState(vector<User> &testCases) {
    // Rodrigo
    User test1;
    test1.username = "brayid_1978";
    test1.password = "ilovecats10'; UPDATE userCredentials SET password = 'hacked' WHERE username = 'admin";
    testCases.push_back(test1);
    
    //Kyle
    User test2;
    test2.username = "admin";
    test2.password = "nothing'; DROP TABLE usercredentials";
    testCases.push_back(test2);
    
    //Milan
    User test3;
    test3.username = "Max";
    test3.password = "x'; DELETE FROM usercredentials WHERE username='Admin'";
    testCases.push_back(test3);

    // Trevor
    User test4;
    test4.username = "john";
    test4.password = "x'; DROP TABLES users;";
    testCases.push_back(test4);
    
    //Michael 
    User test5;
    test5.username = "randomUser; UPDATE usercredentials SET password = loco12;";
    test5.password = "loco123";
    testCases.push_back(test5);
}
void testComment(vector<User> &testCases) {
    // Rodrigo
    User test1;
    test1.username = "admin'; -- ";
    test1.password = "ilovecats10";
    testCases.push_back(test1);

    //Kyle
    User test2;
    test2.username = "admin; --";
    test2.password = "nothing";
    testCases.push_back(test2);

    //Milan
    User test3;
    test3.username = "Max'; --";
    test3.password = "x";
    testCases.push_back(test3);

    // Trevor
    User test4;
    test4.username = "john; /*";
    test4.password = "*/";
    testCases.push_back(test4);

    //Michael
    User test5;
    test5.username = "randomUser";
    test5.password = ";-- loco123";
    testCases.push_back(test5);
}

