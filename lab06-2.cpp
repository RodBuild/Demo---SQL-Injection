#include "testCases.cpp"

// Reassemble a blocklist
string removeInvalidCharacters(const string text) {
    string clean = text;
    for (int i = 0; i < text.length(); i++)
    {
        //  32  39  42  45  59  61
        if ((int)text[i] == 32 || (int)text[i] == 39 || (int)text[i] == 42 ||
            (int)text[i] == 45 || (int)text[i] == 59 || (int)text[i] == 61) {
                clean.erase(clean.begin()+i, clean.end());
                break;
            }
    }
    return clean;
}

// Reassemble an allowlist
string checkForValidCharacters(const string text) {
    string clean;
    //  48-57   65-90   95   97-122
    for (int i = 0; i < text.length(); i++) {
        if (((int)text[i] == 95) ||                         //underscore(-)
            ((int)text[i] >= 48 && (int)text[i] <= 57) ||   //lowercase letters (a-z)
            ((int)text[i] >= 65 && (int)text[i] <= 90) ||   //uperppercase letters (A-Z)
            ((int)text[i] >= 97 && (int)text[i] <= 122))    //numbers (0-9)
        {
            clean += text[i];
        }
        else {
            break;
        }
    }
    return clean;
}

/***************************************
 * Generate SQL query from a username  *
 * and password string                 *
 ***************************************/
string genQuery(const string username, const string password)
{
    return "SELECT authenticate FROM usercredentials WHERE username='" + username + "' AND password='" + password + "';";
}

/***************************************
 * Display the a SQL query for all     *
 * available test cases                *
 ***************************************/
void displayTestCases(vector<User> testCases) {
    for (auto x : testCases)
    {
        // cout << x.username << " " << x.password << endl;     //debug
        cout << "   " << genQuery(x.username, x.password) << endl;
    }
}

/***************************************
 * Strong Mitigation:                  *
 * Limit to only valid characters, to  *
 * simulate and allow list. Consider   *
 * UNION, OR, UPDATE, SELECT, FROM,    *
 * WHERE                               *
 * GOOD:                               *
 *      ^[a-zA-Z0-9_]*$                *
 ***************************************/
void strongMitigation(const vector<User> testCases)
{
    for (auto x: testCases) {
        x.username = checkForValidCharacters(x.username);
        x.password = checkForValidCharacters(x.password);
        cout << "   " << genQuery(x.username, x.password) << endl;
    }
}

/***************************************
 * Weak Mitigation:                    *
 * Blocklist...
 * GOOD:                               *
 *      [^;\-\'\s]*$                   *
 ***************************************/
void weakMitigation(const vector<User> testCases)
{
    // Note range based loops:
    //      auto  -> does not modify data
    //      auto& -> modifies data 
    for (auto x: testCases) {
        x.username = removeInvalidCharacters(x.username);
        x.password = removeInvalidCharacters(x.password);
        cout << "   " << genQuery(x.username, x.password) << endl;
    }
}

/***************************************
 * Show instructions to the user       *
 ***************************************/
void displayOptions()
{
    cout << "\nMake a selection\n";
    cout << "(1) Input Validation\n";
    cout << "(2) Test Tautology\n";
    cout << "(3) Test Union\n";
    cout << "(4) Test Add State\n";
    cout << "(5) Test Comment\n";
    cout << "(6) Quit Application\n";
    cout << "> ";
}

/***************************************
 * Main function, command line takes   *
 * three arguments:                    *
 *      username, password, type       *
 ***************************************/
int main(int argc, char **argv)
{
    // no comannd line
    if (argc == 1)
    {

        vector<User> testCases;
        string option;
        bool running = true;

        while (running)
        {
            testCases.clear(); // empty vector
            displayOptions();
            getline(cin, option);

            if (option == "1")
            {
                // add test cases into vector called testCases
                testValid(testCases);
                cout << "\nExample of valid test cases:\n";
                displayTestCases(testCases);

            }
            else if (option == "2")
            {
                testTautology(testCases);
                cout << "Test Cases:\n";
                displayTestCases(testCases);
                cout << "Weak Mitigation:\n";
                weakMitigation(testCases);
                cout << "Strong Mitigation:\n";
                strongMitigation(testCases);
            }
            else if (option == "3")
            {
                testUnion(testCases);
                displayTestCases(testCases);
                cout << "Weak Mitigation:\n";
                weakMitigation(testCases);
                cout << "Strong Mitigation:\n";
                strongMitigation(testCases);
            }
            else if (option == "4")
            {
                testAddState(testCases);
                cout << "Test Cases:\n";
                displayTestCases(testCases);
                cout << "Weak Mitigation:\n";
                weakMitigation(testCases);
                cout << "Strong Mitigation:\n";
                strongMitigation(testCases);
            }
            else if (option == "5")
            {
                testComment(testCases);
                cout << "Test Cases:\n";
                displayTestCases(testCases);
                cout << "Weak Mitigation:\n";
                weakMitigation(testCases);
                cout << "Strong Mitigation:\n";
                strongMitigation(testCases);
            }
            else if (option == "6")
            {
                running = false;
                break;
            }
            else
            {
                cout << "ERROR: Unknown option\n";
            }
        }
        cout << "\nHave a great day!\n";
    }
    // run from the command line
    else if (argc == 2)
    {
        string type;
        vector<User> testCases;
        type = argv[1];
        if (type == "tautology") {
            testTautology(testCases);
            cout << "Test Cases:\n";
            displayTestCases(testCases);
            cout << "Weak Mitigation:\n";
            weakMitigation(testCases);
            cout << "Strong Mitigation:\n";
            strongMitigation(testCases);
        }
        else if (type == "union") {
            testUnion(testCases);
            cout << "Test Cases:\n";
            displayTestCases(testCases);
            cout << "Weak Mitigation:\n";
            weakMitigation(testCases);
            cout << "Strong Mitigation:\n";
            strongMitigation(testCases);
        }
        else if (type == "state") {
            testAddState(testCases);
            cout << "Test Cases:\n";
            displayTestCases(testCases);
            cout << "Weak Mitigation:\n";
            weakMitigation(testCases);
            cout << "Strong Mitigation:\n";
            strongMitigation(testCases);
        }
        else if (type == "comment") {
            testComment(testCases);
            cout << "Test Cases:\n";
            displayTestCases(testCases);
            cout << "Weak Mitigation:\n";
            weakMitigation(testCases);
            cout << "Strong Mitigation:\n";
            strongMitigation(testCases);
        }
        else {
            cout << "Invalid type argument. Try again :)\n";
        }
    }
    else {
        cout << "Only pass one argument when using the command line.\nRefer to the following:\n         Type [tautology, union, state, comment]. ";
    }
    return 0;
}