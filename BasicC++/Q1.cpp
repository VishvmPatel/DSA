#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;

struct Process {
    int pid, arrival, burst, remaining, completion, turnaround, waiting, start = -1;
};

void printTable(const vector<Process>& processes) {
    double totalTAT = 0, totalWT = 0;
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto& p : processes) {
        totalTAT += p.turnaround;
        totalWT += p.waiting;
        cout << "P" << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.completion << "\t" << p.turnaround << "\t" << p.waiting << "\n";
    }
    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << totalTAT / processes.size();
    cout << "\nAverage Waiting Time: " << totalWT / processes.size() << "\n";
}

void printGanttChart(const vector<pair<string, int>>& gantt) {
    cout << "\nGantt Chart:\n";
    for (auto& entry : gantt) cout << "| " << entry.first << " ";
    cout << "|\n";
    for (auto& entry : gantt) cout << entry.second << "\t";
    cout << "\n";
}

void fcfs(vector<Process> processes) {
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrival < b.arrival;
    });

    vector<pair<string, int>> gantt;
    int time = 0;

    for (auto& p : processes) {
        if (time < p.arrival)
            time = p.arrival;
        p.start = time;
        time += p.burst;
        p.completion = time;
        p.turnaround = p.completion - p.arrival;
        p.waiting = p.turnaround - p.burst;
        gantt.push_back({ "P" + to_string(p.pid), p.start });
    }
    gantt.push_back({ "", time });

    printGanttChart(gantt);
    printTable(processes);
}

void sjf(vector<Process> processes) {
    int n = processes.size(), time = 0, completed = 0;
    vector<pair<string, int>> gantt;
    vector<bool> isDone(n, false);

    while (completed < n) {
        int idx = -1, minBT = 1e9;
        for (int i = 0; i < n; i++) {
            if (!isDone[i] && processes[i].arrival <= time && processes[i].burst < minBT) {
                minBT = processes[i].burst;
                idx = i;
            }
        }
        if (idx != -1) {
            processes[idx].start = time;
            time += processes[idx].burst;
            processes[idx].completion = time;
            processes[idx].turnaround = time - processes[idx].arrival;
            processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
            isDone[idx] = true;
            completed++;
            gantt.push_back({ "P" + to_string(processes[idx].pid), processes[idx].start });
        } else {
            time++;
        }
    }

    gantt.push_back({ "", time });
    printGanttChart(gantt);
    printTable(processes);
}

void srtf(vector<Process> processes) {
    int n = processes.size(), time = 0, completed = 0, last = -1;
    vector<pair<string, int>> gantt;

    for (auto& p : processes) p.remaining = p.burst;

    while (completed < n) {
        int idx = -1, minRT = 1e9;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= time && processes[i].remaining > 0 && processes[i].remaining < minRT) {
                minRT = processes[i].remaining;
                idx = i;
            }
        }
        if (idx != -1) {
            if (last != idx) gantt.push_back({ "P" + to_string(processes[idx].pid), time });
            if (processes[idx].start == -1) processes[idx].start = time;
            processes[idx].remaining--;
            time++;
            last = idx;
            if (processes[idx].remaining == 0) {
                processes[idx].completion = time;
                processes[idx].turnaround = time - processes[idx].arrival;
                processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
                completed++;
            }
        } else {
            time++;
        }
    }

    gantt.push_back({ "", time });
    printGanttChart(gantt);
    printTable(processes);
}

void roundRobin(vector<Process> processes, int quantum) {
    int n = processes.size(), time = 0, completed = 0;
    queue<int> q;
    vector<bool> inQueue(n, false);
    vector<pair<string, int>> gantt;

    for (auto& p : processes) p.remaining = p.burst;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= time && !inQueue[i] && processes[i].remaining > 0) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (!q.empty()) {
            int idx = q.front(); q.pop();
            gantt.push_back({ "P" + to_string(processes[idx].pid), time });

            if (processes[idx].start == -1)
                processes[idx].start = time;

            int exec = min(quantum, processes[idx].remaining);
            processes[idx].remaining -= exec;
            time += exec;

            for (int i = 0; i < n; i++) {
                if (processes[i].arrival <= time && !inQueue[i] && processes[i].remaining > 0) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }

            if (processes[idx].remaining > 0)
                q.push(idx);
            else {
                processes[idx].completion = time;
                processes[idx].turnaround = time - processes[idx].arrival;
                processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
                completed++;
            }
        } else {
            time++;
        }
    }

    gantt.push_back({ "", time });
    printGanttChart(gantt);
    printTable(processes);
}

int main() {
    int choice, n;
    cout << "CPU Scheduling Algorithms\n";
    cout << "1. FCFS\n2. SJF (Non-preemptive)\n3. SRTF (Preemptive)\n4. Round Robin\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        processes[i].pid = i + 1;
        cout << "Enter Arrival Time for P" << i + 1 << ": ";
        cin >> processes[i].arrival;
        cout << "Enter Burst Time for P" << i + 1 << ": ";
        cin >> processes[i].burst;
        processes[i].remaining = processes[i].burst;
    }

    if (choice == 1)
        fcfs(processes);
    else if (choice == 2)
        sjf(processes);
    else if (choice == 3)
        srtf(processes);
    else if (choice == 4) {
        int quantum;
        cout << "Enter Time Quantum: ";
        cin >> quantum;
        roundRobin(processes, quantum);
    } else
        cout << "Invalid choice.\n";

    return 0;
}
