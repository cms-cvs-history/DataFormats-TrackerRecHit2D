#ifndef SiPixelRecHit_H
#define SiPixelRecHit_H

#include "DataFormats/TrackerRecHit2D/interface/BaseSiStripRecHit2DLocalPos.h"
#include "DataFormats/SiStripCluster/interface/SiStripCluster.h"

class SiPixelRecHit : public  BaseSiStripRecHit2DLocalPos {
public:

  SiPixelRecHit(): BaseSiStripRecHit2DLocalPos () {}

  ~SiPixelRecHit() {}

  SiPixelRecHit( const LocalPoint&, const LocalError&,
			 const DetId&, 
			   const std::vector<const SiStripCluster*>& cluster);  

  virtual SiPixelRecHit * clone() const {return new SiPixelRecHit( * this); }

  const std::vector<const SiStripCluster*>& cluster() const { return cluster_;}
  
private:
  std::vector<const SiStripCluster*>   cluster_;

};

// Comparison operators
inline bool operator<( const SiPixelRecHit& one, const SiPixelRecHit& other) {
  if ( one.geographicalId() < other.geographicalId() ) {
    return true;
  } else {
    return false;
  }
}

#endif
