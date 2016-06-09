#pragma once
#include <iostream>
using namespace std;

template<typename K, typename V, int N>
class KVList 
{
	K k[N];
	V v[N];
	int count;
	
public:
	KVList() : count(0) {}
	
	size_t size() const 
	{ 
		return count; 
	}
	
	const K& key(int i) const 
	{ 
		return k[i]; 
	}
	
	const V& value(int i) const 
	{ 
		return v[i]; 
	}
	
	KVList &add(const K& kk, const V& vv) 
	{
		if (count < N) 
		{
			k[count] = kk;
			v[count] = vv;
			count++;
		}
		
		return *this;
	}
	
	int find(const K& kk) const 
	{
		for (int i = 0; i < count; i++) 
		{
			if (kk == k[i]) 
				return i;
		}
		
		return 0;
	}
	
	KVList& replace(int i, const K& kk, const V& vv) 
	{
		if (i < count) 
		{
			k[i] = kk;
			v[i] = vv;
		}
		
		return *this;
	}
};