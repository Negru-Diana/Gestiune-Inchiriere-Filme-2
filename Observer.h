#pragma once
#include<vector>
using namespace std;



class Observer
{
public:
	virtual void update() = 0;
};



class Observable
{
	vector<Observer*> filme_cos;

protected:

	void modificari()
	{
		for (auto f : filme_cos)
		{
			f->update();
		}
	}

public:

	void addObserver(Observer* o)
	{
		filme_cos.push_back(o);
	}

	void removeObserver(Observer* o)
	{
		filme_cos.erase(std::remove(filme_cos.begin(), filme_cos.end(), o), filme_cos.end());
	}
};