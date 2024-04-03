#include "view.h"
#include "ui_view.h"

view::view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view)
{
    ui->setupUi(this);
}

view::~view()
{
    delete ui;
}

void view::setCandidateInfo(const QString& info)
{
    ui->out_text->setPlainText(info);  // setting the PlainTextEdit as "info"
}

void view::on_backbtn_clicked()
{
    this->close(); // Close the view form
    emit backClicked(); // Emit a signal to notify MainWindow that the back button is clicked
}
