#include "PriorityQueue.hh"



bool PriorityQueue::isEmpty(){
  if (elem.begin()==elem.end())
    return true;
  else
    return false;
}
void PriorityQueue::push(std::vector<int> vec){
  elem.push_back(vec);
}
/*operacja push nie ustawia wektorów zgodnie z priorytetem, ponieważ operacja
pop i tak musi zawsze wybierać element o najmniejszym priorytecie z powodu
zminy priorytetów elemenów w trakcie*/
std::vector<int> PriorityQueue::pop(){
  if (this->isEmpty())
    throw std::runtime_error("Priority queue is empty");
  else {
    std::vector<int>* temp=&elem[0];
    for (unsigned int i=1;i<elem.size();++i) {
      if (elem[i][1]<(*temp)[1])
	temp=&elem[i];
    }
    std::swap(*temp,*(elem.end()-1));
    std::vector<int> help=*(elem.end()-1);
    elem.pop_back();
    return help;
    }
  //zamien element ostatni z elementem o najmniejszym priorytecie
  //poniewaz w std::vector mamy operacje wyciągnięcia ostatniego elementu
}
void PriorityQueue::decrease_priority(int number, int npriority) {
  auto it = std::find_if(elem.begin(),elem.end(),[number](const std::vector<int>& vec){
      return number==vec[0]; });
  if (it==elem.end())
    throw std::runtime_error("Can't find chosen edge");
  else 
    (*it)[1]=npriority;
}
