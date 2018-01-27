//
// Created by liut21 on 1/27/2018.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<string> v;
    v.push_back("Hello");
    v.push_back("World");
    v.push_back("Jason");
    v.push_back("Travor");
    v.push_back("Percy");
    vector<string>::iterator it=v.begin();
    for(;it!=v.end();it++){
        cout << *it << endl;
    }
    return 0;
}
