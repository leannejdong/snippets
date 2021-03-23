#include <iostream>
#include <vector>
#include <thread>

// void printThreadIDs(int &val1, int val2){
// 	std::cout << "Thread ID: " << std::this_thread::get_id() << " Val 1: " << val1++ << " val2: " << val2++ << std::endl;
// }

int main(){
	int val1 = 9;
	int val2 = 9;
	
	std::vector <std::thread> threads;
	
	for(int i = 0; i < 4; ++i){
		std::thread t([&](int a){
            std::cout << "Thread ID: " << std::this_thread::get_id() << " Val 1: " << val1++ << " val2: " << val2*a << "\n";
        },10);
		threads.push_back(std::move(t)); // Instead of copying, move t into the vector (Less expensive)
	}

	// Now wait for the threads to finish,
	// We need to wait otherwise main thread might reach an end before the multiple threads finish their work
	for(auto &t: threads){
		t.join();
	}

	std::cout << "Final value of variable val1: " << val1 << " val2: " << val2 << std::endl;
}
// https://godbolt.org/z/6h8n395Kj
