#include<json.hpp>
#include<iostream>
#include<fstream>
#include<string>
#if 0
constexpr auto source = 
"["
"    {"
"        \"false\": {"
"            \"complexity\": 0.009999999776482582,"
"            \"loss\": 0.03938019275665283,"
"            \"name\": \"recidivate-within-two-years:1\","
"            \"prediction\": 1"
"        },"
"        \"feature\": 7,"
"        \"name\": \"juvenile-crimes:=0\","
"        \"reference\": 1,"
"        \"relation\": \"==\","
"        \"true\": {"
"            \"false\": {"
"                \"complexity\": 0.009999999776482582,"
"                \"loss\": 0.21644717454910278,"
"                \"name\": \"recidivate-within-two-years:1\","
"                \"prediction\": 0"
"            },"
"            \"feature\": 11,"
"            \"name\": \"priors:>3\","
"            \"reference\": 1,"
"            \"relation\": \"==\","
"            \"true\": {"
"                \"complexity\": 0.009999999776482582,"
"                \"loss\": 0.08904016017913818,"
"                \"name\": \"recidivate-within-two-years:1\","
"                \"prediction\": 1"
"            }"
"        }"
"    }"
"]";
#endif

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
