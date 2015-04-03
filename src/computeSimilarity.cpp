#include "OnClust.h"
#include <sstream>

double OnClust::computeSimilarity(uint id1, uint id2)
{
  return (_data[id1] - _data[id2]).cwiseAbs().sum();
}
