#include "newworld.h"
#include "ui_newworld.h"
#include <QStatusBar>
#include <QMessageBox>
#include <QTextCodec>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>

NewWorld::NewWorld(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWorld)
{
    ui->setupUi(this);
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    chargerListeRayon();
    chargerCombo();
    chargerListeActif();
    chargerListeInactif();
    chargerComboAct();
    chargerComboDesact();
}

NewWorld::~NewWorld()
{
    delete ui;
}

void NewWorld::chargerComboAct(){
    //Charger ComboBox
    modelComboAct.setQuery("select produitId,produitLib from produit where actif=1");
    ui->comboBoxProdAct->setModel(&modelComboAct);
    ui->comboBoxProdAct->setModelColumn(1);
}
void NewWorld::chargerComboDesact(){
        //Charger ComboBox
    modelComboDesact.setQuery("select produitId,produitLib from produit where actif=0");
    ui->comboBoxProdDesact->setModel(&modelComboDesact);
    ui->comboBoxProdDesact->setModelColumn(1);
}

void NewWorld::chargerCombo(){
    //Charger ComboBox
    modelCombo.setQuery("select rayonId,rayonLib from rayon");
    ui->comboBoxNewProd->setModel(&modelCombo);
    ui->comboBoxNewProd->setModelColumn(1);

    modelCombo.setQuery("select rayonId,rayonLib from rayon");
    ui->comboBoxModifProd->setModel(&modelCombo);
    ui->comboBoxModifProd->setModelColumn(1);
}

void NewWorld::chargerListeActif(){
    //tableau de Produit
    modelActif.setQuery("select rayonLib,produitLib from produit natural join rayon where actif=1;");
    ui->tableViewProdActif->setModel(&modelActif);
    ui->tableViewProdActif->resizeColumnsToContents();
    ui->tableViewProdActif->resizeRowsToContents();
    modelActif.setHeaderData(0, Qt::Horizontal, tr("Rayon"));
    modelActif.setHeaderData(1, Qt::Horizontal, tr("Produit"));
}

void NewWorld::chargerListeInactif(){
    //tableau de Produit
    modelInactif.setQuery("select rayonLib,produitLib from produit natural join rayon where actif=0;");
    ui->tableViewProdDesact->setModel(&modelInactif);
    ui->tableViewProdDesact->resizeColumnsToContents();
    ui->tableViewProdDesact->resizeRowsToContents();
    modelInactif.setHeaderData(0, Qt::Horizontal, tr("Rayon"));
    modelInactif.setHeaderData(1, Qt::Horizontal, tr("Produit"));
}

void NewWorld::chargerListeRayon(){
    //tableau de Rayon
    modelRayon.setQuery("select rayonLib from rayon natural join organisation order by organisationOrdre");
    ui->tableViewRay->setModel(&modelRayon);
    ui->tableViewRay->resizeColumnsToContents();
    ui->tableViewRay->resizeRowsToContents();
    modelRayon.setHeaderData(0, Qt::Horizontal, tr("Désignation"));
}



void NewWorld::on_pushButtonValidConnect_clicked()
{
    if(ui->lineEditMdpAdmin->text()=="ini01")
    {
        ui->stackedWidgetApp->setCurrentIndex(1);
    }
    else
    {
        ui->statusBar->showMessage("Erreur de saisie du mot de passe.");
    }
}

void NewWorld::on_pushButtonUp_clicked()
{
    QSqlQuery reqMax1;
    reqMax1.prepare("select max(organisationOrdre)+1 from organisation");
    reqMax1.exec();
    reqMax1.first();
    int max = reqMax1.value(0).toInt();

    QSqlQuery reqUpdate1;
    reqUpdate1.prepare("update organisation set organisationOrdre=:max where organisationOrdre=:up");
    reqUpdate1.bindValue(":max", max);
    reqUpdate1.bindValue(":up", ui->tableViewRay->currentIndex().row());
    reqUpdate1.exec();
    reqUpdate1.first();

    QSqlQuery reqUpdate2;
    reqUpdate2.prepare("update organisation set organisationOrdre=:up where organisationOrdre=:current");
    reqUpdate2.bindValue(":up", ui->tableViewRay->currentIndex().row());
    reqUpdate2.bindValue(":current", ui->tableViewRay->currentIndex().row()+1);
    reqUpdate2.exec();
    reqUpdate1.first();

    QSqlQuery reqUpdate3;
    reqUpdate3.prepare("update organisation set organisationOrdre=:down where organisationOrdre=:current");
    reqUpdate3.bindValue(":down", ui->tableViewRay->currentIndex().row()+1);
    reqUpdate3.bindValue(":current", max);
    reqUpdate3.exec();
    reqUpdate3.first();

    chargerListeRayon();
}

void NewWorld::on_pushButtonDown_clicked()
{
    QSqlQuery reqMax;
    reqMax.prepare("select max(organisationOrdre)+1 from organisation");
    reqMax.exec();
    reqMax.first();
    int max = reqMax.value(0).toInt();

    QSqlQuery reqUpdate1;
    reqUpdate1.prepare("update organisation set organisationOrdre=:max where organisationOrdre=:down");
    reqUpdate1.bindValue(":max", max);
    reqUpdate1.bindValue(":down", ui->tableViewRay->currentIndex().row()+2);
    reqUpdate1.exec();
    reqUpdate1.first();

    QSqlQuery reqUpdate2;
    reqUpdate2.prepare("update organisation set organisationOrdre=:down where organisationOrdre=:current");
    reqUpdate2.bindValue(":down", ui->tableViewRay->currentIndex().row()+2);
    reqUpdate2.bindValue(":current", ui->tableViewRay->currentIndex().row()+1);
    reqUpdate2.exec();
    reqUpdate1.first();

    QSqlQuery reqUpdate3;
    reqUpdate3.prepare("update organisation set organisationOrdre=:down where organisationOrdre=:current");
    reqUpdate3.bindValue(":up", ui->tableViewRay->currentIndex().row()+1);
    reqUpdate3.bindValue(":current", max);
    reqUpdate3.exec();
    reqUpdate3.first();

    chargerListeRayon();
}

void NewWorld::on_pushButtonRayValid_clicked()
{
    QString lib = ui->lineEditDesRay->text();
    if(lib!="")
    {
    QSqlQuery reqMax;
    reqMax.prepare("select max(rayonId)+1 from rayon");
    reqMax.exec();
    reqMax.first();
    int max=reqMax.value(0).toInt();
    qDebug()<<max;

    QSqlQuery reqInsert1;
    reqInsert1.prepare("insert into rayon value (:max,\""+lib+"\")");
    reqInsert1.bindValue(":max", max);
    reqInsert1.exec();
    reqInsert1.first();
    qDebug()<<lib;

    QSqlQuery reqInsert2;
    reqInsert2.prepare("insert into organisation value (1,:max1,:max2)");
    reqInsert2.bindValue(":max1", max);
    reqInsert2.bindValue(":max2", max);
    reqInsert2.exec();
    reqInsert2.first();

    chargerListeRayon();
    }
}

void NewWorld::on_pushButtonRayModif_clicked()
{
    QSqlQuery reqUpdate;
    reqUpdate.prepare("update rayon set rayonLib=\""+ui->lineEditModifRay->text()+"\" where rayonId=:current");
    reqUpdate.bindValue(":current", ui->tableViewRay->currentIndex().row());
    reqUpdate.exec();
    reqUpdate.first();
    chargerListeRayon();
}

void NewWorld::on_pushButtonProdValid_clicked()
{
    QString lib = ui->lineEditProdDesi->text();
    if(lib!="")
    {
    QSqlQuery reqMax;
    reqMax.prepare("select max(produitId)+1 from produit");
    reqMax.exec();
    reqMax.first();
    int max=reqMax.value(0).toInt();
    ui->comboBoxNewProd->setModelColumn(0);
    qDebug()<<max;
    qDebug()<<ui->comboBoxNewProd->currentText();
    qDebug()<<lib;

    QSqlQuery reqInsert;
    reqInsert.prepare("insert into produit value (:max,\""+lib+"\",:rayon,1)");
    reqInsert.bindValue(":max", max);
    reqInsert.bindValue(":rayon", ui->comboBoxNewProd->currentText());
    reqInsert.exec();
    reqInsert.first();

    ui->comboBoxNewProd->setModelColumn(1);
    chargerListeActif();
    }
}

void NewWorld::on_comboBoxNewProd_activated()
{
    ui->comboBoxNewProd->setModelColumn(0);

    //tableau de Produit
    modelActif.setQuery("select rayonLib,produitLib from produit natural join rayon where actif=1 and rayonId="+ui->comboBoxNewProd->currentText());
    ui->tableViewProdActif->setModel(&modelActif);
    ui->tableViewProdActif->resizeColumnsToContents();
    ui->tableViewProdActif->resizeRowsToContents();
    modelActif.setHeaderData(0, Qt::Horizontal, tr("Rayon"));
    modelActif.setHeaderData(1, Qt::Horizontal, tr("Produit"));

    ui->comboBoxNewProd->setModelColumn(1);
}

void NewWorld::on_pushButtonProdDesac_clicked()
{
    ui->comboBoxProdAct->setModelColumn(0);
    QSqlQuery reqUpdate;
    reqUpdate.prepare("update produit set actif=0 where produitId=:current");
    reqUpdate.bindValue(":current", ui->comboBoxProdAct->currentText());
    reqUpdate.exec();
    reqUpdate.first();
    ui->comboBoxProdAct->setModelColumn(1);
    chargerListeActif();
    chargerListeInactif();
    chargerComboAct();
    chargerComboDesact();
}

void NewWorld::on_pushButtonProdReact_clicked()
{
ui->comboBoxProdDesact->setModelColumn(0);
    QSqlQuery reqUpdate;
    reqUpdate.prepare("update produit set actif=1 where produitId=:current");
    reqUpdate.bindValue(":current", ui->comboBoxProdDesact->currentText());
    reqUpdate.exec();
    reqUpdate.first();
    ui->comboBoxProdDesact->setModelColumn(1);
    chargerListeActif();
    chargerListeInactif();
    chargerComboAct();
    chargerComboDesact();
}
