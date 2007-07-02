#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHit.h"

SiPixelRecHit::SiPixelRecHit( const LocalPoint& pos, const LocalError& err,
			      const DetId& id,
			      edm::Ref< edm::DetSetVector<SiPixelCluster>, SiPixelCluster> const&  cluster): 
  BaseSiTrackerRecHit2DLocalPos(pos,err,id),
  cluster_(cluster) 

{
}

bool SiPixelRecHit::sharesInput( const TrackingRecHit* other, 
				 SharedInputType what) const
{
  if (trackerId() != other->geographicalId()) return false;
  if(! other->isValid()) return false;

  const SiPixelRecHit* otherCast = static_cast<const SiPixelRecHit*>(other);

  return cluster_ == otherCast->cluster();
}
