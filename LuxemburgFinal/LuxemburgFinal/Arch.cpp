#include "Arch.h"

Arch::Arch(int from, int to, double length) : m_from(from), m_to(to), m_cost(length)
{
	//empty
}

int Arch::GetFrom()
{
	return m_from;
}

int Arch::GetTo()
{
	return m_to;
}

double Arch::GetCost()
{
	return m_cost;
}

void Arch::SetFrom(int x)
{
	m_from = x;
}

void Arch::SetTo(int y)
{
	m_to = y;
}

void Arch::SetCost(int val)
{
	m_cost = val;
}
