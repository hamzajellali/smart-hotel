#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQueryModel>


#include <QMap>
#include <QDateTime>
#include <QInputDialog>
#include <QMessageBox>
class ChatBot {
public:
    ChatBot() {}

    QString respondToQuestion(const QString &question) {
        if (knowledgeBase.contains(question)) {
            return knowledgeBase[question];  // Répondre avec la réponse connue
        } else {
            // Si la question n'est pas connue, demander une réponse à l'utilisateur
            QString userResponse = QInputDialog::getText(nullptr, "Nouvelle question",
                                                         "Je ne connais pas encore la réponse à cette question. Quelle est la réponse ?");
            if (!userResponse.isEmpty()) {
                // Enregistrer la nouvelle question-réponse
                knowledgeBase[question] = userResponse;
                return "Merci ! J'ai appris une nouvelle réponse.";
            }
            return "Je ne peux pas répondre à cette question.";
        }
    }

private:
    QMap<QString, QString> knowledgeBase; // Base de connaissances
};


class employee{
    int id;
    QString nom;
    QString prenom;
    QString mail;
    QString dateembauche;
    QString certificats;
    QString diplomes;
    QString salaire;
    QString assurance;
public:

    employee(){}
    employee(int , QString , QString , QString , QString , QString , QString , QString , QString );

    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getid(){return id;}

    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setid(int id){this->id=id;}


    bool ajouter();
    bool supprimer(int);
    int getNextId();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher2();
    QSqlQueryModel* rechercherParNom(const QString &nomRecherche);

    QSqlQueryModel* RechercherEmploye(const QString &text);

    bool modifier();
    //bool Modifieremployee();

};





#endif // EMPLOYEE_H
