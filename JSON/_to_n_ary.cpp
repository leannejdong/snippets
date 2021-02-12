#include<nlohmann/json.hpp>
#include<iostream>

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


auto restructure(const auto &inputs){
    nlohmann::json outputs;
    for(auto &input:inputs){
        nlohmann::json output;
        for(auto &[key,value]:input.items()){
            if(key == "true" || key == "false")
                output["children"][key] = value;
            else
                output["value"][key] = value;
        }
        outputs.push_back(output);
    }
    return outputs;
}

int main(int argc,char **){
    auto inputs = nlohmann::json::parse(source);
    std::cout << inputs.dump(4) << std::endl;
    auto outputs = restructure(inputs);
    std::cout << outputs.dump(4) << std::endl;
}
