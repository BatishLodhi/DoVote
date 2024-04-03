#include "MainWindow.h"
#include <QApplication>
#include "globals.h"


int main(int argc, char *argv[])
{
    // Initialize globalCandidatesList with five parties and 0 votes
    globalCandidatesList = new CandidateNode("PMLN");
    globalCandidatesList->next = new CandidateNode("PTI");
    globalCandidatesList->next->next = new CandidateNode("PML");
    globalCandidatesList->next->next->next = new CandidateNode("PPP");
    globalCandidatesList->next->next->next->next = new CandidateNode("MQM");
    CandidateNode* currentCandidate = globalCandidatesList;
    while (currentCandidate) {
        currentCandidate->votes = 0;
        currentCandidate = currentCandidate->next;
    }

    // Running the application
    QApplication a(argc, argv);
    a.setApplicationDisplayName("DoVote");
    MainWindow w;
    w.show();
    return a.exec();
}
