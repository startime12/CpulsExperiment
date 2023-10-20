#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

// 1. 设计进程控制块PCB的数据结构；
struct PCB {
    int pid;  // 进程标识符
    int priority;  // 优先级
    int burst_time;  // 所需CPU时间
    int remaining_time;  // 剩余CPU时间

    enum State {
        RUNNING,
        READY,
        FINISHED
    };

    State state;  // 进程状态
};

// 自定义比较函数
struct ComparePriority {
    bool operator()(const PCB& p1, const PCB& p2) const {
        // 较高优先级的进程在队列前面
        return p1.priority > p2.priority;
    }
};

// 使用multiset作为就绪队列
typedef std::multiset<PCB, ComparePriority> PCBQueue;

// 打印PCB信息函数
void print_pcb_info(const PCB& process) {
    std::cout << "Process ID: " << process.pid << ","
        << "Priority: " << process.priority << ","
        << "Burst Time: " << process.burst_time << ","
        << "Remaining Time: " << process.remaining_time << ","
        << "State: " << (process.state == PCB::RUNNING ? "RUNNING" : (process.state == PCB::READY ? "READY" : "FINISHED")) << "\n";
}

// 打印就绪队列信息函数
void print_ready_queue_info(const PCBQueue& ready_queue) {
    for (const PCB& process : ready_queue) {
        print_pcb_info(process);
    }
}

// 3. 实现时间片轮转调度算法；
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

// 4. 实现基于优先权调度算法；
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

    // 创建进程
    PCB process1 = { 1, 3, 10, 10, PCB::READY };
    PCB process2 = { 2, 1, 5, 5, PCB::READY };
    PCB process3 = { 3, 2, 7, 7, PCB::READY };
    PCB process4 = { 4, 4, 8, 8, PCB::READY };

    // 将进程添加到就绪队列
    ready_queue.insert(process1);
    ready_queue.insert(process2);
    ready_queue.insert(process3);
    ready_queue.insert(process4);

    // 执行优先级调度
    priority_scheduler(ready_queue, 1);

    return 0;
}