// Copyright AbraceTI Ltd.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankPawn.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\Math\UnrealMathUtility.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Engine\World.h"





float ATankPawn::GetHealthPercent() const
{
	return (float)CurrentlyHealth / (float)StartingHealth;
}

// Sets default values
ATankPawn::ATankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	
	//UE_LOG(LogTemp, Warning, TEXT("%s PREFIX: Tank C++ Construct"), *TankName)
}

void ATankPawn::BeginPlay()
{
	Super::BeginPlay(); // Needed for BP_BeginPlay to run

	//set the value at right time in execution, no rewrite the same 100 in StartingHealth;
	CurrentlyHealth = StartingHealth;
}

float ATankPawn::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	//Simplifies the damage sistem converting all damage to int with RoundTo.
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);

	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentlyHealth);

	CurrentlyHealth -= DamageToApply;

	if (CurrentlyHealth <= 0 ) 
	{	
		//Use of Delegate
		OnDeath.Broadcast();
		
	}
	//UE_LOG(LogTemp, Warning, TEXT(" DamageAmount : %f, DamageToApply : %i  "), DamageAmount, DamageToApply);


	return DamageAmount;
	   	 
}





