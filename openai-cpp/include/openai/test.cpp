#include "openai.hpp"
#include <iostream>
#include"json/include/nlohmann/json.hpp"

std::string getText(std::string text) {
    nlohmann::json json = {{"model", "text-davinci-003"},
                            {"prompt",text},
                            {"max_tokens", 1500},
                            {"temperature", 0.9},
                            {"top_p", 1.0},
                            {"frequency_penalty", 0.0},
                            {"presence_penalty",0.6}
                            };


    auto completion = openai::completion().create(json);

    //std::cout <<  completion["choices"][0]["text"]; 
    return completion["choices"][0]["text"];
}
int main() {

    openai::start("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"); // Will use the api key provided by `OPENAI_API_KEY` environment variable
    // openai::start("your_API_key", "optional_organization"); // Or you can handle it yourself

    std::string text="что такое ооп?";
    std::cout<<getText(text);


}
