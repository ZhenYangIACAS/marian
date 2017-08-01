#pragma once
#include <vector>
#include "sentences.h"
#include "base_matrix.h"

namespace amunmt {

class BeamSize
{
  struct SentenceHolder
  {
    EncParamsPtr encParams;
    size_t ind;
  };

public:
  BeamSize();

  virtual void Init(EncParamsPtr encParams);

  void Set(uint val);

  size_t size() const
  { return sizes_.size(); }

  uint GetTotal() const;

  void Decr(size_t ind);

  uint Get(size_t ind) const
  { return sizes_.at(ind); }

  SentencePtr GetSentence(size_t ind) const;

  virtual std::string Debug(size_t verbosity = 1) const;

protected:
  std::vector<uint> sizes_;
  //std::vector<SentenceHolder> sentences_;
  std::vector<SentencePtr> sentences_;

  uint total_;

};

}

