#include<fstream>
#include<iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

//��Խ��̵���ģ����ص㣬��ƽ��̿��ƿ�PCB�����ݽṹ
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

// ʹ��multiset��Ϊ��������
typedef multiset<PCB, ComparePriority> PCBQueue;

// ʵ��ʱ��Ƭ��ת�����㷨
void round_cal(PCBQueue& ready_queue, int quantum){
	//RR���еĳ�ʼ��
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

// ʵ�ֻ�������Ȩ�ĵ����㷨
void priority_cal(PCBQueue& ready_queue, int quantum) {
	//RR���еĳ�ʼ��
	std::queue<PCB> PRIQueue;
	while (!ready_queue.empty()) {
		PRIQueue.push(*ready_queue.begin());
		ready_queue.erase(ready_queue.begin());
	}
	while (!PRIQueue.empty()) {
		
	}
}

// ���ļ��ж�ȡ������Ϣ��ʱ��Ƭ���Ⱥ��㷨ѡ��
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

	// ѡ���㷨��1-ʱ��Ƭ��ת�����㷨��2-��������Ȩ�����㷨
	int ALGOSEL;

	// ��ʼ����������
	PCBQueue ready_queue;

	// ��ʼ��ʱ��Ƭ����
	int time_slice;

	// ���ļ��ж�ȡ��������
	ALGOSEL = readInputFromFile("input.txt", ready_queue, time_slice);

	switch (ALGOSEL)
	{
	case 0:break;
	case 1:priority_cal(ready_queue, time_slice); break;
	case 2:round_cal(ready_queue, time_slice); break;
	}

	return 0;
}

