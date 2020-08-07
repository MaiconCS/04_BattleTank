// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAimingcomponent.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Pawn.h"
#include "TankPawn.generated.h"//generetade is last include

class UTankBarrel;

UCLASS()
class BATTLETANK_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)

	void SetBarrelReference(UTankBarrel* BarrelToSet);



protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	


private:
	// Sets default values for this pawn's properties
	ATankPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000; //TODO find best starting value default 1000 m/s 

};
