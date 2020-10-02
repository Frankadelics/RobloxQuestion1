//An answer to the question presented in the Roblox university test
#include <iostream>
#include <vector>
#include <random>
using namespace std;

//To iterate across my vector of stored trashbag weights
vector<float>::iterator it1;
vector<float>::iterator it2;

int efficientJanitor(vector<float>& weight)
{
	int numTrips = 0;
	int saved = 0;
	bool changed = false;
	//Your code starts here
	
	if (weight.size() == 1)
	{
		return 1;
	}
	sort(weight.begin(), weight.end());
	for (int i = 0; i < weight.size(); i++)
	{
		if (weight[i] != -1)
		{
			if (weight[i] >= 2)
			{
				numTrips++;
				weight[i] = -1;
			}

			else
			{
				for (int j = i + 1; j < weight.size(); j++)
				{
					float sum = weight[i] + weight[j];
					cout << "Sum: " << sum << " i: " << i << " j: " << j << endl;
					if (sum <= 3 && weight[j] != -1)
					{
						saved = j;
						changed = true;
						cout << "Saved: " << j << endl;
					}
				}
				weight[i] = -1;
				if (changed)
				{
					weight[saved] = -1;
					changed = false;
				}
				numTrips++;
			}
		}
	}
	

	//Your code ends here
	return numTrips;
}

int main()
{
	

	vector<float> weightOfBags;
	weightOfBags.push_back(1.01);
	weightOfBags.push_back(1.01);
	weightOfBags.push_back(1.99);
	weightOfBags.push_back(1.99);

	//weightOfBags.push_back(1.01);
	//weightOfBags.push_back(1.01);
	int numTrips = efficientJanitor(weightOfBags);
	cout << "You will need to do " << numTrips << " trips Mr. Janitor." << endl;

	sort(weightOfBags.begin(), weightOfBags.end());

	for (int i = 0; i < weightOfBags.size(); i++)
	{
		cout << weightOfBags[i] << endl;
	}
}