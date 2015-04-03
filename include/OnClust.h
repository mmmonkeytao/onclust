#ifndef OnClust_H
#define OnClust_H

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <set>

#include <cmath>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <queue>

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <stdexcept>

#include "Vertex.h"

using namespace Eigen;

class OnClust
{
public:

  typedef std::vector<VectorXd> DataSet;
    
  // constructor
  OnClust(uint feaSize);
    
  // Destructor
  virtual ~OnClust();    

  // access functions
  uint getDataSize();
  void incrementDataSize();    
  const DataSet& getData();
  int getLabel(uint id){ return _labels[id]; };
  const std::map<uint, int>& getLabelList();
  const std::map<uint, Vertex> getGraph();
  const Eigen::MatrixXd& getSimilarityMat();

  // I/O
  void exportClusterInfo(const char* save_dir, uint threshold);
  void exportClustDot(char const*filename) const;
    
  // insert data
  /*
   * vec: input data vector
   * id : data ID
   * label: label of data, -1 if unlabelled
   * iter: iteration number
   * select_threshold: p(0)
   */
  bool EBC(Eigen::VectorXd vec, uint id, int label, uint iter);

  // assign labels to query when new insertion turns to be
  // a center
  void assignlabel(uint id, int label){ _labels[id] = label; }

  /*
   * vec: input data vector
   * id : data ID
   * label: label of data, -1 if unlabelled
   * iter: iteration number
   * select_threshold: 
   */
  void OSC(Eigen::VectorXd vec, uint id, int label, uint iter, double select_threshold);

  // cluster evaluation
  void V_measure(double beta, bool message);
  void Hquery_accuracy();
    
  /** OSC */
  // osc functions
  void oscInsert(uint, std::list<uint>&);
  void oscUpdate(uint);

  // helper functions
  uint vertexIDMaxDeg(std::set<uint> const&) const;

  //Eigen::VectorXi hquery;

  
protected:

  virtual double loaded_computeSimilarity(uint id1, uint id2);
  virtual double computeSimilarity(uint id1, uint id2);
    
private:

  typedef Eigen::MatrixXd MatrixType;

  uint _feaSize;
  DataSet _data;
  int _datasize;
  
  std::map<uint, uint> _dataIDs; // a map from iter to id
  MatrixType _similarityMatrix;
  std::set<uint> _centerList;
        
  std::map<uint, Vertex> _graph;     
  std::map<uint, int> _labels;
  std::map<int, uint> _labelist;

  uint _numClusters;
  double _h, _c;

  const double _min_cluster_size_wanted = 25.0;
  const double _clust_size_eps = 0.0002;
  const double _threshold_eps = 0.0002;
  const double select_threshold = 0.9;
  
  // priority Q
  std::priority_queue<Vertex> _priorityQ;
    
};
  
#endif
