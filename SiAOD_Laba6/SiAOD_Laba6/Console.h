#pragma once
#include <iostream>
#include <vector>

class Console
{
public:
	void start();
private:
	long long get_data() const;
	void push_vector(int count);
	long long computation(int count);
	void print(int result, int time) const;

	std::vector<long long> _machine_a;
	std::vector<long long> _machine_b;
	std::vector<long long> _machine_c;
	std::vector<long long> _remaining_time = { 0, 0, 0 };
};