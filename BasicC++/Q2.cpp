#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void displayResults(const vector<int>& accessSeq, int totalMovement, const string& method) {
    cout << "\n--- " << method << " Disk Scheduling ---\n";
    cout << "Seek Sequence: ";
    for (size_t k = 0; k < accessSeq.size(); ++k) {
        cout << accessSeq[k];
        if (k != accessSeq.size() - 1) cout << " -> ";
    }
    cout << "\nTotal Seek Time: " << totalMovement << "\n";
}

void runFCFS(const vector<int>& jobs, int initPos) {
    vector<int> sequence = {initPos};
    int moveSum = 0, curr = initPos;

    for (int j : jobs) {
        moveSum += abs(curr - j);
        curr = j;
        sequence.push_back(j);
    }

    displayResults(sequence, moveSum, "FCFS");
}

void runSSTF(vector<int> jobs, int initPos) {
    vector<int> sequence = {initPos};
    int moveSum = 0, curr = initPos;

    while (!jobs.empty()) {
        auto closest = min_element(jobs.begin(), jobs.end(),
            [=](int a, int b) {
                return abs(a - curr) < abs(b - curr);
            });
        moveSum += abs(curr - *closest);
        curr = *closest;
        sequence.push_back(curr);
        jobs.erase(closest);
    }

    displayResults(sequence, moveSum, "SSTF");
}

void runSCAN(vector<int> jobs, int initPos, int maxTrack, const string& dir) {
    vector<int> leftSide, rightSide, sequence = {initPos};
    int moveSum = 0, curr = initPos;

    for (int j : jobs) {
        if (j < initPos) leftSide.push_back(j);
        else rightSide.push_back(j);
    }

    sort(leftSide.begin(), leftSide.end());
    sort(rightSide.begin(), rightSide.end());

    if (dir == "left") {
        for (int i = leftSide.size() - 1; i >= 0; i--) {
            moveSum += abs(curr - leftSide[i]);
            curr = leftSide[i];
            sequence.push_back(curr);
        }
        if (!leftSide.empty() && leftSide[0] > 0) {
            moveSum += curr;
            curr = 0;
        }
        for (int j : rightSide) {
            moveSum += abs(curr - j);
            curr = j;
            sequence.push_back(curr);
        }
    } else {
        for (int j : rightSide) {
            moveSum += abs(curr - j);
            curr = j;
            sequence.push_back(curr);
        }
        if (!rightSide.empty() && rightSide.back() < maxTrack - 1) {
            moveSum += (maxTrack - 1 - curr);
            curr = maxTrack - 1;
        }
        for (int i = leftSide.size() - 1; i >= 0; i--) {
            moveSum += abs(curr - leftSide[i]);
            curr = leftSide[i];
            sequence.push_back(curr);
        }
    }

    displayResults(sequence, moveSum, "SCAN (" + dir + ")");
}

void runCSCAN(vector<int> jobs, int initPos, int maxTrack) {
    vector<int> leftSide, rightSide, sequence = {initPos};
    int moveSum = 0, curr = initPos;

    for (int j : jobs) {
        if (j < initPos) leftSide.push_back(j);
        else rightSide.push_back(j);
    }

    sort(leftSide.begin(), leftSide.end());
    sort(rightSide.begin(), rightSide.end());

    if (leftSide.empty() && rightSide.empty()) {
        displayResults(sequence, 0, "C-SCAN");
        return;
    }

    for (int i = leftSide.size() - 1; i >= 0; i--) {
        moveSum += abs(curr - leftSide[i]);
        curr = leftSide[i];
        sequence.push_back(curr);
    }

    if (!leftSide.empty() && leftSide[0] > 0) {
        moveSum += curr;
        curr = 0;
        sequence.push_back(curr);
    } else if (leftSide.empty()) {
        moveSum += curr;
        curr = 0;
        sequence.push_back(curr);
    }

    moveSum += maxTrack - 1;
    curr = maxTrack - 1;
    sequence.push_back(curr);

    for (int i = rightSide.size() - 1; i >= 0; i--) {
        moveSum += abs(curr - rightSide[i]);
        curr = rightSide[i];
        sequence.push_back(curr);
    }

    displayResults(sequence, moveSum, "C-SCAN");
}

void runLOOK(vector<int> jobs, int initPos, const string& dir) {
    vector<int> leftSide, rightSide, sequence = {initPos};
    int moveSum = 0, curr = initPos;

    for (int j : jobs) {
        if (j < initPos) leftSide.push_back(j);
        else rightSide.push_back(j);
    }

    sort(leftSide.begin(), leftSide.end());
    sort(rightSide.begin(), rightSide.end());

    if (dir == "left") {
        for (int i = leftSide.size() - 1; i >= 0; i--) {
            moveSum += abs(curr - leftSide[i]);
            curr = leftSide[i];
            sequence.push_back(curr);
        }
        for (int j : rightSide) {
            moveSum += abs(curr - j);
            curr = j;
            sequence.push_back(curr);
        }
    } else {
        for (int j : rightSide) {
            moveSum += abs(curr - j);
            curr = j;
            sequence.push_back(curr);
        }
        for (int i = leftSide.size() - 1; i >= 0; i--) {
            moveSum += abs(curr - leftSide[i]);
            curr = leftSide[i];
            sequence.push_back(curr);
        }
    }

    displayResults(sequence, moveSum, "LOOK (" + dir + ")");
}

void runCLOOK(vector<int> jobs, int initPos) {
    vector<int> leftSide, rightSide, sequence = {initPos};
    int moveSum = 0, curr = initPos;

    for (int j : jobs) {
        if (j < initPos) leftSide.push_back(j);
        else rightSide.push_back(j);
    }

    sort(leftSide.begin(), leftSide.end());
    sort(rightSide.begin(), rightSide.end());

    if (leftSide.empty() && rightSide.empty()) {
        displayResults(sequence, 0, "C-LOOK");
        return;
    }

    for (int i = leftSide.size() - 1; i >= 0; i--) {
        moveSum += abs(curr - leftSide[i]);
        curr = leftSide[i];
        sequence.push_back(curr);
    }

    if (!rightSide.empty()) {
        moveSum += abs(curr - rightSide.back());
        curr = rightSide.back();
        sequence.push_back(curr);

        for (int i = rightSide.size() - 2; i >= 0; i--) {
            moveSum += abs(curr - rightSide[i]);
            curr = rightSide[i];
            sequence.push_back(curr);
        }
    }

    displayResults(sequence, moveSum, "C-LOOK");
}

int main() {
    int reqCount, initHead, trackLimit;
    string scanDir;

    cout << "Enter number of disk requests: ";
    cin >> reqCount;
    vector<int> queue(reqCount);

    cout << "Enter the disk requests: ";
    for (int i = 0; i < reqCount; ++i) cin >> queue[i];

    cout << "Enter initial head position: ";
    cin >> initHead;

    cout << "Enter total disk size (max cylinder number): ";
    cin >> trackLimit;

    cout << "Enter initial direction (left/right): ";
    cin >> scanDir;

    runFCFS(queue, initHead);
    runSSTF(queue, initHead);
    runSCAN(queue, initHead, trackLimit, scanDir);
    runCSCAN(queue, initHead, trackLimit);
    runLOOK(queue, initHead, scanDir);
    runCLOOK(queue, initHead);

    return 0;
}
