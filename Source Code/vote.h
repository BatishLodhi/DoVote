#ifndef VOTE_H
#define VOTE_H

#include <QDialog>
#include <QMessageBox>
#include "ui_vote.h"
#include "globals.h" // Include the globals header

class vote : public QDialog
{
    Q_OBJECT

public:
    explicit vote(QWidget *parent = nullptr);
    ~vote();

private slots:
    void on_submitbtn_clicked(); // declaring submit button function

private:
    Ui::vote *ui;
    CandidateNode* candidatesList; // making an object (candidatesList) of struct (CandidateNode)
};

#endif // VOTE_H
