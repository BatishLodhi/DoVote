#ifndef GLOBALS_H
#define GLOBALS_H

#include <QStringList>

// Declaring Node Structure
struct CandidateNode {
    QString name;
    int votes;
    CandidateNode* next;
    CandidateNode(QString n) : name(n), votes(0), next(nullptr) {}
};

// Declare globalCandidatesList as extern
extern CandidateNode* globalCandidatesList;
extern QStringList globalVotersList;

#endif // GLOBALS_H
