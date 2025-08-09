#include <QCoreApplication>
#include <QDebug>
#include <QtCore>
#include "QtTelegramBot/qttelegrambot.h"
#include "completion.h"
#include "image.h"
#include "msql.h"
#include <QStringList>
#include <QList>
#include<QDate>
#include<cstring>
#define TOKEN "token"
DB dbase;
Telegram::Bot *bot;
int date = QDate::currentDate().day();
QStringList l;



void newMessage(Telegram::Message message)
{

    if (date !=QDate::currentDate().day()) {
        dbase.resetRq();
    }




    try {



        if (bot && message.string==("/start")) {
            bot->sendMessage(QString::number(message.chat.id), "\n🤖 Для начала работы выберете интересующую Вас нейронную сеть в меню слева \n\n"
                                              "📝 После выбора напишите Ваш запрос  \n\n"
                                              "Помните, чем подробнее будет ваш запрос, тем коректнее будет ответ нейронной сети.");


            dbase.insert(&message.chat.id,&message.chat.username);
        } else if (message.string.contains("/start ") && !dbase.chekAv(&message.chat.id)) {
            bot->sendMessage(QString::number(message.chat.id), "\n🤖 Для начала работы выберете интересующую Вас нейронную сеть в меню слева \n\n"
                                              "📝 После выбора напишите Ваш запрос  \n\n"
                                              "Помните, чем подробнее будет ваш запрос, тем коректнее будет ответ нейронной сети.");


                dbase.insert(&message.chat.id,&message.chat.username);
                QString *d=new QString;
                *d = message.string.split(" ")[1];
                dbase.addLimReq(d);

                qlonglong *idll = new qlonglong;
                        *idll=d->toLongLong();
                if (dbase.chekStat(idll)!=2 || dbase.chekStat(idll)!=4) {

                 bot->sendMessage(*d,"👥 Кто-то присоеденился по Вашей ссылке\n\nВаше число ежедневных запросов увеличенно на 5\n Для отключения уведоилений:\n/notoff");
                }
                delete d;
                delete idll;

        }



        if (dbase.chekAv(&message.chat.id)) { //проверка авторизации в бд

            if (dbase.numOfReq(&message.chat.id)>0) { // проверка наличия доступных запросов

                if (bot && message.string=="/notoff") {
                    bot->sendMessage(QString::number(message.chat.id),"🔕Уведомления о приглошенных пользователях отключены\n\nДля включения уведомлений:\n/noton");
                    dbase.uvedSwap(&message.chat.id,1);
                }

                if (bot && message.string=="/noton") {
                    bot->sendMessage(QString::number(message.chat.id),"🔔Уведомления о приглошенных пользователях включены\n\nДля отключения уведомлений:\n/notoff");
                    dbase.uvedSwap(&message.chat.id,2);
                }



                if (bot && message.type == Telegram::Message::TextType && !message.string.contains("/account")
                        && !message.string.contains("/help") && !message.string.contains("/start")&& !message.string.contains("/noton")&& !message.string.contains("/notoff") && !message.string.contains("/image")
                        && !message.string.contains("/chatgpt") && dbase.chekStat(&message.chat.id)!=0 && !message.string.contains("sudo")&& !message.string.contains("/context")) {

                    qDebug()<< message.chat.id << message.chat.username << ": " << message.string<< '\n';

                    if (dbase.checkNeiro(&message.chat.id)==1) {
                       if (dbase.isContext(&message.chat.id)) {
                            QString *tempmsg = new QString;
                            *tempmsg = getText(dbase.checkCOntext(&message.chat.id) + "Я:"+message.string+"");
                           bot->sendMessage(QString::number(message.chat.id),*tempmsg );

                            dbase.addcontext(&message.chat.id,&message.string,tempmsg);

                            delete tempmsg;

                       } else bot->sendMessage(QString::number(message.chat.id), getText(message.string));


                    } else if (dbase.checkNeiro(&message.chat.id)==2) bot->sendPhoto(QString::number(message.chat.id),getImage(message.string));

                    else bot->sendMessage(QString::number(message.chat.id), "Выберите нейронную сеть в в меню!");

                    if (dbase.chekStat(&message.chat.id)!=3) {
                        dbase.reqDecriment(&message.chat.id);
                    }
                }


                if (bot && message.string=="/chatgpt" && dbase.chekStat(&message.chat.id)!=0) {  //выбрать chatGPT
                    dbase.changeNeiro(&message.chat.id, "chat");
                    bot->sendMessage(QString::number(message.chat.id),"Используется chatGPT 💬");
                }


                if (bot && message.string=="/image" && dbase.chekStat(&message.chat.id)!=0) {  //выбрать dall-e
                    dbase.changeNeiro(&message.chat.id,"dalle");
                    bot->sendMessage(QString::number(message.chat.id),"Используется DALL-E 🌄");
                }

                if (bot && message.string=="/context") {
                    if (dbase.isContext(&message.chat.id)) {
                        dbase.changeCont(&message.chat.id,0);
                        dbase.clearContext(&message.chat.id);
                        bot->sendMessage(QString::number(message.chat.id),"Учет контекста отключен");
                    } else {

                            dbase.changeCont(&message.chat.id,1);
                            bot->sendMessage(QString::number(message.chat.id),"Учет контекста включен");

                    }
                }



                if (bot && message.string=="/account" && dbase.chekStat(&message.chat.id)!=0) { //инфа о пользователе
                    bot->sendMessage(QString::number(message.chat.id),"\n👤 У вас осталось "+QString::number(dbase.numOfReq(&message.chat.id))+" запросов"
                                     ". \nЗапросы обновляются каждый день.\n\n"
                                     "🎚 Ваше максимальное число ежедневных запросов: "+QString::number(dbase.getLimReq(&message.chat.id))+"\n\n"
                                     "👥 Для увеличения количества ежедневных запросов приглашайте друзей(плюс 5 за каждого) по своей уникальной ссылке:\nhttps://t.me/OpenAISucharTgGBot?start="+QString::number(message.chat.id));
                }



                if (bot && message.string=="/help" && dbase.chekStat(&message.chat.id)!=0) {//help
                    bot->sendMessage(QString::number(message.chat.id), "\n🤖 Для начала работы выберете интересующую Вас нейронную сеть в меню слева \n\n"
                                                      "📝 После выбора напишите Ваш запрос\n\n"
                                                      "❕ Помните, чем подробнее будет ваш запрос, тем коректнее будет ответ нейронной сети.\n\n"
                                                      "⌚ ️Количество запросов боту ограничено, но оно восполняется кажадый день.\n\n"
                                                      "👤 Информацию о Вашем максимальном числе ежедневных запросов можно найти в профиле:\n"
                                                      "/account\n\n"
                                                      "👥 Для увеличения числа ежедневных запросов приглашайте друзей по вашей индивидуальной ссылке:\n""https://t.me/OpenAISucharTgGBot?start="+QString::number(message.chat.id));
                }



                //admin
                if (bot && message.string.contains("sudo") && dbase.chekStat(&message.chat.id)==3) {
                    //select
                    if (bot && message.string.contains("select")){
                        bot->sendMessage(QString::number(message.chat.id),dbase.usersinfo());
                    }
                    //send
                    if (bot && message.string.contains("send")){
                        l=message.string.split("  ");
                        bot->sendMessage(l[2],l[3]);
                    }





                }




            } else {
                bot->sendMessage(QString::number(message.chat.id),"Вы использовали все доступные запросы за день!");
                qDebug()<< message.chat.id << message.chat.username << ": " << message.string<<"(Запросы пользователя исчерпанны)" <<'\n';
            }



        } else bot->sendMessage(QString::number(message.chat.id),"Введите /start");


    } catch(...) {
         bot->sendMessage(QString::number(message.chat.id), "Не удалось обработать запрос. Пожалуйста, попррбуйте ещё раз.");
    }

}

int main(int argc, char *argv[])
{


    QCoreApplication a(argc, argv);

    bot = new Telegram::Bot(TOKEN, true, 500, 4);
    QObject::connect(bot, &Telegram::Bot::message, &newMessage);
    qDebug() << "Started Telegram Bot";

    return a.exec();
}
