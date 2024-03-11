#pragma once
template <typename T>
class Box
{
private:
	T data;
public:
	void setData(T data)
	{
		this->data = data;
	}
	T getData()
	{
		return this->data;
	}

};