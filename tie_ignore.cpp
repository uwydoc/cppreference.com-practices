// tie_ignore.cpp
// 
// Defined in header <tuple>
//

#include <iostream>
#include <set>
#include <string>
#include <tuple>

using namespace std;

int main()
{
    set<string> ss;
    bool inserted = false;
    tie(ignore, inserted) = ss.insert("test");
    if (inserted) {
        cout << "Value was inserted successfully" << endl;
    } else {
        cout << "Value not inserted" << endl;
    }
}
