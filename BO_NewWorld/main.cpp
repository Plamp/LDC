#include "QApplication"
#include "newworld.h"
#include <QSqlDatabase>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //connexion
    QSqlDatabase baseNW=QSqlDatabase::addDatabase("QMYSQL");
    baseNW.setHostName("127.0.0.1");
    baseNW.setUserName("root");
    baseNW.setPassword("");
    baseNW.setDatabaseName("u683437950_dblis");
    if(!baseNW.open())
    {
        qDebug("Pas marche");
        //QMessageBox::warning(this,this->windowTitle(),"Le serveur de base de données est inaccessible.\r\rMerci de contacter votre administrateur et de relancer l'application après avoir réglé le problème.");
    }
    NewWorld w;
    w.show();
    
    return a.exec();
}
