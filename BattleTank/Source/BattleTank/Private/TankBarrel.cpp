// Copyright AbraceTI Ltd.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankBarrel.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\Math\UnrealMathUtility.h"

void UTankBarrel::Elevated(float RelativeSpeed)
{
	// TODO move the barrel the right amount this frame	
	// TODO givem a max elevation speed and the frame time


	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;

	/* how works>> if barrel is a little under 40 degrees by default (RelativeRotation), 
	and  add (ElevationChange), this make the result above of 40, need clamp	*/
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	//no need to use clamp angle, make it simple ??.
	auto ElevationClamp = FMath::Clamp<float>(RawNewElevation, MinimunElevationDegrees, MaximumElevationDegrees);

	SetRelativeRotation(FRotator(ElevationClamp, 0, 0));

	
	



}