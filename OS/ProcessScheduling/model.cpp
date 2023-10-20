#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

// 1. ��ƽ��̿��ƿ�PCB�����ݽṹ��
struct PCB {
    int pid;  // ���̱�ʶ��
    int priority;  // ���ȼ�
    int burst_time;  // ����CPUʱ��
    int remaining_time;  // ʣ��CPUʱ��

    enum State {
        RUNNING,
        READY,
        FINISHED
    };

    State state;  // ����״̬
};

// �Զ���ȽϺ���
struct ComparePriority {
    bool operator()(const PCB& p1, const PCB& p2) const {
        // �ϸ����ȼ��Ľ����ڶ���ǰ��
        return p1.priority > p2.priority;
    }
};

// ʹ��multiset��Ϊ��������
typedef std::multiset<PCB, ComparePriority> PCBQueue;

// ��ӡPCB��Ϣ����
void print_pcb_info(const PCB& process) {
    std::cout << "Process ID: " << process.pid << ","
        << "Priority: " << process.priority << ","
        << "Burst Time: " << process.burst_time << ","
        << "Remaining Time: " << process.remaining_time << ","
        << "State: " << (process.state == PCB::RUNNING ? "RUNNING" : (process.state == PCB::READY ? "READY" : "FINISHED")) << "\n";
}

// ��ӡ����������Ϣ����
void print_ready_queue_info(const PCBQueue& ready_queue) {
    for (const PCB& process : ready_queue) {
        print_pcb_info(process);
    }
}

// 3. ʵ��ʱ��Ƭ��ת�����㷨��
void round_robin_scheduler(PCBQueue& ready_queue, int quantum) {
    std::queue<PCB> rr_queue;

    while (!rr_queue.empty()) {
        PCB current_process = rr_queue.front();
        rr_queue.pop();
        current_process.state = PCB::RUNNING;
        print_pcb_info(current_process);
        print_ready_queue_info(ready_queue);
        if (current_process.remaining_time <= quantum) {
            std::cout << "Process " << current_process.pid << " finished.\n";
            current_process.state = PCB::FINISHED;
        }
        else {
            current_process.remaining_time -= quantum;
            rr_queue.push(current_process);
            current_process.state = PCB::READY;
        }
    }
}

// 4. ʵ�ֻ�������Ȩ�����㷨��
void priority_scheduler(PCBQueue& ready_queue, int quantum) {
    while (!ready_queue.empty()) {
        PCB current_process = *ready_queue.begin();
        ready_queue.erase(ready_queue.begin());
        current_process.state = PCB::RUNNING;
        print_pcb_info(current_process);
        print_ready_queue_info(ready_queue);
        current_process.remaining_time -= quantum;
        if (current_process.remaining_time > 0) {
            ready_queue.insert(current_process);
            current_process.state = PCB::READY;
        }
        else {
            current_process.state = PCB::FINISHED;
        }
    }
}

int main() {
    PCBQueue ready_queue;

    // ��������
    PCB process1 = { 1, 3, 10, 10, PCB::READY };
    PCB process2 = { 2, 1, 5, 5, PCB::READY };
    PCB process3 = { 3, 2, 7, 7, PCB::READY };
    PCB process4 = { 4, 4, 8, 8, PCB::READY };

    // ��������ӵ���������
    ready_queue.insert(process1);
    ready_queue.insert(process2);
    ready_queue.insert(process3);
    ready_queue.insert(process4);

    // ִ�����ȼ�����
    priority_scheduler(ready_queue, 1);

    return 0;
}