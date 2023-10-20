#include<fstream>
#include<iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

//针对进程调度模块的特点，设计进程控制块PCB的数据结构
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

// 使用multiset作为就绪队列
typedef multiset<PCB, ComparePriority> PCBQueue;

// 实现时间片轮转调度算法
void round_cal(PCBQueue& ready_queue, int quantum){
	//RR队列的初始化
	std::queue<PCB> RRQueue;
	while (!ready_queue.empty()) {
		RRQueue.push(*ready_queue.begin());
		ready_queue.erase(ready_queue.begin());
	}
	while (!RRQueue.empty()) {
		PCB process = RRQueue.front();
		RRQueue.pop();
		process.state = PCB::RUNNING;
		print_pcb_info(process);
		print_ready_queue_info(ready_queue);
		process.remaining_time -= quantum;
		if (process.remaining_time > 0) {
			RRQueue.push(process);
			process.state = PCB::READY;
		}
		else {
			process.state = PCB::FINISHED;
			std::cout << "Process " << process.pid << " finished.\n";
		}
	}
}

// 实现基于优先权的调度算法
void priority_cal(PCBQueue& ready_queue, int quantum) {
	//RR队列的初始化
	std::queue<PCB> PRIQueue;
	while (!ready_queue.empty()) {
		PRIQueue.push(*ready_queue.begin());
		ready_queue.erase(ready_queue.begin());
	}
	while (!PRIQueue.empty()) {
		
	}
}

// 从文件中读取进程信息、时间片长度和算法选择
int readInputFromFile(const std::string& filename, PCBQueue& ready_queue, int time_slice) {
	std::ifstream file(filename);
	int ALGOSEL = 0;
	if (file.is_open()) {
		file >> time_slice;
		file >> ALGOSEL;

		PCB process;
		while (file >> process.pid >> process.priority >> process.burst_time >> process.remaining_time) {
			process.state = PCB::State::READY;
			ready_queue.insert(process);
		}
		file.close();
	}
	else {
		std::cerr << "Failed to open file: " << filename << std::endl;
	}
	return ALGOSEL;
}

int main() {
	ifstream ifs;

	// 选择算法：1-时间片轮转调度算法；2-基于优先权调度算法
	int ALGOSEL;

	// 初始化就绪队列
	PCBQueue ready_queue;

	// 初始化时间片长度
	int time_slice;

	// 从文件中读取输入数据
	ALGOSEL = readInputFromFile("input.txt", ready_queue, time_slice);

	switch (ALGOSEL)
	{
	case 0:break;
	case 1:priority_cal(ready_queue, time_slice); break;
	case 2:round_cal(ready_queue, time_slice); break;
	}

	return 0;
}

