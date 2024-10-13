#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

    // I've tried using std::for_each, but unfortunatle received an error quote "namespace std has no member for_each"
    // I also understand that basically I could have instead of every "for" loop use std::for_each, but giving that it
    // didn't work I resorted to using "for"
    
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

int cost(vector<std::tuple<std::string, std::string, int, int>>&commodities){
    int capital = 0;
    for(auto &product: commodities){
        capital += get<2>(product) * get<3>(product);
    }
    cout << capital << endl;
    return 0;
}

int find(vector<std::tuple<std::string,std::string,int,int>>&commodities){
    string type;
    cin >> type;
    vector<string>foundProducts;
    for(auto &product: commodities){
        if (get<1>(product) == type){
            foundProducts.push_back(get<0>(product));
        }
    }
    if(foundProducts.empty()){
        cout << "There are no goods of such type";
    }else{
        for(auto &el: foundProducts){
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}

int update(vector<std::tuple<std::string,std::string,int,int>>&commodities){
    string Name;
    int Quantity;
    cin >> Name >> Quantity;
    for(int i = 0; i < commodities.size(); i++){
        if(get<0>(commodities[i]) == Name){
            auto newTuple = std::make_tuple(get<0>(commodities[i]),get<1>(commodities[i]),get<2>(commodities[i]), Quantity);
            commodities[i] = newTuple;
        }
    }
    return 0;
    }

int sale(vector<std::tuple<std::string, std::string, int, int>>&commodities){
    string Type;
    int discount;
    cin >> Type >> discount;
    for(int i = 0; i < commodities.size(); i++){
        if(get<1>(commodities[i]) == Type){
            int newPrice = get<2>(commodities[i]) - ((get<2>(commodities[i]) * discount)/100);
            auto newTuple = std::make_tuple(get<0>(commodities[i]),get<1>(commodities[i]), newPrice, get<3>(commodities[i]));
            commodities[i] = newTuple;
        }
    }
    return 0;
}

int remove(vector<std::tuple<std::string, std::string, int, int>>&commodities){
    string type;
    cin >> type;
    vector<string>foundProducts;
    for(int i = 0; i < commodities.size(); i++){
        if(get<1>(commodities[i]) == type)
            commodities.erase(commodities.begin()+i);
    }
    return 0;
}

int report(vector<std::tuple<std::string, std::string, int, int>>&commodities){
    for(auto &product: commodities){
        cout << "Name: " << std::get<0>(product) << " Type: " << std::get<1>(product) << " Price: " << std::get<2>(product) << " Quantity: " << std::get<3>(product) << endl;
    }

    return 0;
}

int main(){
    vector<std::tuple<std::string, std::string, int, int>>commodities;
    string cmd;
    while(true){
        cin >> cmd;
        if (cmd == "quit"){
            break;
        }else if(cmd == "add"){
            add(commodities);
        }else if(cmd == "report"){
            report(commodities);
        }else if(cmd == "cost"){
            cost(commodities);
        }else if(cmd == "find"){
            find(commodities);
        }else if(cmd == "update"){
            update(commodities);
        }else if(cmd == "sale"){
            sale(commodities);
        }else if(cmd == "remove"){
            remove(commodities);
        }else{
            cout << "please type in proper command";
        }
        
    }
    return 0;
}
