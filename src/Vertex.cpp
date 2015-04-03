#include "Vertex.h"

using namespace std;

/////////////////////////// CONSTRUCTOR //////////////////////////////////////////
Vertex:: Vertex()
{
  _domCenter = -1;
  _domSatsList = std::set<uint>();
  _degree = 0;
  _attrSum = 0.0;
  setDomCenterNull();
  _adjPlanetsList = std::set<uint>();
  _adjCentersList = std::set<uint>();
}

Vertex:: Vertex(uint ID)
{
  _domCenter = -1;
  _domSatsList = std::set<uint>();
  _degree = 0;
  _attrSum = 0.0;
  setDomCenterNull();
  setID(ID);
  setType(Vertex::STAR);
  _adjPlanetsList = std::set<uint>();
  _adjCentersList = std::set<uint>();
}


/////////////////////////// DESTRUCTOR /////////////////////////////////////////
Vertex:: ~Vertex() 
{}

/////////////////////////// PUBLIC FUNCTIONS ////////////////////////////////////

// Accessors and mutatorsb

// ID
uint Vertex::getID() const
{
  return _id;
}

void Vertex::setID(uint uID) 
{
  _id = uID;
}

// Type
Vertex::Type Vertex::getType() const
{
  return _type;
}

void Vertex::setType(Type sType)
{
  _type = sType;
}

// Degree
uint Vertex::getDegree() const
{
  return _degree;
}

void Vertex::setDegree(uint uDegree)
{
  _degree = uDegree;
}

void Vertex::incrementDegree()
{
  ++_degree;
}

void Vertex::decrementDegree()
{
  --_degree;
}


//********** RELATED TO OPTIMIZED VERSIONS ********

// Related to domcenter.

uint Vertex::getDomCenter()
{
  return _domCenter;
}

void Vertex::setDomCenter(uint domCenterIndex)
{
  _domCenter = domCenterIndex;
}

void Vertex::setDomCenterNull()
{
  _domCenter = -1;
}

bool Vertex::isDomCenterNull()
{
  return (_domCenter == -1) ? true : false;
}

// Related to domSatsList

// Insert a satellite ID into the dominant satellite list.
void Vertex::insertDomSats(uint domSatIDToInsert)
{
  _domSatsList.insert(domSatIDToInsert);
}

// Delete a satellite ID into the dominant satellite list.
void Vertex::deleteDomSats(uint domSatIDToDelete)
{
  _domSatsList.erase(domSatIDToDelete);
}

// Clear the dominant centers list.
void Vertex::clearDomSatsList()
{
  _domSatsList.clear();
}

// Is dom centers list empty?
bool Vertex::isDomSatsListEmpty()
{
  return _domSatsList.empty();
}

// Output reference to the dom centers list.
set<uint>& Vertex::getDomSatsList()
{
  return _domSatsList;
}

// Obtain the whole dom centers list.
set<uint> Vertex::getCopyOfDomSatsList()
{
  return _domSatsList;
}

const set<uint>& Vertex::getConstDomSatsList() const
{
  return _domSatsList;
}

void Vertex::setAttr(double attr) {
  _attraction = attr;
}

double Vertex::getAttr() {
  return _attraction;
}

void Vertex::setAttrSum(double attr) {
  _attrSum = attr;
}

void Vertex::addAttrSum(double attr) {
  _attrSum += attr;
}

void Vertex::minusAttrSum(double attr){
  _attrSum -= attr;
}

double Vertex::getAttrSum() {
  return _attrSum;
}

// *********************
// Adjacent Vertices List
// *********************

// Output reference to the list.
const set<uint>& Vertex::getAdjPlanetsList() const
{
  return _adjPlanetsList;
}

// Obtain the whole list.
set<uint> Vertex::getCopyOfAdjPlanetsList() const
{
  return _adjPlanetsList;
}

// Insert a vertex into the adjacency list.
void Vertex::insertAdjPlanet(uint adjPlanetIDToInsert)
{
  _adjPlanetsList.insert(adjPlanetIDToInsert);
}

// Delete a vertex from the adjacency list.
void Vertex::deleteAdjPlanet(uint adjPlanetIDToDelete)
{
  _adjPlanetsList.erase(adjPlanetIDToDelete);
}

// *********************
// Adjacent Centers List
// *********************
// Output reference
set<uint>& Vertex::getAdjCentersList()
{
  return _adjCentersList;
}

// Output whole list
set <uint> Vertex::getCopyOfAdjCentersList()
{
  return _adjCentersList;
}

// Insert a vertex into the adjacency list.
void Vertex::insertAdjCenter(uint adjCenterIDToInsert)
{
  _adjCentersList.insert(adjCenterIDToInsert);
}

// Delete a vertex from the adjacency list.
void Vertex::deleteAdjCenter(uint adjCenterIDToDelete)
{
  _adjCentersList.erase(adjCenterIDToDelete);
}

// Is adjacent centers list empty?
bool Vertex::isAdjCentersListEmpty()
{
  return _adjCentersList.empty();
}

void Vertex::clearCentersList()
{
  _adjCentersList.clear();
}

// Boolean status to indicate presence in the queue.
bool Vertex::getInQStatus() 
{
  return _inQ;
}

void Vertex::setInQStatus(bool bInQStatus)
{
  _inQ = bInQStatus;
}

int Vertex::getClustSize() {

  if(_type == Vertex::CENTER)
    return _degree + 1;
  else{
    std::cerr << "This is a Stars, please ask the center!\n";
    return -1;
  }
}

// Printing a vector
void Vertex::print()
{

  std::cout<< "PlanetID: " << _id << " " << std::endl;
  std::cout<< "PlanetType: " << _type << " ";
  std::cout<< "Degree: " << _degree << std::endl;
  std::cout<< "DomCenter: " << _domCenter << std::endl;
         
  std::cout << "domSatsList: ";
  copy(_domSatsList.begin(), _domSatsList.end(), ostream_iterator <uint> (cout, " "));
  std::cout << std::endl;
    
}

