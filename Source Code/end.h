#ifndef END_H
#define END_H

#include <QDialog>

namespace Ui {
class end;
}

class end : public QDialog
{
    Q_OBJECT

public:
    explicit end(QWidget *parent = nullptr);
    ~end();

    void setCandidateInfo(const QString& info); // declaration of setCandidateInfo Function

private slots:
    void on_fexitbtn_clicked();  // declaration of exit button Function

private:
    Ui::end *ui;
};

#endif // END_H
