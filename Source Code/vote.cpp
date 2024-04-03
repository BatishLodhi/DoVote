#include "vote.h"
#include "MainWindow.h"
#include "ui_vote.h"
#include <QDebug>
#include <QIntValidator>

vote::vote(QWidget *parent) : QDialog(parent), ui(new Ui::vote)
{
    ui->setupUi(this);
    candidatesList = globalCandidatesList; // Initialize candidatesList with the global globalCandidatesList variable

    // Create a regular expression for 13-digit integers
    QRegularExpression regex("^\\d{1,13}$");

    // Create a validator with the regular expression
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(regex, this);

    // Set the validator for the CNIC input field
    ui->cnic_input->setValidator(validator);
}

vote::~vote()
{
    delete ui;
}

void vote::on_submitbtn_clicked()
{
    // Retrieve the text from the input field
    QString cnic = ui->cnic_input->text();

    // Check if the CNIC is empty
    if (cnic.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter your CNIC.");
        return;
    }

    // Check if the CNIC is valid (13 digits)
    if (cnic.length() != 13) {
        QMessageBox::warning(this, "Error", "Invalid CNIC length. CNIC must be 13 digits.");
        return;
    }

    // Check if the CNIC is already in use
    if (std::any_of(globalVotersList.begin(), globalVotersList.end(),
                    [cnic](const QString& voter) { return voter == cnic; })) {
        QMessageBox::warning(this, "Error", "This CNIC has already been used for voting.");
        return;
    }

    // Check if a valid candidate is chosen
    if (!(ui->pmln_rb->isChecked() || ui->pti_rb->isChecked() || ui->pml_rb->isChecked() ||
          ui->ppp_rb->isChecked() || ui->mqm_rb->isChecked())) {
        QMessageBox::warning(this, "Error", "Please select a candidate.");
        return;
    }

    // Store the CNIC in the global voters list
    globalVotersList.append(cnic);

    // Get the selected candidate's name from the radio buttons
    QString selectedCandidate = "";
    if (ui->pmln_rb->isChecked()) {
        selectedCandidate = "PMLN";
    } else if (ui->pti_rb->isChecked()) {
        selectedCandidate = "PTI";
    } else if (ui->pml_rb->isChecked()) {
        selectedCandidate = "PML";
    } else if (ui->ppp_rb->isChecked()) {
        selectedCandidate = "PPP";
    } else if (ui->mqm_rb->isChecked()) {
        selectedCandidate = "MQM";
    }

    // Update the candidate's votes in the linked list
    CandidateNode* currentCandidate = candidatesList;
    while (currentCandidate) {
        if (currentCandidate->name == selectedCandidate) {
            currentCandidate->votes++;
            break;
        }
        currentCandidate = currentCandidate->next;
    }

    // Close the current vote form
    this->close();

    // Open the MainWindow
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}
