#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "vote.h"
#include "view.h"
#include "end.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_votebtn_clicked()
{
    vote *voteform = new class vote; // making an object (voteform) of class (vote)
    voteform -> show(); // showing voteform
    this->close(); // closing current screen (MainWindow) when vote button is clicked
}

void MainWindow::on_exitbtn_clicked()
{
    this->close(); // closing current screen (MainWindow) when vote button is clicked
}

void MainWindow::on_currbtn_clicked()
{
    // Sort the linked list based on the number of votes in descending order
    globalCandidatesList = sortCandidates(globalCandidatesList);

    // Initialize a QString to store the candidate information
    QString candidateInfo;

    // Traverse the sorted linked list and append each candidate's information to the QString
    CandidateNode* currentCandidate = globalCandidatesList;
    while (currentCandidate) {
        candidateInfo.append("  " + currentCandidate->name + " --> Votes: " + QString::number(currentCandidate->votes) + "\n");
        currentCandidate = currentCandidate->next;
    }

    // Open the view form and display the candidate information
    viewform = new view();
    viewform->setCandidateInfo(candidateInfo);
    connect(viewform, &view::backClicked, this, &MainWindow::onViewBackClicked); // Connect backClicked signal
    viewform->show();
    hide(); // Hides the main window
}

// Function to sort the linked list of candidates based on votes in descending order using insertion sort
CandidateNode* MainWindow::sortCandidates(CandidateNode* head)
{
    if (!head || !head->next) {
        return head; // If the list is empty or has only one node, it's already sorted
    }
    CandidateNode* sorted = nullptr; // Initialize the sorted list as empty
    CandidateNode* current = head;
    // Traverse the original list
    while (current) {
        CandidateNode* next = current->next; // Store the next node before modifying current

        // Insert current into the sorted list
        if (!sorted || current->votes >= sorted->votes) {
            current->next = sorted;
            sorted = current;
        } else {
            CandidateNode* temp = sorted;
            while (temp->next && temp->next->votes > current->votes) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next; // Move to the next node in the original list
    }
    return sorted;
}

void MainWindow::onViewBackClicked()
{
    this->show(); // implementation for back button in view-form
}

void MainWindow::on_endbtn_clicked()
{
    // Sort the linked list based on the number of votes in descending order
    globalCandidatesList = sortCandidates(globalCandidatesList);

    // Initialize a QString to store the candidate information
    QString candidateInfo;

    // Traverse the sorted linked list and append each candidate's information to the QString
    CandidateNode* currentCandidate = globalCandidatesList;
    while (currentCandidate) {
        candidateInfo.append("  " + currentCandidate->name + " --> Votes: " + QString::number(currentCandidate->votes) + "\n");
        currentCandidate = currentCandidate->next;
    }

    // Open the view form and display the winner
    endform = new end();
    endform->setCandidateInfo(candidateInfo);
    endform->show();
    hide(); // Hides the main window
}

