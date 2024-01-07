#include"completion.h"


QString getText(QString text) {
    openai::start("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");
    nlohmann::json json = {{"model", "text-davinci-003"},
                            {"prompt",text.toStdString()},
                            {"max_tokens", 1500},
                            {"temperature", 0.9},
                            {"top_p", 1.0},
                            {"frequency_penalty", 0.0},
                            {"presence_penalty",0.6}
                            };


    auto completion = openai::completion().create(json);
    
    //std::cout <<  completion["choices"][0]["text"]; 
    return QString::fromStdString(completion["choices"][0]["text"]);
}
