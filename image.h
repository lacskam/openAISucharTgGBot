#ifndef IMAGE_H
#define IMAGE_H
#include <stdio.h>
#include<iostream>
#include "openai-cpp/include/openai/openai.hpp"
#include<QString>
#include<nlohmann/json.hpp>
#include<QDebug>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

QString getImage(QString text, QString size="512x512");
#endif // IMAGE_H
