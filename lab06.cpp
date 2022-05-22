#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
using std::cout, std::cin, std::endl;
using std::string, std::getline, std::stringstream, std::vector, std::map;
const map<string, string> cases = {
    {"admin", "uWrNuLsu2gqkuhM9"}, {"johndoe", "TStTbuEhAbzlNVix"}, {"mar_cus", "Pass_word123"}, {"Mary21_", "_bekind_"}};

// Ideas
// Request access to customer account, request access to admin account
// Make an online purchase, confirm your account
// User registration
// User login
// User validation
// User update data
// User delete data

string genQuery(const string username, const string password);
void testTautology(const string query);
bool testValid(const string username, const string password);
void testUnion(const string query);
void testAddState(const string query);
void testComment(const string query);
void runTestCases();
bool validateStringStrong(const string text);
bool validateStringWeak(const string text);

void testTautology(const string query)
{
}

// note:    input should only contain letters,
//          numbers, _, and check if there are UNION, OR, UPDATE, SELECT, FROM, WHERE
//          statements
/***************************************
 * Return true if string only contains *
 * numbers, letters, and underscores   *
 ***************************************/
bool validateStringStrong(const string text)
{
    bool valid = true;
    // string has to be more than 5 characters long
    if (text.length() < 5)
        return false;

    for (int i = 0; i < text.length(); i++)
    {
        //  1   48-57   65-90   95   97-122
        if (((int)text[i] == 1)  ||
            ((int)text[i] == 95) ||
            ((int)text[i] >= 48 && (int)text[i] <= 57) ||
            ((int)text[i] >= 65 && (int)text[i] <= 90) ||
            ((int)text[i] >= 97 && (int)text[i] <= 122))
        {
            // cout << (int)text[i] << " ";     //debug
            continue;
        }
        else {
            valid = false;
            break;
        }
    }
    // cout << "\n";   //debug

    return valid;
}

bool validateStringWeak(const string text)
{
    bool valid = true;
    // string has to be more than 5 characters long
    if (text.length() < 5)
        return false;

    for (int i = 0; i < text.length(); i++)
    {
        //  32  39  42  45  59  61
        if ((int)text[i] == 32 || (int)text[i] == 39 || (int)text[i] == 42 ||
            (int)text[i] == 45 || (int)text[i] == 59 || (int)text[i] == 61)
            continue;
        else {
            valid = false;
            break;
        }
    }
    return valid;
}

/******************************
 * Function to validate input *
 ******************************/
bool testValid(const string username, const string password)
{
    if (validateStringWeak(username) && validateStringWeak(password))
    // if (validateStringStrong(username) && validateStringStrong(password))
        return true;
    else
        return false;
}

/******
 * feed test cases...??
 ******/
void runTestCases()
{
    /*
    CASE1: admi - uWrNuLsu2gqkuhM9
    CASE2: johnydoeh - TStTbuEhAbzlNVix
    CASE3: mar_cus - Pass_word123
    CASE4: Mary21_ - _bekind_
    */
    //    genQuery("admi", "uWrNuLsu2gqkuhM9");
    for (auto const &[key, val] : cases)
    {
        cout << genQuery(key, val) << endl;
        // cout << key << " " << val << endl;
    }
}

/***************************************
 * Generate SQL query from a username  *
 * and password string                 *
 ***************************************/
string genQuery(const string username, const string password)
{
    return "SELECT authenticate FROM userCredentials WHERE username='" + username + "' and password='" + password + "';";
}

/********
 * MAIN *
 ********/
int main(int argc, char **argv)
{
    string username, password;
    // no comand line arguments
    if (argc == 1)
    {
        cout << "username: ";
        getline(cin, username);
        cout << "password: ";
        getline(cin, password);
    }
    else if (argc == 3)
    {
        username = argv[1];
        password = argv[2];
    }
    else
    {
        cout << "Only pass two arguments when using the command line. Try again.";
        return 0; // for now, finish program
    }

    /***    QUERY GENERATION    ***/
    if (testValid(username, password))
    {
        cout << genQuery(username, password) << endl;
    }
    else {
        cout << genQuery(username, password) << endl;
        cout << "bad!\n";
        // cout << "Usernames and passwords are five digits long and only containt letters (a-z), number(0-9), and underscores(_)\n";
    }
    
    /******************************/

    // runTestCases();

    // argv[0] is basepath!
    // cout << "argv[0]: " << argv[0] << endl;
    return 0;
}