#include<json.hpp>
#include<iostream>
#include<fstream>
#include<string>

auto restructure(const auto &inputs){
    nlohmann::json outputs;
    for(auto &input:inputs){
        nlohmann::json new_child;
        for(auto &[key, value]:input.items()){
            new_child["key"] = key;
            new_child["value"] = value;
        }
        outputs["children"].push_back(new_child);

    }
    return outputs;
}

auto convert(const auto &inputs){
    nlohmann::json outputs;
    auto input0 = inputs[0];
    outputs["feature"] = input0["feature"];
    outputs["name"] = input0["name"];
    outputs["reference"] = input0["reference"];
    outputs["relation"] = input0["relation"];
    nlohmann::json new_child;
    for(auto &[key, value]:input0["true"].items()){
        new_child[key] = value;

    }
    outputs["children"].push_back(new_child);
    return outputs;
}

int main(){
//    std::ifstream source("model.json");
//    std::ifstream source("tic-tac-dat.json");
    std::ifstream source("m2.json");
   auto inputs = nlohmann::json::parse(source);
   // std::ofstream os("n-ary-model.json");
   // std::ofstream os("ttdo.json");
//   std::ofstream os("/home/leanne/Dev/snippets/JSON/outputs/m22.json");
   std::ofstream os("m22.json");
   auto outputs = convert(inputs);
    std::string inputs_str = inputs.dump(4);
    os << inputs_str << "\n";
   // std::cout << inputs.dump(4) << std::endl;
   // auto outputs = restructure(inputs);
    std::string outputs_str = outputs.dump(4);
   // std::cout << outputs.dump(4) << std::endl;
   os << outputs_str << "\n";
}
