#include "end.h"
#include "ui_end.h"

end::end(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::end)
{
    ui->setupUi(this);
}

end::~end()
{
    delete ui;
}

void end::on_fexitbtn_clicked()
{
    this->close(); // closing current screen when exit button is clicked
}

void end::setCandidateInfo(const QString& info)
{
    ui->out_text->setPlainText(info); // setting the PlainTextEdit as "info"
}
