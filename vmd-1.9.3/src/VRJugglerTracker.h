/***************************************************************************
 *cr
 *cr            (C) Copyright 1995-2016 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 *cr VRJuggler patches contributed by Martijn Kragtwijk: m.kragtwijk@rug.nl
 *cr
 ***************************************************************************/

/***************************************************************************
 * RCS INFORMATION:
 *
 *      $RCSfile: VRJugglerTracker.h,v $
 *      $Author: johns $        $Locker:  $             $State: Exp $
 *      $Revision: 1.3 $       $Date: 2016/11/28 03:05:06 $
 *
 ***************************************************************************
 * DESCRIPTION:
 * a VRJuggler specific tracker device for VMD
 ***************************************************************************/
class VRJugglerScene;

/// VMDTracker subclass that interfaces to the VRJuggler wand
class VRJugglerTracker : public VMDTracker {
 public:
  VRJugglerTracker(VRJugglerScene* scene);
  virtual VMDTracker *clone() { return new VRJugglerTracker(mScene); }
  const char *device_name() const { return "vrjugglertracker"; }
  virtual void update();
  inline virtual int alive() { return 1; }

 protected:
  virtual int do_start(const SensorConfig *);
  VRJugglerScene* mScene;
};

