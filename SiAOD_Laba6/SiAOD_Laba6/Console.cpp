#include "Console.h"

void Console::start()
{
	long long count = get_data();

	push_vector(count);

	unsigned int start = clock();
	long long result = computation(count);	
	unsigned int stop = clock();
	
	print(result, stop - start);
}

long long Console::get_data() const
{
	long long data;
	std::cin >> data;
	return data;
}

void Console::push_vector(int count)
{
	for (long long i = 0; i < count; i++)
	{
		_machine_a.push_back(get_data());
		_machine_c.push_back(get_data());
		_machine_b.push_back(get_data());
	}
}

long long Console::computation(int count)
{
	long long result = 0;
	for (long long i = 0; i < count; i++)
	{
		if (_remaining_time[0] != 0 || _remaining_time[1] != 0 || _remaining_time[2] != 0)
		{
			long long A = _remaining_time[0] - _machine_a[i];
			long long B = _remaining_time[1] - _machine_b[i];
			long long C = _remaining_time[2] - _machine_c[i];

			if (A > B && B > C)
			{
				if (_remaining_time[0] >= _machine_a[i])
				{
					_remaining_time[0] -= _machine_a[i];
				}
				else
				{
					_machine_a[i] -= _remaining_time[0];

					_remaining_time[0] = 0;

					result += _machine_a[i];
					_remaining_time[1] += _machine_a[i];
					_remaining_time[2] += _machine_a[i];
				}
			}
			else if (B > A && A > C)
			{
				if (_remaining_time[1] >= _machine_b[i])
				{
					_remaining_time[1] -= _machine_b[i];
				}
				else
				{
					_machine_b[i] -= _remaining_time[1];

					_remaining_time[1] = 0;

					result += _machine_b[i];
					_remaining_time[0] += _machine_b[i];
					_remaining_time[2] += _machine_b[i];
				}
			}
			else if (C > B && B > A)
			{
				if (_remaining_time[2] >= _machine_c[i])
				{
					_remaining_time[2] -= _machine_c[i];
				}
				else
				{
					_machine_c[i] -= _remaining_time[2];
					_remaining_time[2] = 0;
					result += _machine_c[i];
					_remaining_time[1] += _machine_c[i];
					_remaining_time[0] += _machine_c[i];
				}
			}
		}
		else
		{
			if (_machine_a[i] < _machine_b[i] < _machine_c[i])
			{
				result += _machine_a[i];
				_remaining_time[1] += _machine_a[i];
				_remaining_time[2] += _machine_a[i];
			}
			else if (_machine_b[i] < _machine_a[i] < _machine_c[i])
			{
				result += _machine_b[i];
				_remaining_time[0] += _machine_b[i];
				_remaining_time[2] += _machine_b[i];
			}
			else if (_machine_c[i] < _machine_b[i] < _machine_a[i])
			{
				result += _machine_c[i];
				_remaining_time[1] += _machine_c[i];
				_remaining_time[0] += _machine_c[i];
			}
		}
	}
	return result;
}

void Console::print(int result, int time) const
{
	std::cout << "Результат: " << result << std::endl;
	std::cout << "Время: " << time << "мс" << std::endl;
}