#include"image.h"
using namespace std;
string url_encode(string value) {
    ostringstream escaped;
    escaped.fill('0');
    escaped << hex;

    for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        string::value_type c = (*i);


        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }


        escaped << uppercase;
        escaped << '%' << setw(2) << int((unsigned char) c);
        escaped << nouppercase;
    }

    return escaped.str();
}

QString getImage(QString text,QString size) {
    openai::start("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");


    auto image = openai::image().create({
           { "prompt", text.toStdString()},
           { "n", 1 },
           { "size", size.toStdString() }
       });

    QString a = QString::fromStdString(url_encode(image["data"][0]["url"]));



       return a;
}




