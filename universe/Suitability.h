// -*- C++ -*-
#ifndef _Suitability_h_
#define _Suitability_h_

#include "Enums.h"
#include "TemporaryPtr.h"
#include "UniverseObject.h"

#include "../util/Export.h"

#include <set>
#include <map>
#include <string>

class Empire;
class Planet;

///< get a set of all the species from the given empire that can colonize this planet
FO_COMMON_API std::set<std::string> GetColonizerSpecies(Empire* empire, TemporaryPtr<const Planet> planet, bool all_species = true);

///< get the species, suitability pairs for all relevant species of the given empire and planet
FO_COMMON_API std::map<std::string, std::pair<PlanetEnvironment, float> > GetSuitabilitiesForSpecies(int empire_id, int planet_id,
                                                                                                     const std::set<std::string>& species_names);

///< choose the best suitable species from the given set
FO_COMMON_API std::string GetBestSuitable(const std::map<std::string, std::pair<PlanetEnvironment, float> >& suitabilities,
                                          int empire_id = INVALID_OBJECT_ID, int location_id = INVALID_OBJECT_ID);

#endif // _Suitability_h_
