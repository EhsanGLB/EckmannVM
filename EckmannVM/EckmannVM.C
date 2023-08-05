/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     | Version:     4.1
    \\  /    A nd           | Web:         http://www.foam-extend.org
     \\/     M anipulation  | For copyright notice see file Copyright
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Author
    Ehsan Golab, SUT. All rights reserved.

\*---------------------------------------------------------------------------*/

#include "EckmannVM.H"
#include "addToRunTimeSelectionTable.H"
#include "surfaceFields.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace viscosityModels
{
    defineTypeNameAndDebug(EckmannVM, 0);

    addToRunTimeSelectionTable
    (
        viscosityModel,
        EckmannVM,
        dictionary
    );
}
}


// * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::viscosityModels::EckmannVM::calcNu() const
{
    dimensionedScalar dimMu("dimMu", dimMass/dimLength/dimTime, 1.0);
    dimensionedScalar Tc("Tc", dimTemperature, 273.15);
    dimensionedScalar dimLambda("dimLambda", dimless/dimTime, 1);

    return (1e-3*dimMu/rho_) * exp((lambda_/(dimLambda+strainRate())) + etha_*hct_) * ( alpha_ + phi_/(1+exp(beta_*(T_-Tc-kesi_))) );
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::viscosityModels::EckmannVM::EckmannVM
(
    const word& name,
    const dictionary& viscosityProperties,
    const volVectorField& U,
    const surfaceScalarField& phi
)
:
    viscosityModel(name, viscosityProperties, U, phi),
    EckmannVMCoeffs_(viscosityProperties.subDict(typeName + "Coeffs")),
    lambda_(EckmannVMCoeffs_.lookup("lambda")),
    etha_(EckmannVMCoeffs_.lookup("etha")),
    alpha_(EckmannVMCoeffs_.lookup("alpha")),
    phi_(EckmannVMCoeffs_.lookup("phi")),
    beta_(EckmannVMCoeffs_.lookup("beta")),
    kesi_(EckmannVMCoeffs_.lookup("kesi")),
    rho_(EckmannVMCoeffs_.lookup("rho")),
    hct_(EckmannVMCoeffs_.lookup("hct")),
    T_(EckmannVMCoeffs_.lookup("T")),
    nu_
    (
        IOobject
        (
            name,
            U_.time().timeName(),
            U_.db(),
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        calcNu()
    )
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

bool Foam::viscosityModels::EckmannVM::read
(
    const dictionary& viscosityProperties
)
{
    viscosityModel::read(viscosityProperties);

    EckmannVMCoeffs_ = viscosityProperties.subDict(typeName + "Coeffs");

    EckmannVMCoeffs_.lookup("lambda") >> lambda_;
    EckmannVMCoeffs_.lookup("etha") >> etha_;
    EckmannVMCoeffs_.lookup("alpha") >> alpha_;
    EckmannVMCoeffs_.lookup("phi") >> phi_;
    EckmannVMCoeffs_.lookup("beta") >> beta_;
    EckmannVMCoeffs_.lookup("kesi") >> kesi_;
    EckmannVMCoeffs_.lookup("rho") >> rho_;
    EckmannVMCoeffs_.lookup("hct") >> hct_;
    EckmannVMCoeffs_.lookup("T") >> T_;

    return true;
}


// ************************************************************************* //
