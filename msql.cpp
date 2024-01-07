#include"msql.h"



DB::DB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("tgbot");
    db.open();

}

DB::~DB() {
    db.close();
}







int DB::chekStat(const qlonglong *id) {

    QSqlQuery *query = new QSqlQuery(db);

    if(query->exec("SELECT accmode FROM users WHERE tgid="+QString::number(*id))) {

        query->first();
        int s = query->value(0).toInt();

        delete query;
        return s;
    }

    delete query;

    return 5;


}





bool DB::chekAv(const qlonglong *id) {



    QSqlQuery *query = new QSqlQuery(db);
    query->exec("SELECT tgid FROM users");
    while (query->next()) {


        if (query->value(0)==QString::number(*id)) {
            delete query;

            return 1;
        }
    }
    delete query;

    return 0;

}




void DB::insert(const qlonglong *id, const QString *username) {



    QSqlQuery *query = new QSqlQuery(db);


        if (!chekAv(id)) {

            if(query->exec("INSERT INTO users (tgid,username,accmode,limit_req,context,role,rolestat) VALUES(\""+QString::number(*id)+"\",\""+username+"\",1,10,\"\",\"\",0)")) {
                qDebug()<<"пользователь "<<id<<" добавлен";
            } else qDebug()<<"пользователь "<<id<<" не добавлен";

        } else qDebug()<<"Пользователь уже существует";




    delete query;

}

void DB::changeNeiro(const qlonglong *id, const QString neiro) {
      QSqlQuery *query = new QSqlQuery(db);
      if (chekAv(id)) {
          if (neiro=="chat") {
              if(query->exec("UPDATE users SET changet_neiro = 1 WHERE tgid="+QString::number(*id))) {
                  qDebug()<<"изменено";
              } else qDebug()<<"нет";
          }

          if (neiro=="dalle") {
              if(query->exec("UPDATE users SET changet_neiro = 2 WHERE tgid="+QString::number(*id))) {
                  qDebug()<<"изменено";
              } else qDebug()<<"нет";
          }



      } else qDebug()<<"неизвестный пользователь";
      delete query;
}

int DB::checkNeiro(const qlonglong *id) {
    QSqlQuery *query = new QSqlQuery(db);

    if(query->exec("SELECT changet_neiro FROM users WHERE tgid="+QString::number(*id))) {

        query->first();
        int s = query->value(0).toInt();

        delete query;
        return s;
    }

    delete query;

    return 3;
}


int DB::numOfReq(const qlonglong *id) {
    QSqlQuery *query = new QSqlQuery(db);

    if(query->exec("SELECT num_of_req FROM users WHERE tgid="+QString::number(*id))) {

        query->first();
        int s = query->value(0).toInt();

        delete query;
        return s;
    }
    delete query;
    return 0;
}


void DB::reqDecriment(const qlonglong *id) {
    int *numofre= new int;
    *numofre = numOfReq(id);
    if (*numofre>0) {
        QSqlQuery *query = new QSqlQuery(db);
        if(query->exec("UPDATE users SET num_of_req = "+QString::number(*numofre-1)+" WHERE tgid="+QString::number(*id))) {
            qDebug()<<"-1"<< "У пользователя "<< *id<< " осталось "<<*numofre-1<<" запросов";
            delete query;

        } else qDebug()<<"Декримент не сработал";

    }

    delete numofre;
}

int DB::getLimReq(const qlonglong *id) {
    QSqlQuery *query = new QSqlQuery(db);

    if(query->exec("SELECT limit_req FROM users WHERE tgid="+QString::number(*id))) {

        query->first();
        int s = query->value(0).toInt();

        delete query;
        return s;
    }
    delete query;
    return 0;
}


void DB::resetRq() {
    QSqlQuery *query = new QSqlQuery(db);


        query->exec("UPDATE users SET num_of_req = limit_req");


    delete query;

}

void DB::addLimReq(const QString *id) {
    QSqlQuery *query = new QSqlQuery(db);


        query->exec("UPDATE users SET limit_req = limit_req + 5 WHERE tgid="+*id);


    delete query;
}

void DB::uvedSwap(const qlonglong *id,int m) {
    QSqlQuery *query = new QSqlQuery(db);
    if (chekStat(id)==3) {
        if (m==1) {
            query->exec("UPDATE users SET accmode=4 WHERE tgid="+QString::number(*id));
        } else  query->exec("UPDATE users SET accmode=3 WHERE tgid="+QString::number(*id));
    }
    if (m==1) {
        query->exec("UPDATE users SET accmode=2 WHERE tgid="+QString::number(*id));
    } else  query->exec("UPDATE users SET accmode=1 WHERE tgid="+QString::number(*id));

    delete query;
}


//context end role
bool DB::isContext(const qlonglong *id) {
    QSqlQuery *query = new QSqlQuery(db);

    if(query->exec("SELECT rolestat FROM users WHERE tgid="+QString::number(*id))) {

        query->first();
        bool s = query->value(0).toBool();
        qDebug()<<s;
        delete query;
        return s;
    }
    delete query;
    return 0;
}



void DB::changeCont(const qlonglong *id,bool stat) {

    QSqlQuery *query = new QSqlQuery(db);
    if (stat) {
        query->exec("UPDATE users SET rolestat=1 WHERE tgid="+QString::number(*id));
    } else {
        query->exec("UPDATE users SET rolestat=0 WHERE tgid="+QString::number(*id));
    }
    delete query;
}



QString DB::checkCOntext(const qlonglong *id) {
    QSqlQuery *query = new QSqlQuery(db);
    if(query->exec("SELECT context FROM users WHERE tgid="+QString::number(*id))) {

        query->first();
          QString s = query->value(0).toString();

        delete query;
        return s;
    }
    delete query;
    return "";
}



void DB::clearContext(const qlonglong *id) {
    QSqlQuery *query = new QSqlQuery(db);


        query->exec("UPDATE users SET context =\"Ответь на запрос учитываю предыдущие сообщения(не пиши перед своим сообщением слово Ты:):\n\" WHERE tgid="+QString::number(*id));


    delete query;
}



void DB::addcontext(const qlonglong *id,const QString *messageuser,const QString *messagebot) {
    QString *temp = new QString;
    *temp = checkCOntext(id);

     if (temp->size()>3800) clearContext(id);

     *temp+= "  Я:"+*messageuser+" Ты:\n\n "+*messagebot+"";

    QSqlQuery *query = new QSqlQuery(db);



    qDebug()<<*temp;
    if (query->exec("UPDATE users SET context=\""+*temp+"\" WHERE tgid="+QString::number(*id))) qDebug()<<"oik";

    delete temp;
    delete query;

}



//admin

QString DB::usersinfo() {
    QSqlQuery *query = new QSqlQuery(db);
    QStringList *idlist=new QStringList;
    QStringList *namelist=new QStringList;

    query->exec("SELECT tgid FROM users");
    while (query->next()) {


            idlist->push_back(query->value(0).toString());



        }
    delete query;


    QSqlQuery *query2 = new QSqlQuery(db);
    query2->exec("SELECT username FROM users");
    while (query2->next()) {


            namelist->push_back(query2->value(0).toString());

        }
    delete query2;
    for (int i =0;i<namelist->size();i++) {
        str+=idlist->at(i)+" "+namelist->at(i)+"\n";
    }
    delete namelist;
    delete idlist;
    return str;
    }






