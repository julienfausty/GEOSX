/*
 * ------------------------------------------------------------------------------------------------------------
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Copyright (c) 2018-2020 Lawrence Livermore National Security LLC
 * Copyright (c) 2018-2020 The Board of Trustees of the Leland Stanford Junior University
 * Copyright (c) 2018-2020 TotalEnergies
 * Copyright (c) 2019-     GEOSX Contributors
 * All rights reserved
 *
 * See top level LICENSE, COPYRIGHT, CONTRIBUTORS, NOTICE, and ACKNOWLEDGEMENTS files for details.
 * ------------------------------------------------------------------------------------------------------------
 */

/**
 * @file ParallelPlatesPermeability.cpp
 */

#include "ParallelPlatesPermeability.hpp"

#include "constitutive/permeability/PermeabilityFields.hpp"

namespace geosx
{

using namespace dataRepository;

namespace constitutive
{


ParallelPlatesPermeability::ParallelPlatesPermeability( string const & name, Group * const parent ):
  PermeabilityBase( name, parent )
{
  registerField( fields::permeability::dPerm_dDispJump{}, &m_dPerm_dDispJump );
}

std::unique_ptr< ConstitutiveBase >
ParallelPlatesPermeability::deliverClone( string const & name,
                                          Group * const parent ) const
{
  return PermeabilityBase::deliverClone( name, parent );
}

void ParallelPlatesPermeability::allocateConstitutiveData( dataRepository::Group & parent,
                                                           localIndex const numConstitutivePointsPerParentIndex )
{
  // NOTE: enforcing 1 quadrature point
  m_dPerm_dDispJump.resize( 0, 1, 3, 3 );

  PermeabilityBase::allocateConstitutiveData( parent, numConstitutivePointsPerParentIndex );
}


REGISTER_CATALOG_ENTRY( ConstitutiveBase, ParallelPlatesPermeability, string const &, Group * const )

}
} /* namespace geosx */
