// Copyright AbraceTI Ltd.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\Projectile.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Actor.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Public\TimerManager.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Kismet\GameplayStatics.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\DamageType.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Engine\EngineTypes.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Components\SceneComponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	LaunchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
	LaunchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	
	//prevent start flying off, until we actually press the button to fire it.
	ProjectileMovement->bAutoActivate = false;

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ImpactBlast->bAutoActivate = false;

	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion Force"));
	//Bug Fix mini chalenge, if you dont atacch to a component, ExplosionForce spawn in default location on word, no error show in engine.
	ExplosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	//used to set OnHit method
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
}

void AProjectile::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	LaunchBlast->Deactivate();
	ImpactBlast->Activate();

	ExplosionForce->FireImpulse();

	SetRootComponent(ImpactBlast);
	CollisionMesh->DestroyComponent();

	UGameplayStatics::ApplyRadialDamage
	(
		this,
		ProjectileDamage,          // const UObject * WorldContextObject,  
		GetActorLocation(),        // float BaseDamage,
		ExplosionForce->Radius,    // const FVector & Origin, (for consistancy)
		UDamageType::StaticClass(),// float DamageRadius,
		TArray<AActor*>()		   // TSubclassOf < class UDamageType > DamageTypeClass,
							       // const TArray < AActor * > & IgnoreActors,
								   // AActor * DamageCauser,
								   // AController * InstigatedByController,
								   // bool bDoFullDamage,
								   // ECollisionChannel DamagePreventionChannel
	);


	/* How to use a delegate from the engine https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Delegates/index.html	 
	   1st seek the function and types, in this case SetTimer
	   2nd change the parameters of the function	
	*/

	FTimerHandle Timer; // first parameter in SetTimer

	GetWorld()->GetTimerManager().SetTimer( 
		Timer,                      // FTimerHandle & InOutHandle,
		this,                       // UserClass * InObj, (use this for reference this class)         		
		&AProjectile::OnTimerExpire,// typename FTimerDelegate::TUObjectMethodDelegate_Const< UserClass >::FMethodPtr InTimerMethod,
		DestroyDelay,               // float InRate,
		false                       // bool InbLoop,
					                // float InFirstDelay (not used)
	);
}


//simple delegate to use in the function SetTimer 
void AProjectile::OnTimerExpire()
{
	Destroy();
}


void AProjectile::LaunchProjectile(float Speed)
{
	
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();

}
