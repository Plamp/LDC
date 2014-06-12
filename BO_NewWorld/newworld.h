#ifndef NEWWORLD_H
#define NEWWORLD_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QComboBox>

namespace Ui {
class NewWorld;
}

class NewWorld : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit NewWorld(QWidget *parent = 0);
    ~NewWorld();
    
private slots:

    void chargerComboAct();

    void chargerComboDesact();

    void chargerListeActif();

    void chargerListeInactif();

    void chargerCombo();

    void chargerListeRayon();

    void on_pushButtonValidConnect_clicked();

    void on_pushButtonUp_clicked();

    void on_pushButtonDown_clicked();

    void on_pushButtonRayValid_clicked();

    void on_pushButtonRayModif_clicked();

    void on_pushButtonProdValid_clicked();

    void on_comboBoxNewProd_activated();

    void on_pushButtonProdDesac_clicked();

    void on_pushButtonProdReact_clicked();

private:
    Ui::NewWorld *ui;
    QSqlDatabase baseNW;
    QSqlQueryModel   modelRayon;
    QSqlQueryModel   modelActif;
    QSqlQueryModel   modelInactif;
    QSqlQueryModel   modelComboAct;
    QSqlQueryModel   modelComboDesact;
    QSqlQueryModel   modelCombo;
};

#endif // NEWWORLD_H
