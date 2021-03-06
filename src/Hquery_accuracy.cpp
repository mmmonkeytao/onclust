#include "OnClust.h"

void OnClust::Hquery_accuracy()
{

  uint correct_counter = 0;
  
  for(auto &center: _centerList){

    int cLabel = _labels[center]; 
    
    for(auto &sat: _graph[center].getDomSatsList())
      if(_labels[sat] == cLabel)
	++correct_counter;
  }

  std::cout << "Hquery Accuracy is: " << (float)correct_counter / (float)_datasize
	    << std::endl;
  
}




