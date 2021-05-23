#include<iostream> 
#include<stdio.h> 
#include<string>
#include<algorithm> 

using namespace std;

string pad_str(string x, int n) {

	int x_size = x.size();
	string z = x;

	for (int i = 0; i < n; i++)
	{
		z = "0" + z;
	}

	return z;
}

string add_zero(string x, int n) {

	string z = x;

	for (int i = 0; i < n; i++)
	{
		z = z + "0";
	}

	return z;
}

string remove_trailzero(string x) {

	int x_size = x.size();
	string z = x;

	for (int i = 0; i < x_size; i++)
	{
		if (x[i] == '0')
		{
			z = z.substr(1, z.size() - 1);
		}
		else {
			return z;
		}
	}

	return "";
}


string subtract(string x, string y) {

	//X should always be >= Y

	if (x.size() > y.size())
	{
		y = pad_str(y, x.size() - y.size());
	}


	if (y.size() > x.size())
	{
		x = pad_str(x, y.size() - x.size());
	}

	int borrow = 0, intermediate_diff = 0, temp_x = 0, temp_y = 0, remaining_sum = 0;
	int size_number = x.size();
	string diff = "";

	for (int i = 0; i < size_number; i++)
	{
		temp_x = x[size_number - 1 - i] - '0';
		temp_y = y[size_number - 1 - i] - '0';

		if (borrow == 0)
		{
			if (temp_x < temp_y) {
				borrow++;
				temp_x = temp_x + 10;
				intermediate_diff = temp_x - temp_y;
				diff = to_string(intermediate_diff) + diff;
			}
			else
			{
				intermediate_diff = temp_x - temp_y;
				diff = to_string(intermediate_diff) + diff;
			}
		}
		else
		{
			if ((temp_x-1) < temp_y)
			{
				//borrow++;
				temp_x = temp_x-1 + 10;
				intermediate_diff = temp_x - temp_y;
				diff = to_string(intermediate_diff) + diff;
			}
			else {
				borrow--;
				intermediate_diff = temp_x-1 - temp_y;
				diff = to_string(intermediate_diff) + diff;
			}
		}
		
	}
	return diff;
}


string add(string x, string y) {

	//cout << x << " " << y << endl;

	if (x.size() > y.size())
	{
		y = pad_str(y, x.size() - y.size());
	}


	if (y.size() > x.size())
	{
		x = pad_str(x, y.size() - x.size());
	}

	//cout << x << " " << y << endl;
	
	int carryover = 0, intermediate_sum = 0, temp_x = 0, temp_y = 0, remaining_sum = 0;
	int size_number = x.size();
	string sum = "";
	
	for (int i = 0; i < size_number; i++)
	{
		temp_x = x[size_number - 1 - i] - '0';
		temp_y = y[size_number - 1 - i] - '0';

		//cout << temp_x << " " << temp_y << endl;

		intermediate_sum = temp_x + temp_y + carryover;

		if (intermediate_sum > 9)
		{
			remaining_sum = intermediate_sum % 10;

			if (remaining_sum == 0)
			{
				carryover = intermediate_sum / 10;
			}
			else {
				carryover = (intermediate_sum - remaining_sum)/10;
			}
			
			
		}
		else {

			remaining_sum = intermediate_sum;
			carryover = 0;
		}

		sum = to_string(remaining_sum) + sum;
		
	}

	if (carryover > 0)
	{
		sum = to_string(carryover) + sum;
	}

	return sum;
}

string multiply(string x, string y) {

	int max_size = max(x.size(), y.size());
	//cout << max_size;
	//string breakpoint;
	//cout << max_size << endl;
	//cin >> breakpoint;

	if (x.size() > y.size())
	{
		y = pad_str(y, x.size() - y.size());
	}


	if (y.size() > x.size())
	{
		x = pad_str(x, y.size() - x.size());
	}

	//cout << "x and y are: " << x << " " << y << endl;

	int x_size = x.size();
	int y_size = y.size();

	if (max_size <= 2) {
		//cout << to_string(stoi(x)*stoi(y)) << endl;
		return to_string(stoi(x)*stoi(y));
	}

	string a = x.substr(0, max_size /2);
	string b = x.substr(max_size / 2, x_size-(max_size / 2));
	string c = y.substr(0, max_size / 2);
	string d = y.substr(max_size / 2, y_size - (max_size / 2));
	//cout << a << " " << b << " " << c << " " << d << endl;

	string first_term = multiply(a, c);
	//cout << "first term calculated" << endl;
	string second_term = multiply(b, d);
	//cout << "second term calculated" << endl;
	//cout << add(a, b) << endl;
	string third_term = multiply(add(a,b),add(c,d));
	//cout << "third term calculated" << endl;
	string fourth_term = subtract(subtract(third_term, first_term), second_term);
	string fifth_term = add_zero(remove_trailzero(first_term), b.size()*2);
	string sixth_term = add(fifth_term, second_term);
	string seventh_term = add_zero(remove_trailzero(fourth_term),b.size());
	string final_answer = add(sixth_term, seventh_term);
	//cout << first_term << " " << second_term << " " << third_term << " " << fourth_term << " " << fifth_term << " " << seventh_term << " " << final_answer << endl;
	return final_answer;
   
}

int main()
{
	string x = "3141592653589793238462643383279502884197169399375105820974944592";
	string y = "2718281828459045235360287471352662497757247093699959574966967627";
	//3141592653589793238462643383279502884197169399375105820974944592
	//2718281828459045235360287471352662497757247093699959574966967627
	//string z = multiply(x, y);

	cout << multiply(x,y);
	//cout << subtract("1610","1564");
	string pause;

	cin >> pause;

	return 0;

}