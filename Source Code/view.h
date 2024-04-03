#ifndef VIEW_H
#define VIEW_H

#include <QDialog>

namespace Ui {
class view;
}

class view : public QDialog
{
    Q_OBJECT

public:
    explicit view(QWidget *parent = nullptr);
    ~view();

    void setCandidateInfo(const QString& info); // declaration of setWinner Function

signals:
    void backClicked(); // Declaring the backClicked signal

private slots:
    void on_backbtn_clicked(); // Declaring the back button function

private:
    Ui::view *ui;
};

#endif // VIEW_H
