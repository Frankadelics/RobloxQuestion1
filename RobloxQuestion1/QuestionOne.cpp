//An answer to the question presented in the Roblox university test
#include <iostream>
#include <vector>
#include <random>
using namespace std;

//To iterate across my vector of stored trashbag weights
vector<float>::iterator it;

int efficientJanitor(vector<float>& weight)
{
	int numTrips = 0;
	float buffer = 0.0;
	//Your code starts here

	//One bag will always have one trip
	if (weight.size() == 1)
	{
		cout << "I made it here 1" << endl;
		return 1;
	}

	sort(weight.begin(), weight.end());
	for (it = weight.begin(); it != weight.end(); it++)
	{
		//If the bag is heavier than 2, no other combinations will work and it must be taken by itself
		if (*it >= 2)
		{
			cout << "I made it here 2" << endl;
			numTrips++;
		}
		else if (it == weight.end())
		{
			numTrips++;
			break;
		}
		//Add the current bag with the future bag, if they are less than 3 then they can be taken together, numTrips++
		else if (*it + *(it + 1) <= 3)
		{
			cout << "Iterator: " << *it << endl;
			numTrips++;
			it++;
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
	weightOfBags.push_back(1.01);
	weightOfBags.push_back(2.0);
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