#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct goods{
    string Name;
    string Type;
    int Price;
    int Quantity;
};

int add(vector<std::tuple<std::string, std::string, int, int>>&commodities){
    string Name;
    string Type;
    int Price;
    int Quantity;
    cin >> Name >> Type >> Price >> Quantity;
    commodities.push_back({Name, Type, Price, Quantity});
    return 0;
}

int report(vector<std::tuple<std::string, std::string, int, int>>&commodities){
    for(auto &product: commodities){
        cout << "Name: " << std::get<0>(product) << " Type: " << std::get<1>(product) << " Price: " << std::get<2>(product) << " Quantity: " << std::get<3>(product) << endl;
    }
    // I've tried using std::for_each, but unfortunatle received an error quote "namespace std has no member for_each"
    // std::for_each(commodities.begin(),commodities.end(),[](std::tuple<std::string, std::string, int, int>&product){
    //     cout << " Name: " << std::get<0>(product) << " Type: " << std::get<1>(product) << " Price: " << std::get<2>(product) << " Quantity: " << std::get<3>(product);
    // });
    return 0;
}

int main(){
    vector<std::tuple<std::string, std::string, int, int>>commodities;
    string cmd;
    while(true){
        cin >> cmd;
        if (cmd == "break"){
            break;
        }else if(cmd == "add"){
            add(commodities);
        }else if(cmd == "report"){
            report(commodities);
        }
        
    }
    return 0;
}