#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "globals.h"
#include "view.h"
#include "end.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onViewBackClicked(); // declaring back button function for view-form

private slots:
    // declaring functions of all button functions on MainWindow
    void on_votebtn_clicked();
    void on_exitbtn_clicked();
    void on_currbtn_clicked();
    void on_endbtn_clicked();
    // declaration of function to sort candidates
    CandidateNode* sortCandidates(CandidateNode* head);

private:
    Ui::MainWindow *ui;
    view *viewform; // making an object (viewform) of class (view)
    end *endform; // making an object (endform) of class (end)
};
#endif // MAINWINDOW_H
