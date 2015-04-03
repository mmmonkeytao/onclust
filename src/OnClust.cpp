#include "OnClust.h"

using namespace std;

/*
 * constructor and destructor
 *
 */
OnClust::OnClust(uint feaSize):
_feaSize(feaSize)
{
  _numClusters = 0;
  _h = 0.0;
  _c = 0.0;
  _datasize = 0;
}

OnClust::~OnClust()
{}

/*
 * Access Functions
 *
 */
uint OnClust::getDataSize(){
  return _datasize; 
}

void OnClust::incrementDataSize(){
  ++_datasize;
}

const OnClust::DataSet& OnClust::getData(){
  return _data;
}

const std::map<uint, int>& OnClust::getLabelList(){
  return _labels;
}

const std::map<uint, Vertex> OnClust::getGraph(){
  return _graph;
}

const Eigen::MatrixXd& OnClust::getSimilarityMat() {
  return _similarityMatrix;
}

